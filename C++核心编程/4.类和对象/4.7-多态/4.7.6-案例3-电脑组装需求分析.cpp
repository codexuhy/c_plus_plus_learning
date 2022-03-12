#include <iostream>
using namespace std;
/*
    电脑主要部件：CPU(用于计算),显卡(用于显示),内存条(用于存储)
    将每个零件封装成基类，并提供不同的厂商生产不同的零件，例如：Intel厂商和Lenovo厂商
    创建电脑类提供让电脑工作的函数，并且调用每个零件的工作接口
    测试时组装三台不同的电脑进行工作

*/
class CPU
{
public:
    //抽象计算函数
    virtual void calculate() = 0;
};

class VideoCard
{
public:
    //抽象显示函数
    virtual void display() = 0;
};

class Memory
{
public:
    //抽象存储函数
    virtual void storage() = 0;
};

//电脑类
class Computer
{
public:
    //构造函数中传入三个零件指针
    Computer(CPU *cpu, VideoCard *vc, Memory *mem)
    {
        m_cpu = cpu;
        m_vc = vc;
        m_mem = mem;
    }
    //提供析构函数 释放3个电脑零件
    ~Computer()
    {
        //释放CPU
        if (m_cpu != NULL)
        {
            delete m_cpu;
            m_cpu = NULL;
        }
        // 释放显卡零件
        if (m_vc != NULL)
        {
            delete m_vc;
            m_vc = NULL;
        }
        // 释放内存条零件
        if (m_mem != NULL)
        {
            delete m_mem;
            m_mem = NULL;
        }
    }
    //提供工作的函数
    void work()
    {
        //调用每个零件接口
        m_cpu->calculate();
        m_vc->display();
        m_mem->storage();
    }

private:
    CPU *m_cpu;      // CPU零件接口
    VideoCard *m_vc; //显卡零件接口
    Memory *m_mem;   //内存零件接口
};
//具体零件厂商
// Intel
class IntelCPU : public CPU
{
public:
    void calculate()
    {
        cout << "Intel的CPU开始计算了！" << endl;
    }
};

class IntelVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Intel的显卡开始显示了！" << endl;
    }
};

class IntelMemory : public Memory
{
public:
    void storage()
    {
        cout << "Intel的内存开始存储了！" << endl;
    }
};
// Lenovo
class LenovoCPU : public CPU
{
public:
    void calculate()
    {
        cout << "Lenovo的CPU开始计算了！" << endl;
    }
};

class LenovoVideoCard : public VideoCard
{
public:
    void display()
    {
        cout << "Lenovo的显卡开始显示了！" << endl;
    }
};

class LenovoMemory : public Memory
{
public:
    void storage()
    {
        cout << "Lenovo的内存开始存储了！" << endl;
    }
};

void test01()
{
    //创建三个零部件
    CPU *intel_Cpu = new IntelCPU;
    VideoCard *intel_Vc = new IntelVideoCard;
    Memory *intel_mem = new IntelMemory;
    //创建一台电脑
    cout << "------------创建第一台电脑----------" << endl;
    Computer *computer1 = new Computer(intel_Cpu, intel_Vc, intel_mem);
    computer1->work();
    delete computer1;

    //创建第二台电脑
    cout << "------------创建第二台电脑----------" << endl;
    Computer *computer2 = new Computer(new LenovoCPU, new LenovoVideoCard, new LenovoMemory);
    computer2->work();
    delete computer2;

    //创建第三台电脑
    cout << "------------创建第三台电脑----------" << endl;
    Computer *computer3 = new Computer(new IntelCPU, new LenovoVideoCard, new LenovoMemory);
    computer3->work();
    delete computer3;
}
int main()
{
    test01();
    return 0;
}