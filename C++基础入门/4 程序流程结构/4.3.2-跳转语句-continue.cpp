#include <iostream>
using namespace std;

int main(){

    //continue 语句
    for (int i = 0;i <= 100;i++)
    {
        //如果是奇数输出 偶数不输出
        if (i % 2 == 0)
        {
            continue;
            //break 会退出循环 continue 不会
        }
        cout << i << endl;
    }
    return 0;
}