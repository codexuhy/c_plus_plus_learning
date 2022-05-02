#include <iostream>
using namespace std;
#include <string>
/*
- int find(const string& str, int pos = 0)const;      // 查找str第一次出现位置，从pos开始查找
- int find(const char* s, int pos = 0)const;          // 查找s第一次出现位置，从pos开始查找
- int find(const char* s, int pos, int n)const;       //从pos位置查找s的前n个字符第一次位置
- int find(const char c, int pos = 0)const;           // 查找字符c第一次出现位置
- int rfind(const string& str, int pos = npos)const;  //查找str最后一次位置，从pos开始查找
- int rfind(const char* s, int pos = n)const;         // 从pos开始s的前n个字符最后一个位置
- int rfind(const char c, int pos = 0)const;          // 查找字符c最后一次出现的位置
- string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
- string& replace(int pos, int n, const char* s);     //替换从pos开始的n个字符为字符串s
*/

//查找与替换
// 1.查找
void test01()
{
    string str1 = "abcdefgde";
    int pos = str1.find("de");
    if (pos == -1)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "pos = " << pos << endl;
    }
    //rfind和find区别
    // rfind 从右往左查找 find从左往右查找
    pos = str1.rfind("de");
    cout << "pos = " << pos << endl;
}

//2.替换
void test02()
{
    string str1 = "abcdefgde";
    //从1号位置起 3个字符 替换为"1111"
    str1.replace(1,3,"1111");
    cout << "str1 = " << str1 << endl;
}

void test03(){
    // 查找
    //使用拷贝构造 
    string str1 = "abcdefgde";
    string str2 = "de";
    int pos = str1.find(str2);
    cout << "pos = " << pos << endl;

    pos = str1.find('d',4);
    cout << "pos1 = " << pos << endl;
    //替换
    string str3 = "1111";
    str1.replace(4,3,str3);
    cout << "str1 = " << str1 << endl;


}
int main()
{
    // test01();

    // test02();

    test03();

    return 0;
}