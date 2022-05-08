# 4 STL-对象
## 4.1 函数对象
### 4.1.1 函数对象概念
**概念：**
- 重载函数调用操作符的类，其对象称为函数对象
- 函数对象使用重载的()时，行为类似函数调用，也叫仿函数
**本质：**
函数对象(仿函数)是一个类，不是一个函数

### 4.1.2函数对象使用
**特点：**
- 函数对象在使用时，可以像普通函数那样调用，可以有参数，可以有返回值
- 函数对象超出普通函数的概念，函数对象可以有自己的状态
- 函数对象可以作为参数传递
**示例：** 4.1-函数对象的基本使用
总结：
- 仿函数写法非常灵活，可以作为参数进行传递

## 4.2 谓词
### 4.2.1 谓词概念
**概念：**
- 返回bool类型的仿函数称为谓词
- 如果operator() 接受一个参数，那么叫做一元谓词
- 如果operator()接受两个参数，那么叫做二元谓词

### 4.2.2 一元谓词
**示例：** 4.2-函数谓词-一元谓词

总结：参数只有一个的谓词，称为一元谓词

### 4.2.3 二元谓词
**示例：** 4.3-函数谓词-二元谓词

总结：参数有二元的谓词，称为二元谓词

## 4.3 内建函数
### 4.3.1 内建函数对象意义
**概念：**
- STL内建了一些函数对象
**分类：**
- 算术仿函数
- 关系仿函数
- 逻辑仿函数
**用法：**
- 这些仿函数所产生的对象，用法和一般函数完全相同
- 使用内建函数对象，需要引入头文件#include<functional>

### 4.3.2 算术仿函数
**功能描述：**
- 实现四则运算
- 其中negate是一元运算，其他都是二元运算
**仿函数原型：**
- template<class T> T plus<T>       //加法仿函数
- template<class T> T minus<T>      //减法仿函数
- template<class T> T multiplies<T> //乘法仿函数
- template<class T> T divides<T>    //除法仿函数
- template<class T> T modulus<T>    //取模仿函数
- template<class T> T negate<T>     //取反仿函数

**示例：** 4.4-内联函数-算术仿函数.cpp
总结：使用内建函数对象时，需要引入头文件#include<functional>

### 4.3.3 关系仿函数
**功能描述：**
- 实现关系对比
- 其中negate是一元运算，其他都是二元运算
**仿函数原型：**
- template<class T> T bool equal_to<T>          //等于
- template<class T> T bool not_equal_to<T>      //不等于
- template<class T> T greater<T>                //大于
- template<class T> T greater_equal<T>          //大于等于
- template<class T> T less<T>                   //小于
- template<class T> T less_equal<T>             //小于等于

**示例：** 4.5-内联函数-关系仿函数.cpp
总结：关系仿函数中最常用的就是greater<>大于

### 4.3.4 逻辑仿函数
**功能描述：**
- 实现逻辑运算
- 其中negate是一元运算，其他都是二元运算
**仿函数原型：**
- template<class T> T bool logical_and<T>      //逻辑与
- template<class T> T bool logical_or<T>       //逻辑或
- template<class T> T bool logical_not<T>      //逻辑非

**示例：** 4.6-内联函数-逻辑仿函数.cpp
总结：逻辑仿函数实际应用比较少，了解即可

