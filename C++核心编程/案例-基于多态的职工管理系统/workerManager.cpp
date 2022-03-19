#include "workerManager.h"
#include "stdlib.h"
WorkerManager::WorkerManager()
{
    // //初始化人数
    // this->m_EmpNum = 0;

    // //初始化数组指针
    // this->m_EmpArray = NULL;

    ifstream ifs;
    ifs.open(FILENAME,ios::in);

    //1、文件不存在情况
    if (!ifs.is_open())
    {
        cout << "文件不存在" << endl; // 测试输出
        this->m_EmpNum = 0; // 初始化人数
        this->m_FileIsEmpty = true; //初始化文件为空标志
        this->m_EmpArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }

    //2、文件存在，并且没有记录
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

    // 3、文件存在，并且记录数据
    int num = this->get_EmpNum();
    cout << "职工个数为：" << num << endl; //测试代码
    this->m_EmpNum = num; // 更新成员属性
    
}

WorkerManager::~WorkerManager()
{
}

void WorkerManager::Show_Menu()
{
    cout << "************************************" << endl;
    cout << "******** 欢迎使用职工管理系统！ ******" << endl;
    cout << "**********  0.退出管理程序  *********" << endl;
    cout << "**********  1.增加职工程序  *********" << endl;
    cout << "**********  2.显示职工信息  *********" << endl;
    cout << "**********  3.删除离职职工  *********" << endl;
    cout << "**********  4.修改职工信息  *********" << endl;
    cout << "**********  5.查找职工信息  *********" << endl;
    cout << "**********  6.按照编号排序  *********" << endl;
    cout << "**********  7.清空所有文档  *********" << endl;
    cout << "*************************************" << endl;
    cout << endl;
}

//退出系统
void WorkerManager::exitSystem()
{
    cout << "欢迎下次使用" << endl;
    exit(0);
}

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

            //更新职工不为空标志
	        this->m_FileIsEmpty = false;

            //保存数据到文件中
            this->save();
        }
    }
    else
    {
        cout << "输入有误" << endl;
    }
}

// 保存文件功能实现
void WorkerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME,ios::out | ios::trunc); //用输出的方式打开文件 --- 写文件

    // 将每个人数据写入文件中
    for (int i = 0;i < this->m_EmpNum;i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
        << this->m_EmpArray[i]->m_Name << " "
        << this->m_EmpArray[i]->m_DeptId << endl;
    }

    ofs.close();
}


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