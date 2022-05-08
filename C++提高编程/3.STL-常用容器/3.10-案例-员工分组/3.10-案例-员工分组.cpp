#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <map>
#include <ctime>
#define CHEHUA 0
#define MEISHU 1
#define YANFA 2
/*
### 3.10.1 案例描述
- 公司今天招聘了10个员工(ABCDEFGHIJ),10名员工进入公司之后，需要指派员工在哪个部门工作
- 员工信息有：姓名 工资组成：部门分为：策划、美术、研发
- 随机给10名员工分配部门和工资
- 通过multimap进行信息的插入、key(部门编号) value(员工)
- 分部门显示员工信息

### 3.10.2 实现步骤
1. 创建10名员工，放到vector中
2. 遍历vector容器，取出每个员工，进行随机分组
3. 分组后，将员工部门编号作为key，具体员工作为value，放到multimap容器中
4. 分部门显示员工信息
*/
class Worker
{
public:
    Worker(string name, int salary)
    {
        this->m_Name = name;
        this->m_Salary = salary;
    }
    string m_Name;
    int m_Salary;
};

void createWorker(vector<Worker> &v)
{
    string nameSeed = "ABCDEFGHIJ";
    for (int i = 0; i < 10; i++)
    {
        string name = "员工";
        name += nameSeed[i];
        int m_Salary;
        m_Salary = rand() % 10000 + 10000;
        Worker p(name, m_Salary);

        //将创建的Worker对象放到vector中
        v.push_back(p);
    }
}

void showSalary(vector<Worker> &v)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << "姓名：" << it->m_Name << " 薪资：" << (*it).m_Salary << endl;
    }
}

void setGroup(vector<Worker> &v, multimap<int, Worker> &m)
{
    for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
    {
        int depthId = rand() % 3; // 0 1 2
        //将员工插入到分组中
        // key 部门编号 value 具体员工
        m.insert(make_pair(depthId, *it));
    }
}

void showWorkerByGroup(multimap<int, Worker> &m)
{
    cout << "策划部门：" << endl;
    map<int, Worker>::iterator pos = m.find(CHEHUA);
    int count = m.count(CHEHUA);
    int index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "薪资：" << pos->second.m_Salary << endl;
    }

    cout << "美术部门：" << endl;
    pos = m.find(MEISHU);
    count = m.count(MEISHU);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "薪资：" << pos->second.m_Salary << endl;
    }

    cout << "研发部门：" << endl;
    pos = m.find(YANFA);
    count = m.count(YANFA);
    index = 0;
    for (; pos != m.end() && index < count; pos++, index++)
    {
        cout << "姓名：" << pos->second.m_Name << "薪资：" << pos->second.m_Salary << endl;
    }
}
void test01()
{
    //利用系统时间做一个真实的随机
    srand((unsigned int)time(NULL));
    // 1.创建worker
    vector<Worker> vWorker;
    createWorker(vWorker);
    showSalary(vWorker); //测试使用
    // 2.员工分组
    multimap<int, Worker> mWorker;
    setGroup(vWorker, mWorker);
    showWorkerByGroup(mWorker);
}

int main()
{

    test01();

    return 0;
}