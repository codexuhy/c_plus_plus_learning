#include <iostream>
using namespace std;
#define MAX 1000 //最大人数

#include<stdlib.h>

//联系人结构体
struct Person
{
    string m_name;  //性别
    int m_sex;      //性别
    int m_age;      //年龄
    string m_phone; //电话
    string m_addr;  //地址
};

//通讯录结构体
struct AddressBooks
{
    struct Person personArray[MAX]; //通讯录中保存联系人数组
    int m_size;                     //通讯录中人员个数
};
//1、添加联系人
void addPerson(struct AddressBooks *abs)
{
    //判断通讯录是否已满,如果满了就不再添加
    if (abs->m_size == MAX)
    {
        cout << "通讯录已满，无法添加！" << endl;
        return;
    }
    else
    {
        //添加具体联系人
        
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[abs->m_size].m_name = name;

        //性别
        cout << "请输入性别：" << endl;
        cout << "1 ---- 男" << endl;
        cout << "2 ---- 女" << endl;
        int sex = 0;
        while(true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                abs->personArray[abs->m_size].m_sex = sex;
                break;
            }
            cout << "输入有误,请重新输入" << endl;
        }
        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[abs->m_size].m_age  = age;

        //电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[abs->m_size].m_phone = phone;

        //地址
        cout << "请输入家庭住址：" << endl;
        string address;
        cin >> address;
        abs -> personArray[abs->m_size].m_addr = address;

        //更新通讯录人数
        abs->m_size++;

        cout << "添加成功" << endl;
        // system("pause");
        system("clear");
        
        
    }
}

//2、显示联系人
void showPerson(struct AddressBooks * abs)
{
    if (abs->m_size == 0)
    {
        cout << "当前记录为空" << endl;
    }
    else if (abs->m_size > 0)
    {
        for (int i = 0; i< abs->m_size;i++)
        {
            cout << "姓名：" << abs->personArray[i].m_name
            <<"\t性别：" << (abs->personArray[i].m_sex == 1? "男":"女")
            <<"\t年龄：" << abs->personArray[i].m_age
            <<"\t电话：" << abs->personArray[i].m_phone
            <<"\t家庭住址：" << abs->personArray[i].m_addr
            << endl;
        }
        
    }
}
//显示菜单
void showMenu()
{
    cout << "**************************" << endl;
    cout << "***** 1、添加联系人 *****" << endl;
    cout << "***** 2、显示联系人 *****" << endl;
    cout << "***** 3、删除联系人 *****" << endl;
    cout << "***** 4、查找联系人 *****" << endl;
    cout << "***** 5、修改联系人 *****" << endl;
    cout << "***** 6、清空联系人 *****" << endl;
    cout << "***** 0、退出联系人 *****" << endl;
    cout << "**************************" << endl;
}

int main()
{
    //创建通讯录结构体变量
    AddressBooks abs;
    //初始化通讯录中当前人员个数
    abs.m_size = 0;

    int select = 0; //创建用户选择输入的变量

    while (true)
    {
        //菜单调用
        showMenu();

        cin >> select;

        switch (select)
        {
        case 1:              //添加联系人
            addPerson(&abs); //利用地址传递，可以修饰实参
            break;
        case 2: //显示联系人
        showPerson(&abs);
            break;
        case 3: //删除联系人
            break;
        case 4: //查找联系人
            break;
        case 5: //修改联系人
            break;
        case 6: //清空联系人
            break;
        case 0: //退出通讯录
            cout << "欢迎下次使用" << endl;
            return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}