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
总结：vector容器的迭代器是支持随机访问的迭代器

### 3.2.3 vector赋值操作
**功能描述：**
- 给vector容器进行赋值

**函数原型:**
- vector &operator=(const vector &vec); //重载等号操作符
- assign(beg, end);                     //将v[beg,end]区间中的元素拷贝赋值给本
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
- insert(pos, beg, end);     //在pos位置插入[beg,end)区间的数据，无fanhu值
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
