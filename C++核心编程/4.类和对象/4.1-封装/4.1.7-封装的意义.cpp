#include <iostream>
using namespace std;
/*
    封装的意义
        封装是C++面向对象三大特性之一
        封装的意义：
            - 将属性和行为作为一个整体，表现出生活中的事物
            - 将属性和行为权限控制
        封装的意义一：
            在设计类的时候，属性和行为写在一起，表现事物
        语法： class 类名{ 访问权限：属性  / 行为 };
*/

// 设计一个圆类，求圆的周长
// 圆求周长的公式 2 * PI * 半径

#define PI 3.14
// class 代表设计一个类，类后面紧跟着就是类名称
class Circle
{
    //访问权限
    //公共权限
public:
    //属性
    //半径
    int m_r;

    //行为
    //获取圆的周长
    double caculateZC()
    {
        return 2 * PI * m_r;
    }
};

int main()
{

    //通过圆类 创建具体的圆（对象）
    Circle c1;
    c1.m_r = 10;
    cout << "圆的周长为：" << c1.caculateZC() << endl;
    return 0;
}