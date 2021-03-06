#include <iostream>
using namespace std;
#include <string>

// string的构造函数
/*
- string()                      //创建一个空的字符串 例如：string str;
  string(const char* s);        //使用字符串初始化
- string(const string& str);    // 使用一个string对象初始化另一个string对象
- string(int n,char c);\t\t     //使用n个字符初始化
*/
void test01()
{
    string s1; //默认构造

    const char *str = "hello world";
    string s2(str); //有参构造
    string s3(s2);  //拷贝构造
    string s4(10, 'a');

    cout << "s2= " << s2 << endl;
    cout << "s3= " << s3 << endl;
    cout << "s4= " << s4 << endl;
}

int main()
{
    test01();

    return 0;
}
