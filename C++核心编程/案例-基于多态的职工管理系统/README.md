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

## 6、创建职工类

### 6.1 创建职工抽象类

职工的分类为：普通员工、经理、老板

将三种职工抽象到一个类（worker）中，利用多态管理不同职工种类

职工的属性为：职工编号、职工姓名、职工所在的部门编号

职工的行为为：岗位职责信息描述，获取岗位名称



头文件文件夹下 创建文件worker.h 文件并且添加如下代码：

```
#pragma once
#include <iostream>
#include <string>
using namespace std;

//职工抽象基类
class Worker
{
public:
    //显示个人信息
    virtual void showInfo() = 0;
    //获取岗位名称
    virtual string getDeptName() = 0;

    int m_Id;      //职工编号
    string m_Name; // 职工姓名
    int m_DeptId;  // 职工所在部门名称编号
};
```

### 6.2 创建普通员工类

普通员工类继承职工抽象类，并重写父类中的虚函数

在头文件和源文件的文件夹下分别创建employeee.h和employee.cpp文件



employee.h代码如下：

```
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

//员工类
class Employee : public Worker
{
public:
    //构造函数
    Employee(int id, string name, int dId);

    //显示个人信息
    virtual void showInfo();

    //获取职工岗位名称
    virtual string getDeptName();
};
```

employee.cpp中代码如下：

```
#include "employee.h"

Employee::Employee(int id,string name,int dId){
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Employee::showInfo(){
    cout << "职工编号："<< this->m_Id
    << "\t职工姓名："<< this->m_Name
    <<"\t岗位："<< this->getDeptName()
    << "\t岗位职责:完成经理交给的任务" << endl;
}

string Employee::getDeptName(){
    return string("员工");
}
```

### 6.3 创建经理类

经理类继承职工抽象类，并重写父类中纯虚函数，和普通员工类似在头文件和源文件的文件夹下分别创建manager.h和manager.cpp文件



manager.h中代码如下：

```
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Manager : public Worker
{
public:
    Manager(int id, string name, int dId);

    //显示个人信息
    virtual void showInfo();

    //获取职工岗位名称
    virtual string getDeptName();
};
```

manager.cpp中代码如下

```
#include "manager.h"

Manager::Manager(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Manager::showInfo()
{
    cout << "职工编号: " << this->m_Id
         << "\t职工姓名：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位职责：完成老板交给的任务，并下发任务给员工" << endl;
}

string Manager::getDeptName()
{
    return string("经理");
}
```

### 6.4 创建老板类

老板类继承职工抽象类，并重写父类中纯虚函数，和普通员工类似在头文件和源文件的文件夹下分别创建boss.h

和boss.cpp文件



boss.h代码如下：

```
#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

class Boss : public Worker
{
    Boss(int id, string name, int dId);

    //显示个人信息
    virtual void showInfo();

    //获取职工岗位名称
    virtual string getDeptName();
};
```

boss.cpp代码如下：

```
#include "boss.h"

Boss::Boss(int id, string name, int dId)
{
    this->m_Id = id;
    this->m_Name = name;
    this->m_DeptId = dId;
}

void Boss::showInfo()
{
    cout << "职工编号：" << this->m_Id
         << "\t职工编号：" << this->m_Name
         << "\t岗位：" << this->getDeptName()
         << "\t岗位职责：管理公司所有事务" << endl;
}

string Boss::getDeptName()
{
    return string("总裁");
}
```

### 6.5 测试多态

在职工管理系统.cpp中添加测试函数，并且运行能够产生多态

测试代码如下：

```
#include "worker.h"
#include "employee.h" //(此位置若报错改成employee.cpp,下面同理)
#include "manager.h"
#include "boss.h"

void test(){
    Worker * worker = NULL;
    worker = new Employee(1,"张三",1);
    worker->showInfo();
    delete worker;

    worker = new Manager(2,"李四",2);
    worker->showInfo();
    delete worker;

    worker = new Boss(3,"王五",3);
    worker->showInfo();
    delete worker;
}
```

测试完成后，可删除测试代码，恢复原来的代码

## 7、添加职工

功能描述：批量添加职工，并且保存到文件中

### 7.1 功能分析

分析：

用户在批量创建时，可能会创建不同种类的员工

如果想将不同种类的员工都放入到一个数组中，可以将所有员工的指针维护到一个数组里

如果想在程序中维护这个不定长度的数组，可以将数组创建到堆区，并利用worker**的指针维护

| new Employee | new Boss | new Employee | new Manager | new Employee |
| ------------ | -------- | ------------ | ----------- | ------------ |
| worker *     | worker * | worker *     | worker *    | worker *     |

### 7.2 功能实现

在WorkerManager.h头文件中添加成员属性 代码：

```C++
    //记录文件中的人数个数
    int m_EmpNum;
    //员工数组的指针
    Worker ** = m_EmpArray;
```

在WorkerManager构造函数中初始化属性

```
WorkerManager::WorkerManager()
{
    //初始化人数
    this->m_EmpNum = 0;

    //初始化数组指针
    this->EmpArray = NULL;
}
```

在workerManager.h中添加成员函数

```
	//增加职工
	void Add_Emp();
```

在WorkerManager.cpp中实现该函数

```
	//增加职工
void WorkerManager::Add_Emp()
{
    cout << "请输入增加职工的数量：" << endl;

    int addNum = 0; //保存用户的输入数量
    cin >> addNum;

    if (addNum > 0)
    {
        //添加
        //计算新空间大小
        int newSize = this->m_EmpNum + addNum;

        //开辟新空间
        Worker **newSpace = new Worker *[newSize];

        //将原空间下的内容存放到新空间下
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        //批量添加新数据
        for (int i = 0; i < addNum; i++)
        {
            int id;      //职工编号
            string name; //姓名
            int dSelect; //部门选择

            cout << "请输入第" << i << i + 1 << "个新职工编号" << endl;
            cin >> id;
            cout << "请输入第" << i << i + 1 << "个新职工姓名" << endl;
            cin >> name;

            cout << "请选择该职工的岗位：" << endl;
            cout << "1、普通职工" << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker *worker = NULL;
            switch (dSelect)
            {
            case 1:
                worker = new Employee(id, name, 1);
                break;
            case 2:
                worker = new Manager(id, name, 2);
                break;
            case 3:
                worker = new Manager(id, name, 3);
            default:
                break;
            }

            newSpace[this->m_EmpNum + i] = worker;

            //释放原有空间
            delete[] this->m_EmpArray;

            //更改新空间的指向
            this->m_EmpArray = newSpace;

            //提示添加成功
            cout << "成功添加" << addNum << "名新职工" << endl;
        }
    }
    else
    {
        cout << "输入有误" << endl;
    }
}
```

### 7.3 测试

在职工管理系统.cpp中添加测试函数,

```
#include "worker.h"

#include "employee.cpp"

#include "manager.cpp"

#include "boss.cpp"

wm.Add_Emp();
```

## 8、文件交互-写文件

功能描述：对文件进行读写

​	在上一个添加功能中，我们只是将所有的数据添加到了内存中，一旦程序结束就无法保存了

​	因此文件管理中需要一个与文件进行交互的功能，对于文件进行读写操作

### 8.1 设定文件路径

首先我们将文件路径，在workerManager.h中添加宏常量，并且包含头文件fstream

```
#include <iostream>
#define FILENAME "empFile.txt"
```



### 8.2 成员函数声明

在workerManager.h中类里添加成员函数void save()

```
// 保存文件
void save();
```

### 8.3保存文件功能实现

```
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out);

    for (int i = 0;i < this->m_EmpNum;i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}
```

## 9、文件交互 - 读文件

功能描述：将文件中的内容读取到程序中

虽然我们实现了添加职工后保存到文件的操作，但是每次开始运行程序，并没有将文件中数据读取到程序中

而我们的程序功能中还有清空文件的需求

因此构造函数初始化数据的情况分为三种

1.第一次使用，文件未创建

2.文件存在，但是数据被用户清空

3.文件存在，并且保存职工的所有数据

### 9.1 文件未创建

在workerManager.h中添加新的成员属性m_FileEmpty标志文件是否为空

```C++
	// 标志文件是否为空
	bool m_FileIsEmpty;
```

 修改workerManager.cpp中构造函数代码

```C++
WorkerManager::WorkerManager()
{

    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    //文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl; // 测试输出
        this->m_EmpNum = 0; // 初始化人数
        this->m_FileIsEmpty = true; //初始化文件为空标志
        this->m_EmpArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }
    
}
```

删除文件后，测试文件不存在时初始化数据功能



### 9.2 文件存在且数据为空

在workerManager.cpp中的构造函数追加代码：

```C++
	//文件存在，并且没有记录
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        cout << "文件为空！" << endl;
        this->m_EmpNum = 0; // 初始化人数
        this->m_FileIsEmpty = true; //初始化文件为空标志
        this->m_EmpArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }
```

将文件创建后清空文件内容，并测试该情况下初始化功能



我们发现文件不存在或者为空清空m_FileIsEmpty判断文件是否为空的标志，那何时为假？

成功添加职工后，应该更改文件不为空的标志

在viod workerManager::Add_Emp()成员函数中添加：

```C++
	//更新职工不为空标志
	this->m_FileISEmpty = false;
```

### 9.3文件存在且保存职工数据

#### 9.3.1 获取记录的职工人数

在workerManager.h中添加成员函数 int get_EmpNum();

```C++
	// 统计人数
	int get_EmpNum;
```

workerManager.cpp中实现

```C++
int WorkerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    int id;
    string name;
    int dId;

    int num = 0;

    while(ifs >> id && ifs >> name && ifs >> dId)
    {
        //记录人数
        num++;
    }
    ifs.close();
    return num;
}
```

在workerManager.cpp构造函数中继续追加代码：

```C++
    int num = this->get_EmpNum();
    cout << "职工个数为：" << num << endl; //测试代码
    this->m_EmpNum = num; // 更新成员属性
```

手动添加一些职工数据(empFile.txt)，测试获取职工数量函数

```txt
1   张三    1
2   李四    2
3   王五    3
```

