#include "point.h"

// 点类

void Point::setX(int x){ //Point::  加上作用域 告诉它是point作用域下的成员函数，不加则识别为全局函数
    c_X = x;
}

int Point::getX(){
    return c_X;
}

void Point::setY(int y){
    c_Y = y;
}

int Point::getY(){
    return c_Y;
}