#include <iostream>
using namespace std;

/*
    案例：设计立方体类
        求出立方体的面积和体积
        分别用全局函数和成员函数判断两个立方体是否相等
    步骤：
        1. 创建立方体类
        2.设计属性
        3.设计行为 获取立方体面积和体积
        4.分别利用全局函数和成员函数  判断两个立方体是否相等
*/

class Cube
{

public:
    void setL(int L)
    {
        m_L = L;
    }

    void setW(int W)
    {
        m_W = W;
    }

    void setH(int H)
    {
        m_H = H;
    }

    int getL()
    {
        return m_L;
    }

    int getW()
    {
        return m_W;
    }

    int getH()
    {
        return m_H;
    }

    //获取立方体的面积
    int calculateS()
    {
        return 2 * m_L * m_H + 2 * m_L * m_W + 2 * m_W * m_H;
    }

    //获取立方体体积
    int calculateV()
    {
        return m_L * m_H * m_W;
    }

    //成员函数
    bool isSameByClass(Cube &c)
    {
        if (m_L == c.getL() && m_W == c.getW() && m_H == c.getH())
        {
            return true;
        }
        return false;
    }

private:
    int m_L;
    int m_W;
    int m_H;
};

//全局函数
bool isSame(Cube &c1, Cube &c2)
{
    if (c1.getL() == c2.getL() && c1.getW() == c1.getW() && c1.getH() == c2.getH())
    {
        return true;
    }
    return false;
}

int main()
{
    Cube c1;
    c1.setL(10);
    c1.setW(10);
    c1.setH(10);

    cout << "c1面积：" << c1.calculateS() << endl;
    cout << "c1体积：" << c1.calculateV() << endl;

    Cube c2;
    c2.setL(10);
    c2.setW(10);
    c2.setH(11);

    cout << "c2面积：" << c2.calculateS() << endl;
    cout << "c2体积：" << c2.calculateV() << endl;

    // 全局函数
    bool ret = isSame(c1, c2);
    if (ret)
    {
        cout << "c1和c2相等" << endl;
    }
    else
    {
        cout << "c1和c2不相等" << endl;
    }
    //成员函数
    bool ret1 = c1.isSameByClass(c2);

    if (ret1)
    {
        cout << "c1和c2相等" << endl;
    }
    else
    {
        cout << "c1和c2不相等" << endl;
    }

    return 0;
}