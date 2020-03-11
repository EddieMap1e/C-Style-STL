## string

目前string拥有 1 个全局函数  1 个成员变量 13 个成员函数

> **string的声明**
>
> ```c++
> string str={""};
> ```
>
> 声明时候必须作出定义,大括号初始化的内容无意义,将会被init成员函数覆盖
>
> **成员函数的使用**
>
> 第一个参数均为对象本身
>
> ```c++
> str.show(&str);
> ```



>**string_init(string* self,const char* s)**
>
>string对象的初始化
>
>+ param self 需要初始化的string
>+ param s 初始化的字符串
>+ return void
>+ remarks 任何时候定义string后必须对其使用该全局函数进行初始化 不要重复对同一个对象使用



> **.str**
>
> string对象的字符数组
>
> + type char* C字符数组
> + remarks 可直接访问数组 非常量字符串



> **.push_back(string* self,char c)**
>
> 在最后添加一个字符
>
> + param self 对象自身的地址
> + param c 需要添加的字符
> + return void



> **.pop_back(string* self)**
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



> **.copy(string* self,string *s)**
>
> string的赋值
>
> + param self 对象自身的地址
> + param s 被复制的字符串对象
> + return void



> **.c_copy(string* self, const char* s)**
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



> **.append(string* self,string *s)**
>
> 字符串追加字符串
>
> + param self 对象自身的地址
> + param s 需要追加的字符串对象地址
> + return void
> + remarks 大概像是+=的功能