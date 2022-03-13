#include <iostream>
using namespace std;
#include <fstream> //包含头文件
int main()
{

    // 1、包含头文件
    // 2、创建流对象
    ofstream ofs;
    // 3、打开文件
    ofs.open("test.txt", ios::out);
    // 4、写内容
    ofs << "姓名：张三" << endl;
    // 5、关闭文件
    ofs.close();

    return 0;
}
