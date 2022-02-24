#include <iostream>
using namespace std;

int main(){

    // 不建议使用goto语句,以免造成程序的流程混乱
    // 解释：如果标记的名称存在，执行到goto语句时，会跳转到标记的位置

    cout << "1.XXX" << endl;
    goto FLAG;
    cout << "2.XXX" << endl;
    cout << "3.XXX" << endl;
    FLAG;
    cout << "4.XXX" << endl;
    cout << "5.XXX" << endl;

    return 0;
}