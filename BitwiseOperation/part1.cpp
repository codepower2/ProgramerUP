/*
* 常用位操作小技巧
*/

#include <iostream>
using namespace std;

// 判断奇偶，输出0到100之间的奇数
void example1()
{
    for (int i = 0; i < 10; ++i)
        if (i & 1) // 通过末位判断奇偶
            cout << i << " ";
    cout << endl;
}

// 利用异或^交换两数，无需使用第三方变量
void example2()
{
    int a = 45, b = 33;
    cout << a << " " << b;
    if (a != b)
    {
        /*
        * a ^= b 得到 a = a^b，
        * b ^= a 得到 b = b^a = b^a^b = b^b^a = a，因为异或满足交换律，
        * a ^= b 得到 a = a^b = a^b^a = b
        */
        a ^= b;
        b ^= a;
        a ^= b;
    }
    cout << " to ";
    cout << a << " " << b << endl;
}

// 对整数变换正负号
void example3()
{
    int a = 7, b = -9;
    cout << a << " " << b;
    cout << " to ";
    cout << ~a + 1 << " " << ~b + 1 << endl;
}

// 不使用判断求绝对值
void example4()
{
    int a = -564;
    int i = a >> 31; // 先移位来取符号位
    /*
    * 对于任何数，与0异或都会保持不变，与-1即0xFFFFFFFF异或就相当于取反
    * 若i为0，则总体不变；若i为1，则相当于先取反再加1
    */
    a = ((a ^ i) - i);
    cout << a << endl;
}

int main()
{
    example1();
    example2();
    example3();
    example4();

    return 0;
}
