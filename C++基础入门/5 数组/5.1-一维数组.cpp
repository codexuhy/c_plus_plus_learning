# include <iostream>
using namespace std;

int main(){
    
    /*
        数组特点： 
            放在一块连续的内存空间
            数组中每个元素都是相同的数据类型

    */

    /*
        1. 数据类型  数组名[数组长度];
        2. 数据类型  数组名[数组长度] = {值1，值2，...}
        3. 数据类型  数组名[ ] = {值1，值2，...}

    */

    //1.数据类型 数组名[元素个数]
    int score[10];

    //利用下标赋值
    score[0] = 100;
    score[1] = 99;

    // 访问数据元素
    // cout << score[0] << endl;
    // cout << score[1] << endl;


    //2.数据类型  数组名[数组长度] = {值1，值2，...}
    // 如果初始化数据时，没有全部填写完，全部用0来填补剩余数据
    int arr2[5] = {10,20,30};
    // cout << arr2[0] << endl;
    // cout << arr2[1] << endl;
    //利用循环 输出数组中的元素
    // for (int i = 0; i < 5;i++)
    // {
    //     cout << arr2[i] << endl;
    // }


    //3.  数据类型  数组名[ ] = {值1，值2，...}
    // 定义数组的时候，必须有初始的长度
    int arr3[] = {90,80,70,60,50};
    
    return 0;
}