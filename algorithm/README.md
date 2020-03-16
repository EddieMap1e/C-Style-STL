## algorithm

目前algorithm拥有 11 个全局函数

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



> **[global] swap(void* a_addr,void* b_addr,size_t elem_size)**
>
> 交换元素函数
>
> + param a_addr 需要交换的对象a的地址
> + param b_addr 需要交换的对象b的地址
> + elem_size 对象的内存大小
> + return void 两个对象元素的内存内容直接交换
> + remarks a和b的类型需要相同



> **[global] max_element(void* arr,int begin,int end,size_t elem_size,compare_func cmp)**
>
> 获取区间最大值的引用
>
> + param arr 对象数组首地址
> + param begin 左闭区间的偏移值
> + param end 右闭区间的偏移值
> + elem_size 数组内对象元素的内存大小
> + cmp 数组内对象元素的比较函数
> + return void* 返回指向最大元素的空类型指针 需要在使用时候强制类型转换以及解指针
> + remarks 左闭右闭区间 返回的是引用 不是复制体



> **[global] min_element(void* arr,int begin,int end,size_t elem_size,compare_func cmp)**
>
> 获取区间最小值的引用
>
> + param arr 对象数组首地址
> + param begin 左闭区间的偏移值
> + param end 右闭区间的偏移值
> + elem_size 数组内对象元素的内存大小
> + cmp 数组内对象元素的比较函数
> + return void* 返回指向最小元素的空类型指针 需要在使用时候强制类型转换以及解指针
> + remarks 左闭右闭区间 返回的是引用 不是复制体



> **[global] int_cmp(void*a_addr,void *b_addr)**
>
> 基本类型int的比较函数
>
> + param a_addr 比较元素前者
> + param b_addr 比较元素后者
> + return int >返回1 ==返回0 <返回-1



> **[global] long_long_cmp(void*a_addr,void *b_addr)**
>
> 基本类型long_long的比较函数
>
> + param a_addr 比较元素前者
> + param b_addr 比较元素后者
> + return int >返回1 ==返回0 <返回-1



> **[global] char_cmp(void*a_addr,void *b_addr)**
>
> 基本类型char的比较函数
>
> + param a_addr 比较元素前者
> + param b_addr 比较元素后者
> + return int >返回1 ==返回0 <返回-1



> **[global] float_cmp(void*a_addr,void *b_addr)**
>
> 基本类型float的比较函数
>
> + param a_addr 比较元素前者
> + param b_addr 比较元素后者
> + return int >返回1 ==返回0 <返回-1
> + remarks 此函数相等的精度为相差不超过1e-8表示相等



> **[global] int_cmp(void*a_addr,void *b_addr)**
>
> 基本类型double的比较函数
>
> + param a_addr 比较元素前者
> + param b_addr 比较元素后者
> + return int >返回1 ==返回0 <返回-1
> + remarks 此函数相等的精度为相差不超过1e-8表示相等



> **[global] c_str_cmp(void*a_addr,void *b_addr)**
>
> 基本类型char*的比较函数
>
> + param a_addr 比较元素前者
> + param b_addr 比较元素后者
> + return int >返回1 ==返回0 <返回-1



> **[global] bubble_sort(void* arr,int length,size_t elem_size,compare_func cmp)**		$O(n^2)$
>
> 泛型冒泡排序
>
> + param arr 待排序数组首地址
> + param length 待排序元素个数
> + param elem_size 数组内对象的内存大小
> + param cmp 数组内对象的模板比较函数
> + return void
> + remarks 最好复杂度是O(n)



>**[global] quick_sort(void* arr,int begin,int end,size_t elem_size,compare_func cmp)**		$O(nlog(n))$
>
>泛型冒泡排序
>
>+ param arr 待排序数组首地址
>+ param begin 待排序数组的最左端 闭合
>+ param end 待排序数组的最右端 闭合
>+ param elem_size 数组内对象的内存大小
>+ param cmp 数组内对象的模板比较函数
>+ return void
>+ remarks 最坏复杂度的 O(n*n)









