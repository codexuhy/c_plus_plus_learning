#include <iostream>
using namespace std;

int main(){


    //案例：找出一维数组的最大值
    int arr[5] = {300,350,200,400,250};
    int len = sizeof(arr) / sizeof(arr[0]);
    int max = 0;
    for (int i = 0; i< len;i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    cout << "数组最大值为：" << max << endl;
    return 0;
}