#pragma once //防止头文件重包含
#include<iostream>
using namespace std;
#include "point.h"

// 圆类
class Circle{

public:
    void setR(int r);
    int getR();

    void setCenter(Point center);

    Point getCenter();

private:
    int m_R;//半径
    // 在类中可以让另一个类 作为本来的成员
    Point m_Center;//圆心 
};