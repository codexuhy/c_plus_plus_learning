# 3.STL常用容器
## 3.1 string容器
### 3.1.1 string基本概念
本质：
- string是C++风格的字符串，而string本质上是一个类
string和char*区别：
- char*是一个指针
- string是一个类，类内部封装了char*，管理这个字符串，是一个char*型的容器。
特点：
string类内部封装了很多成员方法
例如：查找find、拷贝copy，删除delete 替换replace，插入insert
string管理char*所分配的内存，不用担心复制越界和取值越界等，由类内部进行负责

### 3.1.2 string构造函数
构造函数原型：
- string()                      //创建一个空的字符串 例如：string str;
  string(const char* s);        //使用字符串初始化
- string(const string& str);    // 使用一个string对象初始化另一个string对象
- string(int n,char c);\t\t     //使用n个字符初始化
**示例**：3.1-string容器-构造函数.cpp
总结：string的多种构造方式没有可比性，灵活使用即可

### 3.1.3 string赋值操作
功能描述：
- 给string字符串进行赋值

赋值的函数原型:
- string &operator=(const char *s);       // char*类型字符串 赋值给当前的字符串
- string &operator=(const string &s);     //把字符串s赋值给当前的字符串
- string &operator=(char c);              //把字赋值给当前的字符串
- string &assign()(const char *s);        //把字符串s赋给当前的字符串
- string &assign()(const char *s, int n); //把字符串s的前n个字符串赋值给当前的字符串
- string &assign(const string &s);        //把字符串s赋值给当前字符串
- string &assign(int n, char c);          //用n个字符c赋值给当前字符串
**示例**：3.2-string容器-赋值操作.cpp
总结：
    string的赋值方式很多，operator= 这种方式是比较实用的

### 3.1.4 string字符串拼接
功能描述：
- 实现在字符串末尾拼接字符串

函数原型:
- string &operator+=(const char *str);              // 重载+=操作符
- string &operator+=(const char c);                 //重载+=操作符
- string &operator+=(const string &str);            //重载+=操作符
- string &append()(const char *s);                 //把字符串s连接到当前字符串结尾
- string &append()(const char *s, int n);          //把字符串s的前n个字符连接到当前字符串结尾
- string &append(const string &s);                 //同operator+=(const string& str)
- string &append(const string &s，int pos, int n); //字符串s中从pos开始的n个字符连接到字符串结尾
**示例**：3.3-string容器-字符串拼接.cpp
总结：
    string的拼接的重载版本很多，初学阶段记住几种即可

### 3.1.5 string查找和替换
功能描述：
- 查找：查找指定字符串是否存在
- 替换：在指定的位置替换字符串

函数原型:
- int find(const string& str, int pos = 0)const;      // 查找str第一次出现位置，从pos开始查找
- int find(const char* s, int pos = 0)const;          // 查找s第一次出现位置，从pos开始查找
- int find(const char* s, int pos, int n)const;       //从pos位置查找s的前n个字符第一次位置
- int find(const char c, int pos = 0)const;           // 查找字符c第一次出现位置
- int rfind(const string& str, int pos = npos)const;  //查找str最后一次位置，从pos开始查找
- int rfind(const char* s, int pos = n)const;         // 从pos开始s的前n个字符最后一个位置
- int rfind(const char c, int pos = 0)const;          // 查找字符c最后一次出现的位置
- string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
- string& replace(int pos, int n, const char* s);     //替换从pos开始的n个字符为字符串s
**示例**：3.4-string容器-字符串查找与替换.cpp
总结：
- find查找是从左往后，rfind从右往左
- find找到字符串后返回查找的第一个字符位置，找不到返回-1
- replace在替换时，要指定从哪个位置起，多少个字符，替换成什么样的字符串

### 3.1.6 string字符串比较
功能描述：
- 字符串之间的比较
比较方式：
- 字符串比较是按字符的ASCII码进行对比
=返回 0
>返回 1
<返回 -1

函数原型:
- int compare(const string& str)const;      // 与字符串s比较
- int compare(const char* s)const;          // 与字符串s比较
**示例**：3.5-string容器-字符串拼接.cpp
总结：字符串对比主要是用于比较两个字符串是否相等，判断谁大谁小的意义并不是很大

### 3.1.7 string字符存取
string中单个字符存取方式有两种
- char& operator[] (int n); // 通过[]方式取字符
- char& at(int n); // 通过at方法获取字符

函数原型:
- int compare(const string& str)const;      // 与字符串s比较
- int compare(const char* s)const;          // 与字符串s比较
**示例**：3.6-string容器-字符串存取.cpp
总结：string字符串中单个字符存取有两种方式，利用[]或at

### 3.1.8 string插入和删除
功能描述：
- 对string字符串进行插入和删除字符 操作

函数原型:
- string& insert(int pos,const char* s);      // 插入字符串
- string& insert(int pos,const string& str);  // 插入字符串
- string& insert(int pos,int n, char c);      // 在指定位置插入n个字符c
- string& earese(int pos,int n = npos);       // 删除从Pos开始的n个字符
**示例**：3.7-string容器-插入和删除.cpp
总结：插入和删除的起始下标都是从0开始

### 3.1.9 string子串
功能描述：
- 从字符串中获取想要的子串

函数原型:
- string& substr(int pos = 0,int n = npos); const     // 返回由pos开始的n个字符组成的字符串
**示例**：3.8-string容器-子串.cpp
总结：灵活的运用求子串功能，可以在实际开发中获取有效的信息