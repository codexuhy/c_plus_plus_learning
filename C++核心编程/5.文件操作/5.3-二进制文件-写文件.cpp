#include <iostream>
using namespace std;
#include <fstream> //包含头文件
/*
    写文件
        二进制写文件主要利用流对象调用成员函数write
        函数原型： ostream& write(const char * buffer，int len);
        参数解释：字符指针buffer指向内存汇总一段存储空间，lne是读写的字节数
*/

class Person
{
public:
    char m_Name[64];
    int m_Age;
};

//二进制文件 写文件
void test01()
{
    // 1、包含头文件

    // 2、创建输出流对象
    ofstream ofs("person.txt", ios::out | ios::binary);
    // 3、打开文件
    //  ofstream ofs;
    //  ofs.open("person.txt",ios::out | ios::binary);

    Person p = {"张三", 18};
    // 4、写文件(文件输出流对象，可以通过write函数，以二进制方式写数据)
    //&p返回的是Person *类型，但是write函数要求的是const char * 所以进行了强转
    ofs.write((const char *)&p, sizeof(p));
    // 5、关闭文件
    ofs.close();
}
int main()
{
    test01();

    return 0;
}