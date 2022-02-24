#include <iostream>
using namespace std;

int main(){

    //输入考试分数，如果分数大于600，则考上一本大学,否则未考上一本大学

    int score = 0;

    cout << "请输入考试分数：" << endl;

    cin >> score;

    if (score > 600)
    {
        cout << "我考上了一本大学" << endl;
    }
    else
    {
        cout << "我未考上一本大学" << endl;
    }
    
    return 0;
}