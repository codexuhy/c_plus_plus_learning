#include <iostream>
using namespace std;

/*
    案例：
        制作饮品的大致流程为:煮水，冲泡，倒入杯中，加入辅料
    利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
*/
class AbstractDrinking
{
public:
    virtual void Boil() = 0;
    virtual void Brew() = 0;
    virtual void PourInCup() = 0;
    virtual void PutSomething() = 0;
    void makeDrink(){
        Boil();
        Brew();
        PourInCup();
        PutSomething();
    }

};

class Coffee:public AbstractDrinking{
    void Boil()
    {
        cout << "煮农夫山泉" << endl;
    }
    void Brew(){
        cout << "冲泡咖啡" << endl;
    }
    void PourInCup(){
        cout << "倒入杯中" << endl;
    }
    void PutSomething(){
        cout << "加些牛奶和糖" << endl;
    }
};

//制作茶叶
class Tea:public AbstractDrinking{
    void Boil()
    {
        cout << "煮矿泉水" << endl;
    }
    void Brew(){
        cout << "冲泡茶叶" << endl;
    }
    void PourInCup(){
        cout << "倒入杯中" << endl;
    }
    void PutSomething(){
        cout << "加些枸杞" << endl;
    }
};

void doWork(AbstractDrinking * abs){ //AbstractDrinking * abs = new Coffee
    abs->makeDrink();
    delete abs; //将堆区数据手动释放，防止内存泄漏
}

void test01(){
    doWork(new Coffee);
    cout << "------" << endl;
    doWork(new Tea);
}

int main()
{
    test01();

    return 0;
}