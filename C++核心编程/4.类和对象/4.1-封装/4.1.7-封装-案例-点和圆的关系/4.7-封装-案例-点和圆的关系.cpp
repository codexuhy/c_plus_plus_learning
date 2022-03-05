#include<iostream>
using namespace std;
#include "point.cpp"
#include "circle.cpp"
/*
    案例：点和圆的关系
*/

// 点类
// class Point{
// public:
//     void setX(int x){
//         c_X = x;
//     }

//     int getX(){
//         return c_X;
//     }

//     void setY(int y){
//         c_Y = y;
//     }

//     int getY(){
//         return c_Y;
//     }

// private:
//     int c_X;
//     int c_Y;
// };


// 圆类
// class Circle{

// public:
//     void setR(int r){
//         m_R = r;
//     }
//     int getR(){
//         return m_R;
//     }

//     void setCenter(Point center){
//        m_Center = center;
//     }

//     Point getCenter(){
//         return m_Center;
//     }

// private:
//     int m_R;//半径
//     // 在类中可以让另一个类 作为本来的成员
//     Point m_Center;//圆心 
// };

void isInCircle(Circle &c,Point &p){
    //计算两点之间距离 平方
    int distance = 
        (c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) +
        (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY());
    //计算半径的平方
    int rDistance = c.getR() * p.getX();
    cout << c.getCenter().getX() << "," << c.getCenter().getY() << endl;
    cout << p.getX() << "," << p.getX() << endl;
    cout << c.getR() << endl;
    if (distance == rDistance)
    {
        cout << "点在圆上" << endl;
    }
    else if (distance > rDistance){
        cout << "点在圆外" << endl;
    }
    else{
        cout << "点在圆内" << endl;
    }


}

int main(){
    
    //创建圆
    Circle c1;
    c1.setR(10);
    Point center;
    center.setX(10);
    center.setY(0);
    c1.setCenter(center);

    //创建点
    Point point;
    point.setX(10);
    point.setY(10);

    isInCircle(c1,point);

    return 0;

}