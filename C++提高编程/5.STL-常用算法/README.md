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