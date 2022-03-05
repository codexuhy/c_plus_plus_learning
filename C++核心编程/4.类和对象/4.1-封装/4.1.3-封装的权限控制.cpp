#include <iostream>
using namespace std;

/*
    访问权限
        三种
        公共权限 public         成员 类内可以访问  类外可以访问
        保护权限 protected      成员 类内可以访问  类外不可以访问  儿子可以访问父亲中的保护内容
        私有权限 private        成员 类内可以访问  类外不可以访问  儿子不可以访问父亲中的私有内容

*/

class Person
{
public:
    //姓名 公共权限
    string m_Name;

protected:
    //汽车 保护权限
    string m_Car;

private:
    //银行卡密码 私有权限
    int m_Password;

public:
    void func()
    {
        m_Name = "张三";
        m_Car = "拖拉机";
        m_Password = 123456;
        cout << "姓名： " << m_Name << "\t汽车：" << m_Car << "\t卡号：" << m_Password << endl;
    }
};

int main()
{

    //实例化具体对象
    Person p1;

    p1.m_Name = "李四";
    // p1.m_Car = "奔驰";//保护权限内容,在类外访问不到
    // p1.m_Password = 123456;//私有权限内容，在类外访问不到
    p1.func();

    return 0;
}