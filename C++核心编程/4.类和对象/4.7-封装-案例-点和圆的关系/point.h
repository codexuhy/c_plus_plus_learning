#pragma once//防止头文件重包含
#include<iostream>
using namespace std;


// 点类
class Point{
public:
    void setX(int x);

    int getX();

    void setY(int y);

    int getY();

private:
    int c_X;
    int c_Y;
};