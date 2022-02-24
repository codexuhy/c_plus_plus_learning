#include <iostream>
using namespace std;

int main(){

    // 提示用户输入一个高考分数，根据分数做如下判断
    // 分数如果大于600 视为一本
    // 分数如果大于500 视为二本
    // 分数如果大于400 视为三本
    // 其余。视为未考上本科
    // 在一本分数中，
        //如果大于700，考入北大，
        //如果大于650，考入清华
        //如果大于600，考入人大

    int score = 0;
    cout << "请输入高考考试分数：" << endl;
    cin >> score;
    cout << "您输入的分数为: " << score << endl;
    if (score >600)
    {
        cout << "恭喜您考入一本大学" << endl;
        if (score > 700)
        {
            cout << "您能考入北京大学" << endl; 
        }
        else if(score > 650)
        {
            cout << "您能考入清华大学" << endl; 
        }
        else if(score > 600)
        {
            cout << "您能考入中国人民大学" << endl; 
        }
    }
    else if (score >500)
    {
        cout << "恭喜您考入二本大学" << endl;
    }
    else if (score >400)
    {
        cout << "恭喜您考入一本大学" << endl;
    }
    else
    {
        cout << "您未考上本科，请再接再厉" << endl;
    }
    return 0;
}