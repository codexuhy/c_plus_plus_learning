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

// 判断是否存在查询的人员，存在返回数组中索引位置，不存在返回-1
//参数1 通讯录，参数2 对比姓名
int isExist(AddressBooks *abs, string name)
{
    for (int i = 0; i < abs->m_size; i++)
    {
        // 找到用户输入的姓名
        if (abs->personArray[i].m_name == name)
        {
            return i; //找到了，返回这个人在数组中的下标编号
        }
    }
    return -1; //如果遍历结束都没找到，返回-1
}
// 3、删除指定联系人信息
void deletePerson(AddressBooks *abs)
{
    cout << "请输入您要删除的联系人" << endl;

    string name;
    cin >> name;

    // ret == -1 为找到
    // ret == 1查到了
    int ret = isExist(abs, name);

    if (ret != -1)
    {
        //查找到人，要进行删除操作
        for (int i = ret; i < abs->m_size; i++)
        {
            //数据前移
            abs->personArray[i] = abs->personArray[i + 1];
        }
        abs->m_size--; //更新通讯录中的人员数
        cout << "删除成功" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    // system("clear");
}

// 4.查找指定联系人信息
void findPerson(AddressBooks *abs)
{
    cout << "请输入您要查找的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        cout << "姓名：" << abs->personArray[ret].m_name << "\t";
        cout << "性别：" << abs->personArray[ret].m_sex << "\t";
        cout << "年龄：" << abs->personArray[ret].m_age << "\t";
        cout << "电话：" << abs->personArray[ret].m_phone << "\t";
        cout << "住址：" << abs->personArray[ret].m_addr << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }

    // system("clear");
}

// 5. 修改指定联系人信息
void modifyPerson(AddressBooks *abs)
{
    cout << "请输入您要修改的联系人" << endl;
    string name;
    cin >> name;

    int ret = isExist(abs, name);
    if (ret != -1)
    {
        //姓名
        string name;
        cout << "请输入姓名：" << endl;
        cin >> name;
        abs->personArray[ret].m_name = name;
        //性别
        cout << "请输入性别：" << endl;
        cout << "1 --- 男" << endl;
        cout << "2 --- 女" << endl;
        int sex = 0;
        while (true)
        {
            cin >> sex;
            if (sex == 1 || sex == 2)
            {
                //输入正确 退出循环输入
                abs->personArray[ret].m_sex = sex;
                break;
            }
            else
            {
                cout << "输入有误，请重新输入" << endl;
            }
        }

        //年龄
        cout << "请输入年龄：" << endl;
        int age = 0;
        cin >> age;
        abs->personArray[ret].m_age = age;

        //电话
        cout << "请输入联系电话：" << endl;
        string phone;
        cin >> phone;
        abs->personArray[ret].m_phone = phone;

        //地址
        cout << "请输入家庭地址：" << endl;
        string address;
        cin >> address;
        abs->personArray[ret].m_addr = address;

        cout << "修改成功！" << endl;
    }
    else
    {
        cout << "查无此人" << endl;
    }
    system("clear");
}

// 6、清空所有联系人
void cleanPerson(AddressBooks *abs)
{
    abs->m_size = 0; //当前记录联系人置为0，做逻辑清空操作
    cout << "通讯录已清空" << endl;
    // 按任意键后清屏
    // system("clear");
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
            // {
            //         cout << "请输入删除联系人姓名：" << endl;
            //         string name;
            //         cin >> name;

            //     if (isExist(&abs,name) == -1)
            //     {
            //         cout << "查无此人" << endl;
            //     }
            //     else
            //     {
            //         cout << "找到此人" << endl;
            //     }
            // }
            deletePerson(&abs);
            break;
        case 4: //查找联系人
            findPerson(&abs);
            break;
        case 5: //修改联系人
            modifyPerson(&abs);
            break;
        case 6: //清空联系人
            cleanPerson(&abs);
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