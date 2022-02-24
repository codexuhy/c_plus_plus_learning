#include <iostream>
using namespace std;

int main(){

    //三只小猪称重
    // 有三只小猪，分别输入三只小猪体重，并判断哪只小猪最重？
    
    //1.赋初始体重
    int num1 = 0;
    int num2 = 0;
    int num3 = 0;

    //2.输入三只三种体重
    cout <<"请输入A小猪的体重：" << endl;
    cin >> num1;
    cout <<"请输入B小猪的体重：" << endl;
    cin >> num2;
    cout <<"请输入C小猪的体重：" << endl;
    cin >> num3;

    //3.判断哪只最重
    // 先判断A和B重量
    if (num1 > num2) //A比B重
    {
        if (num1 >num3)
        {
            cout << "最重的小猪是A：" << num1 << endl;
        }
        else
        {
            cout << "最重的小猪是C：" << num3 << endl;
        }

    }
    else{
        if (num2 >num3)
        {
            cout << "最重的小猪是B：" << num2 << endl;
        }
        else
        {
            cout << "最重的小猪是C：" << num3 << endl;
        }
    }


    return 0;
}