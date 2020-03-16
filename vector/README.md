## vector

目前vector拥有 4 个全局函数  7 个成员变量 6 个成员函数

> **模板函数的定义**
>
> 作为该库泛型容器的通用模板函数格式
>
> ```c++
> //对象析构函数
> //需要把对象拥有的全部指针处理
> void destroy_func(void* obj_addr);
> //对象比较函数
> //>返回正数 ==返回0 <返回负数
> int compare_func(const void* a_addr,const void* b_addr);
> //对象复制函数
> //需要把新的复制出来的对象赋值给dest
> void copy_func(void* dest_addr,const void* src_addr);
> ```



> **vector的声明与定义**
>
> ```c++
> vector v=new_vector(sizeof(type),destroy_func,copy_func,compare_func);
> ```
>
> type为你所需要的类型,三个模板函数中不需要的函数填入NULL即可
>
> **vector的释放**
>
> ```c++
> v->destroy(v);
> ```
>
> 注意不要对vector类型直接进行复制操作 请用成员函数copy
>
> **成员函数的使用**
>
> ```c++
> v->push_back(v,&elem);
> ```
>
> 第一个参数均为对象本身 其余参数注意形参是否需要传入元素地址



> **[global] new_vector(size_t elem_size,destroy_func elem_free,compare_func elem_cmp,copy_func elem_copy)**
>
> vector对象构造获取函数
>
> + param elem_size 元素类型的大小 泛型编程必备
> + param elem_free 元素的析构函数 如没有则填NULL
> + param elem_cmp 元素的比较函数 如没有则填NULL
> + param elem_copy 元素的复制函数 如没有则填NULL
> + return vector 返回一个初始化后的vector对象
> + remarks 一般来说拥有成员指针的对象必须拥有析构函数和复制函数 否则会内存泄露和指针操作同一块地址 比较大小函数如不需要用到排序相关函数则可省略



> **[global] vector_destroy(void* obj_addr)**
>
> vector对象的模板析构函数
>
> + param obj_addr 需要释放的对象地址
> + return void
> + remarks 一般来说不需要直接调用



> **[global] vector_copy(void* dest_addr,const void* src_addr)**
>
> vector对象的模板复制函数
>
> + param dest_addr 需要复制的对象地址
> + param src_addr 被复制的对象地址
> + return void
> + remarks 一般来说不需要直接调用



> **[global] cmp_destroy(const void* a_addr,const void* b_addr)**
>
> vector对象的模板比较函数
>
> + param a_addr 元素a的地址
> + param b_addr 元素b的地址
> + return int 模板比较返回
> + remarks 一般来说不需要直接调用



> **->data**
>
> vector对象的数据域
>
> + type void* 可通过强制类型转换转换为元素对应的数组
> + remarks 你可以这样用: type* arr=(type*)v->data 然后你就可以用arr来进行常规的C操作 当然 对元素和内存的修改还是得用v对象的



> **->elem_size**
>
> 单元素内存大小
>
> + type size_t 泛型的sizeof返回值



> **->max_size**
>
> 已分配的内存的大小
>
> + type size_t
> + remarks 一般来说不需要手动操作内存分配



> **->size**
>
> 已有多少个元素
>
> + type unsigned int 数组的长度



> **->elem_free**
>
> 元素的析构函数



> **->elem_copy**
>
> 元素的复制函数



> **->elem_cmp**
>
> 元素的比较函数



> **->at(vector self,unsigned int pos)**
>
> 获取指向pos位元素的地址
>
> + param self 对象本身
> + param pos 地址偏移值 即数组下标
> + return void* (即type*)
> + remarks 注意返回的是元素的地址 需要解指针获取实体元素



> **->destroy(vector self)**
>
> 析构函数
>
> + param self 对象本身
> + return void



> **->copy(vector self,vector v)**
>
> 复制函数 不允许self或v未初始化
>
> + param self 对象本身
> + param v 被复制的对象
> + return void



> **->push_back(vector self,void* elem_addr)**		$O(1)$
>
> 压入元素 最实用的操作
>
> + param self 对象本身
> + param elem_addr 需要压入的元素的地址
> + return void
> + remarks 压入的操作是以元素复制函数来保证复制的 如果没有复制函数 那么将会把实体压入



> **->erase(vector self,unsigned int pos)**		$O(n)$
>
> 删除指定位置的元素
>
> + param self 对象本身
> + param pos 需要删除元素的下标
> + return void



> **->pop_back(vector) self**
>
> 弹出最后的元素 是erase的特例
>
> + param self 对象本身
> + return void

