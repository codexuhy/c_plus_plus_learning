#include<iostream>
using namespace std;

int main(){


    //利用冒泡排序实现升序序列
    int arr[9] = {4,2,8,0,5,7,1,3,9};
    int count = sizeof(arr) / sizeof(arr[0]);
    cout << "排序前" << endl;

    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }
    
    cout << endl;

    //开始冒泡排序
    // 总共排序轮数 = 元素个数 - 1
    for (int i = 0; i < count;i++)
    {
        //内层循环对比 次数= 元素个数 - 排序轮数- 1
        for (int j = 0;j < count -i -1; j++)
        {
            // 如果第一个数字，比第二个数字大，交换两个数字
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    } 
    cout << "排序后" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << arr[i] << endl;
    }
    
    

    return 0;
}