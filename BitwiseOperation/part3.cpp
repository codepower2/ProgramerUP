/*
* 位操作的趣味应用
*/

#include <stdio.h>
template <class T>

void PrintBinary(T a)
{
    int i;
    for (i = sizeof(a) * 8 - 1; i >= 0; --i)
    {
        if ((a >> i) & 1)
            putchar('1');
        else
            putchar('0');
        if (i == 8)
            putchar(' ');
    }
    putchar('\n');
}

// 高低位交换
void example1()
{
    unsigned short a = 34520;
    PrintBinary(a);
    a = (a >> 8) | (a << 8);
    PrintBinary(a);
}

// 二进制逆序，详细说明见参考文章
void example2()
{
    unsigned short a = 34520;
    PrintBinary(a);

    a = ((a & 0xAAAA) >> 1) | ((a & 0x5555) << 1);
    a = ((a & 0xCCCC) >> 2) | ((a & 0x3333) << 2);
    a = ((a & 0xF0F0) >> 4) | ((a & 0x0F0F) << 4);
	a = ((a & 0xFF00) >> 8) | ((a & 0x00FF) << 8);
	PrintBinary(a);
}

// 二进制中1的个数
void example3()
{
    // 没理解，待完成
}

// 缺失的数字
// 待阅读，缺失的两个数字 http://blog.csdn.net/morewindows/article/details/8214003
void example4()
{
    /*
    * 异或的两个特性:自己与自己异或结果为0，交换律
    * 将数字全异或一遍，结果就是仅出现一次的数
    */
    const int MAXN = 15;
    int a[MAXN] = {1, 347, 6, 9, 13, 65, 889, 712, 889, 347, 1, 9, 65, 13, 712};
    int lostNum = 0;
    for (int i = 0; i < MAXN; i++)
        lostNum ^= a[i];
    printf("%d\n", lostNum);
}

int main()
{
    example1();
    example2();
    example3();
    example4();

    return 0;
}
