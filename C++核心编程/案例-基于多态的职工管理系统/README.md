# 职工管理系统

## 1、管理系统需求

职工管理系统可以用来管理公司所有员工的信息

本教程主要利用C++实现一个基于多态的职工管理系统

公司中职工分为三类：普通员工、经理、老板、显示信息时，需要显示职工编号、职工姓名、职工岗位、以及职责

普通员工职责：完成经理交给的任务

经理职责：完成老板交给的任务，并下发给员工

老板职责：管理公司的事务

管理系统中需要实现的功能如下：

- 退出管理程序：退出当前管理系统
- 增加职工信息：实现批量添加职工信息，将信息录入文件中，职工信息为：职工编号，姓名，部门编号
- 显示职工信息：显示公司内部所有职工的信息
- 删除离职员工：按照编号删除指定的职工
- 修改职工信息：按照编号修改职工的个人信息
- 查找职工信息：按照职工编号后者职工姓名进行查找人员信息
- 按照编号排序：按照职工编号，进行排序，排序规则由用户指定
- 清空所有文档：清空文件中记录的所有职工信息（清空前需要再次确认，防止误删）

## 2、创建项目

创建文件夹名为：基于多态的职工管理系统

## 3、创建管理类

  管理类负责的内容如下：

- 与用户的沟通菜单界面

- 对职工增删改查的操作

- 与文件的读写交互

### 3.1 创建文件

在文件夹下创建workerManager.h和workerManager.cpp文件

### 3.2 头文件的实现

workerManager.h中

```
#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间

class WorkerManager
{
public:
    //构造函数
    WorkerManager();

    //析构函数
    ~WorkerManager();
};
```

### 3.3 源文件的实现

workerManager.cpp中

```
#include "workerManager.h"

WorkerManager::WorkerManager()
{
}

WorkerManager::~WorkerManager()
{
}
```



## 4、菜单功能

功能描述：与用户的沟通界面

### 4.1 添加成员函数

在管理类workerManager.h中添加成员函数void Show_Menu();

```
#pragma once//防止头文件重复包含
#include <iostream>//包含输入输出流头文件
using namespace std;//使用标准命名空间

class WorkerManager
{
public:
    //构造函数
    WorkerManager();

    //展示菜单
    void Show_Menu();

    //析构函数
    ~WorkerManager();
};
```

### 4.2菜单功能实现

在管理类workerManager.cpp中实现Show_Menu()函数

```
void WorkerManager::Show_Menu()
{
    cout << "************************************" << endl;
    cout << "******** 欢迎使用职工管理系统！ ******" << endl;
    cout << "**********  0.退出管理程序  *********" << endl;
    cout << "**********  1.退出管理程序  *********" << endl;
    cout << "**********  2.显示职工信息  *********" << endl;
    cout << "**********  3.删除离职职工  *********" << endl;
    cout << "**********  4.修改职工信息  *********" << endl;
    cout << "**********  5.查找职工信息  *********" << endl;
    cout << "**********  6.按照编号排序  *********" << endl;
    cout << "**********  7.清空所有文档  *********" << endl;
    cout << "************************************" << endl;
    cout << endl;
}
```

## 5、退出功能

### 5.1 提供功能接口

在main函数中提供分支选择，提供每个功能接口

职工管理系统-代码：

```
#include <iostream>
using namespace std;
#include "workerManager.cpp"

int main()
{

    // 实例化管理者对象
    WorkerManager wm;
    int choice = 0;
    while (true)
    {
        //展示菜单
        wm.Show_Menu();
        cout << "请输入您的选择:" << endl;
        cin >> choice;
        switch (choice)
        {
        case 0: //退出系统
            wm.exitSystem();
            break;
        case 1: //添加职工
            break;
        case 2: //显示职工
            break;
        case 3: //删除职工
            break;
        case 4: //修改职工
            break;
        case 5: //查找职工
            break;
        case 6: //排序职工
            break;
        case 7: //清空文件
            break;
        default:
            // system("pause");7
            exit(0);
        }
    }

    return 0;
}
```

### 5.2 实现退出功能

在workerManager.h中提供退出系统的成员函数 void exitSystem();

在workerManager.cpp中提供具体的功能实现

```
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}
```



