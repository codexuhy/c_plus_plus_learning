# 5 STL-常用算法
**概述：**
- 算法主要是由头文件<algorithm><funvtional><numberic>组成
- <algorithm>是由所有STL头文件中最大的一个，范围涉及到比较、交换、查找、遍历操作、复制、修改等等
- <numeric> 体积很小，只包括几个在序列上面进行简单教学运算的模板函数
- <functional> 定义了一些模板类用以声明函数对象

## 5.1 常用遍历算法
**学习目标：**
- 掌握常用的遍历算法

**算法简介：**
- for_each //遍历容器
- transform //搬运容器到另一个容器中

### 5.1.1 for_each
**功能描述：**
- 实现遍历容器

**函数原型：**
- for_each(iterator beg,iterator end,_func);
    //遍历算法 遍历容器元素
    //beg 开始迭代器
    //end 结束迭代器
    //_func函数或者函数对象

**示例：** 5.1.1-常用遍历算法-for_each.cpp
**总结：** for_each在实际开发中是最常用遍历算法，需要熟练掌握

### 5.1.2 transfrom
**功能描述：**
- 搬运容器到另一个容器

**函数原型：**
- transform(iterator beg1,iterator end1,iterator beg2,_func);
    //beg1 源容器开始迭代器
    //end1 源容器结束迭代器
    //beg2 目标容器开始迭代器
    //_func函数或者函数对象

**示例：** 5.1.2-常用遍历算法-transform.cpp
**总结：** 搬运的目标容器必须要提前开辟空间，否则无法正常搬运

## 5.2 常用查找算法
**学习目标：**
- 掌握常用的查找算法

**算法简介：**
- find          //查找元素
- find_if       //按条件查找元素
- adjacent_find //查找相邻重复元素
- binary_search //二分查找法
- count         //统计元素个数
- count_if      //按条件统计元素个数

### 5.2.1 find
**功能描述：**
- 查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

**函数原型：**
- find(iterator beg,iterator end,value);
    //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    //beg 开始迭代器
    //end 结束迭代器
    //value查找的元素
**示例：** 5.2.1-常用查找算法-find.cpp
**总结：** 利用find可以在容器中找指定的元素，返回值是迭代器

### 5.2.2 find_if
**功能描述：**
- 按条件查找元素

**函数原型：**
- find_if(iterator beg,iterator end,_Pred);
    //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    //beg 开始迭代器
    //end 结束迭代器
    //_Pred函数或者谓词(返回bool类型的仿函数)
**示例：** 5.2.2-常用查找算法-find_if.cpp
**总结：** 

### 5.2.3 adjacent_find
**功能描述：**
- 查找相邻重复元素

**函数原型：**
- adjacent_find(iterator beg,iterator end,_Pred);
    //查找相邻重复元素，返回相邻元素第一个位置的迭代器
    //beg 开始迭代器
    //end 结束迭代器
**示例：** 5.2.3-常用查找算法-adjacent_find.cpp
**总结：** 面试中如果出现查找相邻重复元素，记得用STL中的adjacent_find算法

### 5.2.4 binary_search
**功能描述：**
- 查找指定元素是否存在

**函数原型：**
- bool binary_search(iterator beg,iterator end,value);
    //查找相指定的元素，查到返回true 否则返回false
    //注意：在无序序列中不可用
    //beg 开始迭代器
    //end 结束迭代器
    //value查找的元素
**示例：** 5.2.4-常用查找算法-binary_search.cpp
**总结：** 二分查找效率很高，值得注意的是查找的容器中元素必须是有序序列

### 5.2.5 count
**功能描述：**
- 统计元素个数

**函数原型：**
- count(iterator beg,iterator end,value);
    //统计元素出现次数
    //beg 开始迭代器
    //end 结束迭代器
    //value统计的元素
**示例：** 5.2.5-常用查找算法-count.cpp
**总结：** 对于统计自定义数据类型时候，需要配合重载operator==

### 5.2.6 count_if
**功能描述：**
- 统计元素个数

**函数原型：**
- count_if(iterator beg,iterator end,_Pred);
    //按条件统计元素出现次数
    //beg 开始迭代器
    //end 结束迭代器
    //_Pred 谓词
**示例：** 5.2.6-常用查找算法-count_if.cpp
**总结：**

## 5.3 常用排序算法
**学习目标：**
- 掌握常用的排序算法

**算法简介：**
- sort            //对容器内元素进行排序
- random_shuffle  //洗牌  指定范围内的元素随机进行调整
- merge           //容器元素合并,并存储到另一容器
- reverse         //反转指定范围的元素

### 5.3.1 sort
**功能描述：**
- 对容器内元素进行排序

**函数原型：**
- sort(iterator beg,iterator end,_Pred)
    //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    //beg 开始迭代器
    //end 结束迭代器
    //_Pred 谓词
**示例：** 5.3.1-常用排序算法-sort.cpp
**总结：** sort属于开发中最常用的算法之一，需熟练掌握

### 5.3.2 random_shuffle
**功能描述：**
- 洗牌 指定范围内的元素随机调整次序

**函数原型：**
- random_shuffle(iterator beg,iterator end)
    //指定范围内的元素随机调整次序
    //beg 开始迭代器
    //end 结束迭代器
**示例：** 5.3.2-常用排序算法-random_shuffle.cpp
**总结：** random_shuffle洗牌算法比较实用，使用记得加随机数种子

### 5.3.3 merge
**功能描述：**
- 两个容器元素合并,并存储到另一容器

**函数原型：**
- merge(iterator beg1,iterator end1,iterator beg2,iterator end2,iterator dest)
    //容器元素合并,并存储到另一容器中
    //注意：两个容器必须是有序的
    //beg1 容器1开始迭代器
    //end1 容器1结束迭代器
    //beg2 容器1开始迭代器
    //end2 容器1结束迭代器
    //dest 目标容器开始迭代器
**示例：** 5.3.3-常用排序算法-merge.cpp
**总结：** merge合并的两个容器必须是有序序列

### 5.3.4 reverse
**功能描述：**
- 两将容器内元素进行反转

**函数原型：**
- reverse(iterator beg,iterator end)
    //反转指定范围的元素
    //beg 开始迭代器
    //end 结束迭代器
**示例：** 5.3.4-常用排序算法-reverse.cpp
**总结：** reverse反转区间元素，面试题可能涉及到

## 5.4 常用的拷贝和替换算法
**学习目标：**
- 掌握常用的拷贝和替换算法
**算法简介：**
- copy          //容器内指定范围的元素拷贝到另一容器中
- replace       //将容器内指定范围的旧元素修改为新元素
- replace_if    //容器内指定范围满足条件的元素替换为新元素
- swap          //互换两个容器的元素
### 5.4.1 copy
**功能描述：**
- 容器内指定范围的元素拷贝到另一容器中

**函数原型：**
- copy(iterator beg,iterator end,iterator dest)
    //按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
    //beg 开始迭代器
    //end 结束迭代器
    //dest 目标容器开始迭代器
**示例：** 5.4.1-常用的拷贝和替换算法-copy.cpp
**总结：** 利用copy算法在拷贝时，目标容器记得提前开辟空间

### 5.4.2 replace
**功能描述：**
- 将容器内区间范围的旧元素修改为新元素

**函数原型：**
- copy(iterator beg,iterator end,oldValue,newValue)
    //将区间内旧元素替换成新元素
    //beg 开始迭代器
    //end 结束迭代器
    //oldValue 旧元素
    //newValue 新元素
**示例：** 5.4.2-常用的拷贝和替换算法-replace.cpp
**总结：** replace会替换区间内满足条件的所有元素

### 5.4.3 replace_if
**功能描述：**
- 将区间内满足条件的元素，替换成指定元素

**函数原型：**
- copy(iterator beg,iterator end,_Pred,newValue)
    //按条件替换元素，满足条件的替换成指定元素
    //beg 开始迭代器
    //end 结束迭代器
    //_Pred 谓词
    //newValue 替换的新元素
**示例：** 5.4.3-常用的拷贝和替换算法-replace_if.cpp
**总结：** replace_if 按条件查找，可以利用仿函数灵活筛选满足的条件

### 5.4.4 swap
**功能描述：**
- 互换两个容器的元素

**函数原型：**
- swap(container c1,container c2)
    //互换两个容器的元素
    //c1 容器1
    //c2 容器2

**示例：** 5.4.4-常用的拷贝和替换算法-swap.cpp
**总结：** swap交换容器时，注意交换的容器需要同种类型


## 5.5 常用的算术生成算法
**学习目标：**
- 掌握常用的算术生成算法
**注意：**
- 算术生成算法属于小型算法，使用时包含的头文件为#include<numeric>

**算法简介：**
- accumulate            //计算容器元素累加总和
- fill                  //向容器中添加元素

### 5.5.1 accumulate
**功能描述：**
- 计算区间内 容器元素累加总和

**函数原型：**
- accumulate(iterator beg,iterator end,value)
    //计算容器元素累加总和
    //beg 开始迭代器
    //end 结束迭代器
    //value 起始值
**示例：** 5.5.1-常用的算术生成算法-accumulate.cpp
**总结：** accumulate使用时头文件注意是 numberic ,这个算法很实用

### 5.5.2 fill
**功能描述：**
- 计算区间内 容器元素累加总和

**函数原型：**
- accumulate(iterator beg,iterator end,value)
    //计算容器元素累加总和
    //beg 开始迭代器
    //end 结束迭代器
    //value 起始值
**示例：** 5.5.2-常用的算术生成算法-fill.cpp
**总结：** 利用fill可以将容器区间内元素填充为 指定的值