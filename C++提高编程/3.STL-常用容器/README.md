# 3.STL常用容器
## 3.1 string容器
### 3.1.1 string基本概念
**本质：**
- string是C++风格的字符串，而string本质上是一个类
string和char*区别：
- char*是一个指针
- string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。
特点：
string类内部封装了很多成员方法
例如：查找find、拷贝copy，删除delete 替换replace，插入insert
string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

### 3.1.2 string构造函数
**构造函数原型：**
- string()                      //创建一个空的字符串 例如：string str;
  string(const char* s);        //使用字符串初始化
- string(const string& str);    // 使用一个string对象初始化另一个string对象
- string(int n,char c);     //使用n个字符初始化

**示例：** 3.1-string容器-构造函数.cpp
**总结：** string的多种构造方式没有可比性，灵活使用即可

### 3.1.3 string赋值操作
**功能描述：**
- 给string字符串进行赋值

**赋值的函数原型:**
- string &operator=(const char *s);       // char*类型字符串 赋值给当前的字符串
- string &operator=(const string &s);     //把字符串s赋值给当前的字符串
- string &operator=(char c);              //把字赋值给当前的字符串
- string &assign()(const char *s);        //把字符串s赋给当前的字符串
- string &assign()(const char *s, int n); //把字符串s的前n个字符串赋值给当前的字符串
- string &assign(const string &s);        //把字符串s赋值给当前字符串
- string &assign(int n, char c);          //用n个字符c赋值给当前字符串

**示例：** 3.2-string容器-赋值操作.cpp
**总结：** 
    string的赋值方式很多，operator= 这种方式是比较实用的

### 3.1.4 string字符串拼接
**功能描述**：
- 实现在字符串末尾拼接字符串

**函数原型**:
- string &operator+=(const char *str);              // 重载+=操作符
- string &operator+=(const char c);                 //重载+=操作符
- string &operator+=(const string &str);            //重载+=操作符
- string &append()(const char *s);                 //把字符串s连接到当前字符串结尾
- string &append()(const char *s, int n);          //把字符串s的前n个字符连接到当前字符串结尾
- string &append(const string &s);                 //同operator+=(const string& str)
- string &append(const string &s，int pos, int n); //字符串s中从pos开始的n个字符连接到字符串结尾

**示例**：3.3-string容器-字符串拼接.cpp
**总结：**
    string的拼接的重载版本很多，初学阶段记住几种即可

### 3.1.5 string查找和替换
**功能描述**：
- 查找：查找指定字符串是否存在
- 替换：在指定的位置替换字符串

**函数原型**:
- int find(const string& str, int pos = 0)const;      // 查找str第一次出现位置，从pos开始查找
- int find(const char* s, int pos = 0)const;          // 查找s第一次出现位置，从pos开始查找
- int find(const char* s, int pos, int n)const;       //从pos位置查找s的前n个字符第一次位置
- int find(const char c, int pos = 0)const;           // 查找字符c第一次出现位置
- int rfind(const string& str, int pos = npos)const;  //查找str最后一次位置，从pos开始查找
- int rfind(const char* s, int pos = n)const;         // 从pos开始s的前n个字符最后一个位置
- int rfind(const char c, int pos = 0)const;          // 查找字符c最后一次出现的位置
- string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
- string& replace(int pos, int n, const char* s);     //替换从pos开始的n个字符为字符串s

**示例：** 3.4-string容器-字符串查找与替换.cpp
**总结：**
- find查找是从左往后，rfind从右往左
- find找到字符串后返回查找的第一个字符位置，找不到返回-1
- replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

### 3.1.6 string字符串比较
**功能描述：**
- 字符串之间的比较
比较方式：
- 字符串比较是按字符的ASCII码进行对比
=返回 0
>返回 1
<返回 -1

**函数原型:**
- int compare(const string& str)const;      // 与字符串s比较
- int compare(const char* s)const;          // 与字符串s比较

**示例**：3.5-string容器-字符串拼接.cpp
**总结：** 字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大

### 3.1.7 string字符存取
string中单个字符存取方式有两种
- char& operator[] (int n); // 通过[]方式取字符
- char& at(int n); // 通过at方法获取字符

**函数原型:**
- int compare(const string& str)const;      // 与字符串s比较
- int compare(const char* s)const;          // 与字符串s比较

**示例：** 3.6-string容器-字符串存取.cpp
**总结：** string字符串中单个字符存取有两种方式，利用[]或at

### 3.1.8 string插入和删除
**功能描述：**
- 对string字符串进行插入和删除字符 操作

**函数原型:**
- string& insert(int pos,const char* s);      // 插入字符串
- string& insert(int pos,const string& str);  // 插入字符串
- string& insert(int pos,int n, char c);      // 在指定位置插入n个字符c
- string& earese(int pos,int n = npos);       // 删除从Pos开始的n个字符

**示例**：3.7-string容器-插入和删除.cpp
**总结：** 插入和删除的起始下标都是从0开始

### 3.1.9 string子串
**功能描述：**
- 从字符串中获取想要的子串

**函数原型:**
- string& substr(int pos = 0,int n = npos); const     // 返回由pos开始的n个字符组成的字符串

**示例：** 3.8-string容器-子串.cpp
**总结：** 灵活的运用求子串功能，可以在实际开发中获取有效的信息

## 3.2 vector容器
### 3.2.1 vector基本概念
**功能：**
- vector数据结构和数组非常相似，也称为单端数组

**vector与普通数组区别：**
- 不同之处在于数组是静态空间，而vector可以动态扩展

**动态扩展：**
- 并不是在原有空间之后续接新空间，二十找更大的内存空间和，然后将源数据拷贝新空间，释放原空间

### 3.2.2 vector构造函数
**功能描述：**
- 创建vector容器

**函数原型:**
- vector<T> v;                //采用模板实现类实现，默认构造函数
- vector(v.begin(), v.end()); //将v[begin(),end()]区间中的元素拷贝给本身
- vector(m, elem);            //构造函数将n个elem拷贝给本身
- vector(const vector &vec)   //拷贝构造函数
**示例**：3.2.1-vector容器-构造函数.cpp
**总结：** vector容器的迭代器是支持随机访问的迭代器

### 3.2.3 vector赋值操作
**功能描述：**
- 给vector容器进行赋值

**函数原型:**
- vector &operator=(const vector &vec); //重载等号操作符
- assign(beg, end);                     //将v[beg,end)区间中的元素拷贝赋值给本
- assign(n, elem);                      //将n个elem拷贝构造赋值给本身

**示例**：3.2.2-vector容器-赋值操作.cpp
总结：vector赋值方式比较简单，使用operator=，或者assign都可以

### 3.2.4 vector容量和大小
**功能描述：**
- 对vector容器的容量和大小操作

**函数原型:**
- empty();               //判断容器是否为空
- capacity();            //容器的容量
- size();                //返回容器中元素的个数
- resize(int num);       //重新指定容器的长度为num,若容器变长，则以默认值填充新位置，
                         //如果容器变短，则末尾超出容器长度的元素被删除。
- resize(int num, elem); //重新指定容器的长度为num,若容器变长，则以emel值填充新位置
                         //如果容器变短，则末尾超出容器长度的元素被删除

**示例**：3.2.3-vector容器-容量和大小.cpp
**总结：**
- 判断是否为空 --- empty
- 返回元素个数 --- size
- 返回容器容量 --- capacity
- 重新指定大小 --- resize

### 3.2.5 vector插入和删除
**功能描述：**
- 对vector容器进行插入、删除操作

**函数原型:**
- push_back(ele);                                  //尾部插入元素ele
- pop_back();                                      //删除最后一个元素
- insert(const_iterator pos, ele);                 //迭代器指向位置pos插入元素ele
- insert(const_iterator pos, int count, ele);      //迭代器指向位置pos插入count个元素ele
- erase(const_iterator pos);                       //删除迭代器指向的元素
- erase(const_iterator start, const_iterator end); // 删除迭代器从start到end之间的元素
- clear();                                         //删除容器中所有元素

**示例**：3.2.4-vector容器-插入和删除.cpp
**总结：**
- 尾插 --- push_back
- 尾插 --- pop_back
- 插入 --- insert（位置迭代器）
- 删除 --- erase（位置迭代器）
- 清空 --- clear

### 3.2.6 vector数据存取
**功能描述：**
- 对vector中的数据的存取操作

**函数原型:**
- at(int idx); //返回索引idx所指的数据
- operator[];  //返回索引idx所指的数据
- front();     //返回容器中第一个数据元素
- back();      //返回容器中最后一个数据元素

**示例**：3.2.5-vector容器-vector数据存取.cpp
**总结：**
- 除了用迭代器取vector容器中元素，[]和at也可以
- front返回容器中第一个元素
- back返回容器最后一个元素

### 3.2.7 vector互换容器
**功能描述：**
- 实现两个容器内元素进行互换

**函数原型:**
- swap(vec); //将vec与本身的元素互换

**示例**：3.2.6-vector容器-互换容器.cpp
**总结：** swap可以使两个容器互换，可以达到实用的收缩内存效果

### 3.2.8 vector预留空间
**功能描述：**
- 减少vector在动态扩展容量时的扩展次数

**函数原型:**
- reserve(int len); //容器预留len个元素长度，预留位置不初始化，元素不可访问。

**示例**：3.2.7-vector容器-预留空间.cpp
**总结：** 如果数据量较大，可以一开始利用reserve预留空间

## 3.3 deque容器
### 3.3.1 deque容器基本概念
**功能：**
- 双端数组，可以对头端进行插入删除操作

**deque与vector区别：**
- vector对于头部的插入删除效率低，数据量越大，效率越低
- deque相对而言，对头部的插入删除速度会比vector快
- vector访问元素时的速度会比deque快，这和两者内部实现有关
![Image text](https://github.com/codexuhy/c_plus_plus_learning/blob/main/images/1.jpg#pic_center)

deque内部工作原理：
deque内部有个**中控器**，维护每段缓冲区中的内容，缓冲区中存放真实数据
中控器维护的是每个缓冲区的地址，使得使用deque时像一片连续的内存空间
![Image text](https://github.com/codexuhy/c_plus_plus_learning/blob/main/images/2.jpg#pic_center)
- deque容器的迭代器也是支持随机访问的
### 3.3.2 deque构造函数
**功能描述：**
- dequr容器构造

**函数原型：**
- deque<T> deqT;           //默认构造形式
- deque(beg, end);         //构造函数将[beg，end)区间中的元素拷贝给本身
- deque(n, elem);          //构造函数将n个elem拷贝给本身
- deque(const deque &deq); //拷贝构造函数

**示例：** 3.3.1-deque容器-构造函数.cpp
**总结：** deque容器和vector容器的构造方式几乎一致，灵活使用即可

### 3.3.3 deque赋值操作
**功能描述：**
- 给dequr容器进行赋值

**函数原型：**
- deque &operator=(const deque &deq); //重载等操作符
- assigh(beg, end);                   //将[beg,end)区间中的数据拷贝赋值给本身
- assign(n, elem);                    //将n个elem拷贝赋值给本身

**示例：** 3.3.2-deque容器-赋值操作.cpp
**总结：** deque容器复制操作和vector相同，需熟练掌握

### 3.3.4 deque大小操作
**功能描述：**
- 对deque容器的大小进行操作

**函数原型：**
- deque.empty();               //判断容器是否为空
- deque.size();                //返回容器中元素的个数
- deque.resize(int num);       //重新指定容器的长度为num,若容器变长，则以默认值填充新位置，
                               //如果容器变短，则末尾超出容器长度的元素被删除。
- deque.resize(int num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置
                               //如果容器变短，则末尾超出容器长度的元素被删除

**示例：** 3.3.3-deque容器-大小操作.cpp
**总结：**
- deque容器没有capacity概念
- 判断是否为空 --- empty
- 返回元素个数 --- size
- 重新指定个数 --- resize


### 3.3.5 deque插入和删除
**功能描述：**
- 向deque容器中插入和删除数据

**函数原型：**
两端插入操作：
- deque.push_back(elem);  //在容器尾部添加一个数据
- deque.push_front(elem); //在容器头部插入一个数据
- deque.pop_back();       //删除容器最后一个数据
- deque.pop_front();      //删除容器第一个数据
指定位置操作：
- insert(pos, elem);         //在pos位置插入一个elem元素的拷贝，返回新数据的位置
- insert(pos, n, elem)       //在pos位置插入n个elem数据，无返回值
- insert(pos, beg, end);     //在pos位置插入[beg,end)区间的数据，无返回值
- clear();                   //清空容器的所有数据
- erase(beg, end);           //删除[beg,end)区间的数据，返回下一个数据的位置
- erase(pos);                //删除pos位置的数据，返回下一个数据的位置

**示例：** 3.3.4-deque容器-插入和删除.cpp
**总结：**
- 插入和删除提供的位置是迭代器！
- 尾插 --- push_back
- 尾删 --- pop_back
- 头插 --- push_front
- 头删 --- pop_front


### 3.3.6 deque数据存取
**功能描述：**
- 对deque中数据的存取操作

**函数原型：**
- deque.push_back(elem);  //在容器尾部添加一个数据
- deque.push_front(elem); //在容器头部插入一个数据
- deque.pop_back();       //删除容器最后一个数据

**示例：** 3.3.5-deque容器-数据存取.cpp
**总结：**
- 除了用迭代器获取deque容器中元素,[]和at也可以
- front返回容器第一个元素
- back返回容器最后一个元素

### 3.3.7 deque排序
**功能描述：**
- 利用算法实现对deque容器进行排序

**算法：**
- sort(iterator bag,iterator end);  // 对beg和end区间内元素进行排序

**示例：** 3.3.6-deque容器-排序.cpp
**总结：** sorted算法比较实用，使用时包含头文件algorithm即可


## 3.4 案例-评委打分
### 3.4.1 案例描述
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

### 3.4.2 实现步骤
1. 创建五名选手，放到vector中
2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3. sort算法对deque容器中分数排序，去除最高分和最低分
4. deque容器遍历一遍,累加总分
5. 获取平均分

**示例代码：** 3.4-案例-评委打分.cpp


## 3.5 stack容器
### 3.5.1 stack基本概念
**概念：** stack是一种先进后出(First In Last Out,FILO)的数据结构，它只有一个出口
栈中只有顶端的元素可以被外界使用，因此栈不允许有遍历行为
栈中进入数据称为 --- 入栈 push
栈中弹出数据称为 --- 出栈 pop

### 3.5.2 stack常用接口
**功能描述：**
- 栈容器常用的对外接口

构造函数：
- stack<T> stk;            // stack采用模板类实现，stack对象的默认构造形式
- stack(const stack &stk); //拷贝构造函数

赋值操作：
- stack &operator=(const stack &stk); //重载等号操作符

数据存取：
- push(elem); //从栈顶添加元素
- pop();      //从栈顶移除第一个元素
- top();      //返回栈顶元素

大小操作：
- empty(); //判断堆栈是否为空
- size();  //返回栈的大小

**示例：** 3.5-stack容器.cpp
**总结：** 
- 入栈 --- push
- 出栈 --- pop
- 返回栈顶 --- top
- 判断栈是否为空 --- empty
- 返回栈大小 --- size


## 3.6 queue容器
### 3.6.1 queue基本概念
**概念：** Queue是一种先进先出(First In First Out,FIFO)的数据结构，它有两个出口
队列容器允许从一端新增元素，从另一端移除元素
队列中只有队头和队尾才可以被外界使用，因此 队列不允许有遍历行为
队列中进数据称为 --- 入队 push
队列中出数据称为 --- 出队 pop

### 3.6.2 queue常用接口
**功能描述：**
- 栈容器常用的对外接口

构造函数：
- queue<T> que;            // queue采用模板类实现,queue对象的默认构造形式
- queue(const queue &que); //拷贝构造函数

赋值操作：
- queue &operator=(const queue &que); //重载等号操作符

数据存取：
- push(elem); //往队尾添加元素
- pop();      //从队头移除第一个元素
- back();     //返回最后一个元素
- front();    //返回第一个元素

大小操作：
- empty(); //判断堆栈是否为空
- size();  //返回栈的大小

**示例：** 3.6-queue容器.cpp
**总结：** 
- 入队 --- push
- 出队 --- pop
- 返回队头元素 --- top
- 返回队尾元素 --- empty
- 判断队是否为空 --- empty
- 返回队列大小 --- size


## 3.7 list容器
### 3.7.1 list基本概念
**功能：** 将数据进行链式存储

**链表**(list)是一种物理存储单元上非连续的存储结构，数据元素的逻辑顺序是通过链表中的指针链接实现的

链表的组成：链表由一系列结点组成

结点的组成：一个是存储数据元素的**数据域**，另一个是存储下一个结点地址的**指针域**

STL中链表是一个双向循环链表


由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移,属于双向迭代器

list的优点：
- 采用动态存储分配，不会造成内存浪费和溢出
- 链表执行插入和删除操作十分方便，修改指针即可，不需要移动大量元素
list的缺点：
- 链表灵活，但是空间(指针域)和时间（遍历）额外耗费较大

List 有一个重要的性质，插入操作和删除操作都不会造成原有list迭代器的失效，这在vector是不成立的。

总结：STL中List和Vector是两个最常被使用的容器，各有优缺点
### 3.7.2 list构造函数
**功能描述：** 创建list容器
- 创建list容器

**函数原型:**
- list<T> lst;          //采用模板实现类实现，默认构造函数
- list(beg, end);       //将v[begin(),end()]区间中的元素拷贝给本身
- list(n, elem);        //构造函数将n个elem拷贝给本身
- list(const list &lst) //拷贝构造函数

**示例**：3.7.1-list容器-构造函数.cpp
总结：list构造方式同其他几个STL常用容器，熟练掌握即可

### 3.7.3 list赋值和交换
**功能描述：**
- 给list容器进行赋值，以及交换list容器

**函数原型:**
- list &operator=(const list &lst); //重载等号操作符
- assign(beg, end);                 //将[beg,end)区间中的元素拷贝赋值给本身
- assign(n, elem);                  //将n个elem拷贝构造赋值给本身
- swap(lst);                        //将lst与本身的元素互换

**示例**：3.7.2-list容器-赋值和交换.cpp
**总结：** list赋值和交换操作能够灵活运用即可

### 3.7.4 list大小操作
**功能描述：**
- 对list容器的大小进行操作

**函数原型:**
- empty();               //判断容器是否为空
- size();                //返回容器中元素的个数
- resize(int num);       //重新指定容器的长度为num,若容器变长，则以默认值填充新位置，
                         //如果容器变短，则末尾超出容器长度的元素被删除。
- resize(int num, elem); //重新指定容器的长度为num,若容器变长，则以emel值填充新位置
                         //如果容器变短，则末尾超出容器长度的元素被删除


**示例**：3.7.3-list容器-大小操作.cpp
**总结：**
- 判断是否为空 --- empty
- 返回元素个数 --- size
- 重新指定个数 --- resize

### 3.7.5 list插入和删除
**功能描述：**
- 对list容器进行数据的插入和删除

**函数原型:**
- push_back(elem);                                 //在容器尾部插入元素elem
- pop_back();                                      //删除容器中最后一个元素
- push_front(elem);                                //在容器开头插入一个元素
- pop_front();                                     //从容器开头移除第一个元素
- insert(pos, elem);                               //在pos位置插入elem元素的拷贝，返回新数据的位置
- insert(pos, n, elem);                            //在pos位置插入n个elem元素，无返回值
- insert(pos, begin, end);                         // 在pos位置插入[begin,end)区间的数据，无返回值。
- erase(const_iterator pos);                       //删除pos位置的数据，返回下一个数据的位置。
- erase(const_iterator start, const_iterator end); // 删除迭代器[start,end)区间的的数据，无返回值
- clear();                                         //删除容器中所有元素
- remove();                                        //删除容器中所有与elem值匹配的元素

**示例**：3.7.4-list容器-插入与删除.cpp
**总结：**
- 尾插 --- push_back
- 尾删 --- pop_back
- 头插 --- push_front
- 插入 --- insert
- 删除 --- erase
- 移除 --- remove
- 清空 --- clear

### 3.7.6 list数据存取
**功能描述：**
- 对list容器中的数据进行存取

**函数原型:**
- front();     //返回容器中第一个数据元素
- back();      //返回容器中最后一个数据元素

**示例**：3.7.5-list容器-数据存取.cpp
**总结：**
- list容器中不可以通过[]或at方式访问数据
- 返回容器中第一个元素 --- front
- 返回容器最后一个元素 --- back

### 3.7.7 list反转和排序
**功能描述：**
- 将容器中的元素反转，以及将容器中的数据进行排序

**函数原型:**
- reverse(); //反转链表
- sort();    //链表排序

**示例**：3.7.5-list容器-数据存取.cpp
**总结：**
- list容器中不可以通过[]或at方式访问数据
- 返回容器中第一个元素 --- front
- 返回容器最后一个元素 --- back

### 3.7.8 排序案例
案例描述：将Person自定义数据类型进行排序,Person中属性有姓名、年龄、身高
排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序

**示例**：3.7.6-list容器-排序案例.cpp
**总结：**
- 对于自定义数据类型，必须要指定排序规则，否则编译器不知道如何进行排序
- 高级排序知识在排序规则上再进行逻辑规则制定，并不复杂

## 3.8 set/multiset容器
### 3.8.1 set基本概念
**简介：**
- 所有元素都会在插入时自动被排序

**本质：**
- set/multiset属于关联式容器，底层结构是用二叉树实现。

set和multi区别：
- set不允许容器中有重复的元素
- multiset允许容器中有重复的元素

### 3.8.2 set构造和赋值
功能描述：创建set容器以及赋值

构造：
- set<T> st;          // 默认构造函数
- set(const set &st); // 拷贝构造
赋值：
- set &operator=(const set &st); //重载等号操作符

**示例：** 3.8.1-set容器-构造和赋值.cpp

### 3.8.3 set大小和交换
**功能描述：**
- 统计set容器大小以及交换set容器

**函数原型：**
- size();   //返回容器中元素的数目
- empty();  //判断容器是否为空
- swap(st); //交换两个集合容器

**示例：** 3.8.2-set容器-大小和交换.cpp

**总结：**
- 统计大小 --- size
- 判断是否为空 --- empty
- 交换容器 --- swap

### 3.8.4 set插入和删除
**功能描述：**
- 统计set容器大小以及交换set容器

**函数原型：**
- insert(elem);    //在容器中插入元素
- claer();         //清楚所有元素
- erase(pos);      //删除pos迭代器所指的元素，返回下一个元素的迭代器
- erase(beg, end); //删除区间[beg,end)的所有元素，返回下一个元素的迭代器
- erase(elem);     //删除容器中值为elem的元素

**示例：** 3.8.3-set容器-插入和删除.cpp

**总结：**
- 插入 --- size
- 删除 --- empty
- 清空 --- swap

### 3.8.5 set查找和统计
**功能描述：**
- 对set容器进行查找数据以及统计数据

**函数原型：**
- find(key);    //查找key是否存在,返回该键的元素的迭代器;若不存在，返回set.end();
- count(key);   // 统计key的元素个数
**示例：** 3.8.4-set容器-查找和统计.cpp

**总结：** 
- 查找 --- find (返回的是迭代器)
- 统计 --- count (对于set,结果为0或者1)

### 3.8.6 set和multiset区别
**学习目标：**
- 掌握set和multiset区别

**区别：**
- set不可以插入重复数据，而multiset可以
- set插入数据的同时会返回插入结果，表示插入是否成功
- multiset不会检测数据，因此可以插入重复数据

**示例：** 3.8.5-set容器-set和multiset区别.cpp

**总结：** 
- 如果不允许插入重复数据可以利用set
- 如果需要插入重复数据利用multiset

### 3.8.7 pair对组创建
**功能描述：**
- 成对出现的数据，利用对组可以返回两个数据

**两种创建方式：**
- pair<type,type> p (value1,value2);
- pair<type,type> p = makr_pair(value1,value2);

**示例：** 3.8.6-pair对组-对组的创建.cpp

**总结：** 
两种方式都可以创建对组，记住一种方式即可

### 3.8.8 set容器排序
**学习目标：**
- set容器默认排序规则为从小到大，掌握如何改变排序规则

**主要技术点：**
- 利用仿函数，可以改变排序规则

**示例一：** set存放内置数据类型
```
3.8.7-set容器-排序.cpp
```
总结：利用仿函数可以指定set容器的排序规则

**示例二：** set存放自定义数据类型
```
3.8.8-set容器-排(自定义类型).cpp
```
总结：对于自定义数据类型，set必须指定排序规则才可以插入数据

## 3.9 map/multimap容器
### 3.9.1 map基本概念
**简介：**
- map中所有元素都是pair
- pair中第一个元素为key(键值),起到索引作用，第二个元素为value
- 所有元素都会根据元素的键值自动排序
**本质：**
- map/multimap属于**关联式容器**，底层结构是用二叉树实现
**优点：**
- 可以根据key值快速找到value值
map和multimap区别：
- map不允许容器中有重复key值元素
- multimap允许容器中重复key值元素

### 3.9.2 map构造和赋值
**功能描述：**
- 对map容器进行构造和赋值操作
**函数原型：**
**构造：**
- map<T1,T2> mp;      //map默认构造函数
- map<const map &mp>; //拷贝构造函数
**赋值：**
- map& operator=(const map &mp); //重载等号操作符
**示例：** 3.9.1-map容器-构造和赋值.cpp
总结：map中所有元素都是成对出现，插入数据时候要使用对组

### 3.9.3 map大小和交换
**功能描述：**
- 统计map容器大小以及交换map容器
**函数原型：**
- size();   //返回容器中元素的数目
- empty();  //判断容器是否为空
- swap(st); //交换两个集合容器

**示例：** 3.9.2-map容器-大小和交换.cpp
**总结：**
- 统计大小 --- size
- 判断是否为空 --- empty
- 交换容器 --- swap

### 3.9.4 map插入和删除
**功能描述：**
- map容器进行插入数据和删除数据

**函数原型：**
- insert(elem);              //在容器中插入元素
- clear();                   //清空所有元素
- erase(pos);                //删除pos迭代器所指的元素，返回下一个元素的迭代器
- erase(beg, end);           //删除[beg,end)区间的数据，返回下一个数据的迭代器
- erase(key);                //删除容器中值为key的元素

**示例：** 3.9.3-map容器-插入和删除.cpp

**总结：**
- map插入方式很多,记住其一即可
- 插入 --- insert
- 删除 --- erase
- 清空 --- clear

### 3.9.5 map查找和统计
**功能描述：**
- 对map容器进行查找数据以及统计数据

**函数原型：**
- find(key);    //查找key是否存在,若存在，返回该键的元素的迭代器;若不存在，返回set.end();
- count(key);   //统计key的元素个数
**示例：** 3.9.4-map容器-查找和统计.cpp

**总结：** 
- 查找 --- find (返回的是迭代器)
- 统计 --- count (对于map,结果为0或者1)

### 3.9.6 map容器排序
**学习目标：**
- map容器默认排序规则为 按照key值进行 从小到大排序，如何掌握改变排序规则

**主要技术点：**
- 利用仿函数，可以改变排序规则
**示例：** 3.9.4-map容器-查找和统计.cpp

**总结：** 
- 查找 --- find (返回的是迭代器)
- 统计 --- count (对于map,结果为0或者1)

