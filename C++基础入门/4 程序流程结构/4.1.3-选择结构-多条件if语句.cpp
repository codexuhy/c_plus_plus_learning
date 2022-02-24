#include <iostream>
using namespace std;

int main(){
    //判断
    //如果分数大于600，则考上一本大学,
    //如果分数大于500，则考上二本大学,
    //如果分数大于400，则考上三本大学,
    //否则未考上本科
    int score = 0;
    cout << "请输入考试分数：" << endl;
    cin >> score;
    if (score > 600)
    {
        cout << "恭喜你考上一本大学" << endl;
    }
    else if (score > 500)
    {
        cout << "恭喜你考上二本大学" << endl;
    }
    else if (score > 400)
    {
        cout << "恭喜你考上三本大学" << endl;
    }
    else
    {
        cout << "您未考上本科,请再接再厉" << endl;
    }


}