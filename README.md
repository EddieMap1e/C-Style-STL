是否受够了程设课/数据结构课/算法课等等...强制使用纯C去写作业?

那些快乐的**sort** **vector** **string** **set** **map** 统统没有? 就连 **new** 和引用 **&** 也不能用? 没了 **泛型** 复杂N倍?

我受够了! 于是在做数据结构作业时候就想使用纯C把STL都写一下

C语言模板函数怎么搞? 对C标准的qsort函数熟悉的同学就知道其实完全可以用过空类型指针操作内存 *危*

----

高清中文文档和注释保证

不是看不懂的STL 没有骚操作 (性能就下来了)

不是学不会的STL ~~应答老师轻松自如~~

----

尽我所能去完善
使用时候尽量不要传错误指针 空类型指针实现的泛型很危险的

---

> **my_string**
>
> substr KMP_match copy length push_back pop_back equal
>
> greater_than fewer_than append find reverse erase insert... 等等
>
> 不满足的地方大概在输入的时候不够优雅 ~~有空改改~~



> **my_algorithm**
>
> swap max/min_element  几种基本类型的模板compare函数
>
> bubble_sort quick_sort max/min
>
> 只要提供了cmp函数的类型都能使用 
>
> 其中max/min不是模板的  只是简单的宏定义



> **my_vector**
>
> push_back pop_back copy erase size at
>
> 全类型动态数组!!! 我开发的库都能完美嵌套 自身也是可嵌套的达成N维数组
>
> 自定义类型提供复制和析构函数就能够完美使用
>
> 正在完善该库...



> **my_list**
>
> 未开坑 链表 难度不大



> **my_stack**
>
> 未开坑 基于数组问题不大 基于deque得查下资料



> **my_queue**
>
> 未开坑 基于deque得查下资料



> **my_deque**
>
> 未开坑 原理大概明白 实现得查下资料



> **my_set**
>
> 未开坑 红黑树 代码量估计挺大



> **my_map**
>
> 未开坑 红黑树 同set



> **my_heap**
>
> 基于数组的堆问题不大

