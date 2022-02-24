#include <iostream>
using namespace std;
#include<stdlib.h>

/*
    rand（产生随机数）
    表头文件: #include<stdlib.h>
    定义函数 :int rand(void)

    函数说明 :
    因为rand() 的内部实现是用线性同余法做的，它不是真的随机数，只不过是因为其周期特别长，所以有一定的范围里可看成是随机的，
    rand() 会返回一随机数值，范围在 0 至 RAND_MAX 间。
    在调用此函数产生随机数前，必须先利用 srand()设置好随机数种子，如果未设随机数种子，rand()在调用时会自动设随机数种子为 1。
    rand()产生的是假随机数字，每次执行时是相同的。若要不同,以不同的值来初始化它.初始化的函数就是 srand()。
*/

int main(){

    /*
        案例描述：
        系统随机生成一个1到100之间的数字，玩家进行猜测,如果猜错，提示玩家数字过大或过小，
        如果猜对恭喜玩家胜利，并且退出游戏。
    */
    
    //添加随机数种子，作用利用当前系统时间生成随机数，防止每次随机数都一样
    srand((unsigned int) time (NULL));
    
    //1、系统生成随机数
    int num = rand() % 100 + 1; //rand() % 100 + 1 生成 0+1~99+1随机数
    cout << num << endl;
    
    while(1)
    {
        //2、玩家进行猜测
        int val = 0;
        cin >> val;
        
        //3、判断玩家的猜测50
        if(val > num)
        {
            cout << "猜测过大" << endl;
        }
        else if(val < num)
        {
            cout << "猜测过小" << endl;
        }
        else
        {
            cout << "猜对啦" << endl;
            break;
        }
    }

    //猜对 退出游戏
    // 猜错 提示猜的结果 过大或者过小 重新返回第2步




    
    return 0;
}