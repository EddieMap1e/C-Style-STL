## string

目前string拥有 4 个全局函数  2 个成员变量 24 个成员函数

> **string的声明**
>
> ```c++
> string str={""};
> ```
>
> 声明时候必须作出**定义**,大括号初始化的内容无意义,将会被init成员函数覆盖
>
> **定义**可以是使用string_init初始化或者赋值string**右值**对象 不要尝试直接赋值string对象 请使用copy成员函数
>
> **成员函数的使用**
>
> 第一个参数均为对象本身
>
> ```c++
> str.show(&str);
> ```



> **[global] substr(char* s,int offset,int length)**		$O(n)$
>
> C风格的获取子串
>
> + param s 需要截取的源字符串
> + param offset 子串的起始位置
> + param length 子串的长度
> + return char* 子串的右值指针 如果length大于可获取子串长度 返回到结尾 如果偏移值和长度有误 返回空字符串



> **[global] KMP_match(char* s,char* p,int begin)**		$O(m+n)$
>
> kmp字符串匹配
>
> + param s 待匹配的字符串
> + param p 模板串
> + param begin 从哪个位置开始匹配
> + return int 如果匹配成功 返回第一个匹配到的索引起点 否则返回-1



>**[global] string_init(string* self,const char* s)**
>
>string对象的构造函数
>
>+ param self 需要初始化的string
>+ param s 初始化的字符串
>+ return void
>+ remarks 任何时候定义string后必须对其使用该全局函数进行初始化 不要重复对同一个对象使用



>**[global] string_s_init(string* self,string* s)**
>
>string对象的构造函数
>
>+ param self 需要初始化的string
>+ param s 初始化的字符串
>+ return void
>+ remarks 禁止使用未初始化的string对象进行初始化



> **.str**
>
> string对象的字符数组
>
> + type char* C字符数组
> + remarks 可直接访问数组 非常量字符串



> **.length**
>
> string对象的长度
>
> + type unsigned int 长度大小



> **.destroy(string* self)**
>
> string对象的析构函数
>
> + self 对象自身的地址
> + return void
> + remarks string作为局部变量时候记得要调用析构函数 因为结构体不会自动调用析构函数



> **.push_back(string* self,char c)**		$O(1)$
>
> 在最后添加一个字符
>
> + param self 对象自身的地址
> + param c 需要添加的字符
> + return void



> **.pop_back(string* self)**		$O(1)$
>
> 删除最后一个字符并返回它
>
> + param self 对象自身的地址
> + return char 返回被删除的字符 如果字符串为空 返回'\0'



> **.size(string* self)**
>
> 获取字符串的长度
>
> + param self 对象自身的地址
> + return unsigned int 返回字符串长度 不包括终止符'\0'



> **.copy(string* self,string *s)**		$O(n)$
>
> string的赋值
>
> + param self 对象自身的地址
> + param s 被复制的字符串对象
> + return void



> **.c_copy(string* self, const char* s)**		$O(n)$
>
> 字符数组的赋值
>
> + param self 对象自身的地址
> + param s 被复制的字符数组指针
> + return void



> **.show(string* self)**
>
> 打印输出字符串
>
> + param self 对象自身的地址
> + return void
> + remarks  使用的是printf输出到标准输出上



> **.equal(string* self,string* s)**
>
> 判断两个string是否相等
>
> + param self 对象自身的地址
> + param s 需要比较的string的地址
> + return bool 如果相等返回true 否则返回false



> **.c_equal(string* self,const char* s)**
>
> 判断string和字符数组是否相等
>
> + param self 对象自身的地址
> + param s 需要比较的字符串数组指针
> + return bool 如果相等返回true 否则返回false



> **.greater_than(string* self,string* s)**
>
> 判断是否大于
>
> + param self 对象自身的地址
> + param s 需要比较的string地址
> + return bool 如果大于返回true 否则返回false



> **.c_greater_than(string* self,const char* s)**
>
> 判断string是否大于字符数组
>
> + param self 对象自身的地址
> + param s 需要比较的字符串数组指针
> + return bool 如果大于返回true 否则返回false



> **.fewer_than(string* self,string* s)**
>
> 判断是否小于
>
> + param self 对象自身的地址
> + param s 需要比较的string地址
> + return bool 如果小于返回true 否则返回false



> **.c_fewer_than(string* self,const char* s)**
>
> 判断string是否小于字符数组
>
> + param self 对象自身的地址
> + param s 需要比较的字符串数组指针
> + return bool 如果小于返回true 否则返回false



> **.append(string* self,string *s)**		$O(n)$
>
> 字符串追加字符串
>
> + param self 对象自身的地址
> + param s 需要追加的字符串对象地址
> + return void
> + remarks 大概像是+=的功能



> **.c_append(string* self, char* s)**		$O(n)$
>
> 字符串追加C字符串
>
> + param self 对象自身的地址
> + param s 需要追加的字符串指针
> + return void



> **.c_substr(string* self,int offset,int length)**		$O(n)$
>
> 获取子串 返回C字符串
>
> + param self 对象自身的地址
> + param offset 子串开始的位置
> + param length 子串的长度
> + return char* 子串的右值指针 如果length大于可获取子串长度 返回到结尾 如果偏移值和长度有误 返回空字符串



> **.substr(string* self,int offset,int length)**		$O(n)$
>
> 获取子串 返回string右值对象
>
> + param self 对象自身的地址
> + param offset 子串开始的位置
> + param length 子串的长度
> + return string 子串的string**右值**对象  如果length大于可获取子串长度 返回到结尾 如果偏移值和长度有误 返回空字符串的string右值对象
> + remarks 该返回值如果赋值在已初始化的对象  请务必先析构之前的对象  一般用于声明时候直接用该函数初始化



> **.c_find(string* self,char* pattern,int begin)**		$O(m+n)$
>
> 匹配C字符串
>
> + param self 对象自身的地址
> + param pattern 模式匹配的模板字符串
> + param begin 从原字符串哪里开始匹配
> + return int 如果匹配成功返回第一次匹配成功的索引值 匹配失败返回-1



> **.find(string* self,string* pattern,int begin)**		$O(m+n)$
>
> 匹配字符串
>
> + param self 对象自身的地址
> + param pattern 模式匹配的模板字符串
> + param begin 从原字符串哪里开始匹配
> + return int 如果匹配成功返回第一次匹配成功的索引值 匹配失败返回-1



> **.clear(string* self)**
>
> 清空字符串
>
> + param self 对象自身的地址
> + return void
> + remarks 实现为仅仅将其数据地址首位置为终止符 内存空间并没有释放



> **.reverse(string* self)**		$O(n)$
>
> 翻转字符串
>
> + param self 对象自身的地址
> + return void



> **.erase(string* self,int begin,int end)**		$O(n)$
>
> 删除字符串的子串
>
> + param self 对象自身的地址
> + param begin 删除开始的索引位置
> + param end 删除结束的索引位置+1
> + return void
> + remarks 删除的范围是[begin,end) 左闭右开 删除掉的并没有释放其内存



> **.c_insert(string* self,int pos,char* s)**		$O(n)$
>
> 字符串的插入
>
> + param self 对象自身的地址
> + param pos 开始插入的位置 注意即该位置上原来的字符将会放在插入的后面
> + param s 插入的字符串
> + return void



> **.c_insert(string* self,int pos,string* s)**		$O(n)$
>
> 字符串的插入
>
> + param self 对象自身的地址
> + param pos 开始插入的位置 注意即该位置上原来的字符将会放在插入的后面
> + param s 插入的string对象地址
> + return void