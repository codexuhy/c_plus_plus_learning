#pragma once
#include <iostream>
#include <string>
using namespace std;
template <class T>
class MyArray
{
public:
    //有参构造 参数 容量
    MyArray(int capacity)
    {
        this->m_Capacity = capacity;
        this->m_Size = 0;
        this->pAddress = new T[this->m_Capacity]; //将数组中的数据开辟(存储)到堆区
    }

    //拷贝构造
    MyArray(const MyArray &arr)
    {
        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;
        // this->pAddress = arr.pAddress; //浅拷贝 导致堆区的数据重复释放

        this->pAddress = new T[arr.m_Capacity];

        //将arr中的数据都拷贝过来
        for (int i = 0; i < this->m_Size; i++)
        {
            //元素传递
            this->pAddress[i] = arr.pAddress[i];
        }
    }
    // operator= 防止浅拷贝问题(重载=号运算符)
    MyArray &operator=(const MyArray &arr)
    {
        //判断数组是否为空
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
            this->m_Capacity = 0;
            this->m_Size = 0;
        }
        //深拷贝
        this->m_Capacity = arr.m_Capacity;
        this->m_Size = arr.m_Size;

        this->pAddress = new T[arr.m_Capacity];

        for (int i = 0; i < this->m_Size; i++)
        {
            this->pAddress[i] = arr.pAddress[i];
        }

        return *this; //返回自身
    }

    //尾插法
    void Push_Back(const T &val)
    {
        //判断容量是否等于大小
        if (this->m_Capacity == this->m_Size)
        {
            return;
        }
        this->pAddress[this->m_Size] = val; //在数组末尾插入数据
        this->m_Size++;                     //更新数组大小
    }

    //尾删法
    void Pop_Back()
    {
        if (this->m_Size == 0)
        {
            return;
        }
        this->m_Size--;
    }

    //通过下标方式访问数组中的元素 arr[0]=100
    //函数调用想作为一个左值存在的话 要返回引用才可以 例如 arr[0]=100
    //想要100作为arr[0]的左值 必须要用引用 T&
    T &operator[](int index)
    {
        return this->pAddress[index];
    }

    //返回数组容量
    int getCapacity()
    {
        return this->m_Capacity;
    }
    //返回数组大小
    int getSize()
    {
        return this->m_Size;
    }
    //析构函数
    ~MyArray()
    {
        if (this->pAddress != NULL)
        {
            delete[] this->pAddress;
            this->pAddress = NULL;
        }
    }

private:
    T *pAddress; //指针指向堆区开辟的真实数组

    int m_Capacity; //数组容量

    int m_Size; //数组大小
};