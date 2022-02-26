#include<iostream>
using namespace std;
// 案例描述，封装一个函数,利用冒泡排序，实现对整型数组的升序排序

void bubbleSort(int * arr,int len)
{
    for (int i = 0 ;i < 10;i++)
    {
        for(int j = 0 ;j < 10-i-1 ;j++)
        {
            if (arr[j+1] < arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


void printArr(int * arr,int len)
{
    cout << "打印数组" << endl;
    for (int i = 0; i< 10;i++)
    {
        cout << arr[i] << endl;
    }
}
int main(){

    int arr[10] = {4,3,6,9,1,2,10,8,7,5};
    int len = sizeof(arr) - sizeof(arr[0]);
    bubbleSort(arr,len);
    printArr(arr,len);

    return 0;
}