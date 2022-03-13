#include<iostream>
using namespace std;
#include<fstream>
//文本文件 读文件

int main(){
    // 1、包含头文件

    // 2、创建流对象
    ifstream ifs;

    //3、打开文件，并且判断是否打开成功
    ifs.open("test.txt",ios::in);

    if (! ifs.is_open()){
        cout << "文件打开失败" << endl;
    }

    //4、写入数据

    //第一种
    // char buf[1024] = {0};
    // while (ifs >> buf)
    // {
    //     cout << buf << endl;
    // }

    //第二种
    // char buf[1024] = {0};//以数组形式初始化buf
    // while (ifs.getline(buf,sizeof(buf)))//（指向的地址：buf是数组首地址,文件大小）
    // {
    //     cout << buf << endl;
    // }

    //第三种
    // string buf;
    // while(getline(ifs,buf))
    // {
    //     cout << buf << endl;
    // }

    //第四种(不建议使用按字符读，较慢)
    char c;
    while((c = ifs.get()) != EOF)//EOF end od file
    {
        cout << c;
    }

    return 0;
}