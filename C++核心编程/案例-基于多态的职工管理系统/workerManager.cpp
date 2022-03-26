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
        // cout << "文件不存在" << endl; // 测试输出
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
        // cout << "文件为空！" << endl;
        this->m_EmpNum = 0; // 初始化人数
        this->m_FileIsEmpty = true; //初始化文件为空标志
        this->m_EmpArray = NULL; //初始化数组
        ifs.close(); //关闭文件
        return;
    }

    // 3、文件存在，并且记录数据
    int num = this->get_EmpNum();
    // cout << "职工个数为：" << num << endl; //测试代码
    this->m_EmpNum = num; // 更新成员属性

    //根据职工数创建数组(开辟空间)
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    //初始化职工(将文件中的员工，初始化到数组中)
    init_Emp();

    //测试代码
    // for (int i = 0;i < m_EmpNum;i++)
    // {
    //     cout << "职工号：" << this->m_EmpArray[i]->m_Id
    //         << "职工姓名：" << this->m_EmpArray[i]->m_Name
    //         << "部门编号：" << this->m_EmpArray[i]->m_DeptId << endl;
    // }


    
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

void WorkerManager::init_Emp()
{
    ifstream ifs;
    ifs.open(FILENAME,ios::in);
    
    int id;
    string name;
    int dId;
    
    int index = 0;
    while(ifs >> id && ifs >> name && ifs >> dId)
    {
        Worker * worker = NULL;
        //根据不同给的部门Id创建不同对象
        if(dId == 1) // 1普通员工
        {
            worker = new Employee(id,name,dId);
        }
        else if (dId == 2)//2经理
        {
            worker = new Manager(id,name,dId);
        }
        else //3总裁
        {
            worker = new Boss(id,name,dId);
        }
        // 存放在数组中
        this->m_EmpArray[index]  = worker;
        index++;
    }
}


// 显示职工
void WorkerManager::Show_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        for (int i = 0; i < m_EmpNum;i++)
        {
            //利用多态调用接口
            this->m_EmpArray[i]->showInfo();
        }
    }
}

// 删除职工
void WorkerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空" << endl;
    }
    else
    {
        //按照编号删除职工
        cout << "请输入想要删除职工编号：" << endl;
        int id = 0;
        cin >> id;

        int index = this->IsExist(id);

        if (index != -1) //说明职工存在，并且要删除掉index位置上的职工
        {
            
            for (int i = index;i < this->m_EmpNum - 1;i++)
            {
                //数据前移
                this->m_EmpArray[i] = this->m_EmpArray[i+1];
            }
            this->m_EmpNum--;//更新数组中记录人员个数
            //数据同步到文件
            this->save();

            cout << "删除成功！" << endl;
        }
        else
        {
            cout << "删除失败,未找到该职工" << endl;
        }
    }
}

//判断职工是否存在 如果存在返回职工所在数组中的位置，不存在返回-1
int WorkerManager::IsExist(int id)
{
    int index = -1;
    for (int i = 0;i < this->m_EmpNum;i++)
    {
        if (this->m_EmpArray[i]->m_Id == id)
        {
            //找到职工
            index = i;
            break;
        }
    }
    return index;
}

//修改职工
void WorkerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或记录为空！" << endl;
    }
    else
    {
        cout << "请输入修改职工的编号：" << endl;
        int id;
        cin >> id;

        int ret = this-> IsExist(id);
        if (ret != -1)
        {
            //查找到编号的职工
            delete this->m_EmpArray[ret];

            int newId = 0;
            string newName = "";
            int dSelect = 0;

            cout << "查到：" << id << "号职工，请输入新职工号：" << endl;
            cin >> newId;

            cout << "请输入新姓名：" << endl;
            cin >> newName;

            cout << "请输入岗位：" << endl;
            cout << "1、普通职工"  << endl;
            cout << "2、经理" << endl;
            cout << "3、老板" << endl;
            cin >> dSelect;

            Worker * worker = NULL;
            switch (dSelect)
            {
                case 1:
                    worker = new Employee(newId,newName,dSelect);
                    break;
                case 2:
                    worker = new Employee(newId,newName,dSelect);
                    break;
                case 3:
                    worker = new Boss(newId,newName,dSelect);
                    break;
                default:
                    break;
            }

            // 更改数据到数组中
            this->m_EmpArray[ret] = worker;

            cout << "修改成功！ " << this->m_EmpArray[ret]->m_DeptId << endl;

            //保存到文件中
            this->save();
        }
        else
        {
            cout << "修改失败，查无此人" << endl;
        }
    }
}