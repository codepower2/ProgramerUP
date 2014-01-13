/*
* 位操作与空间压缩，筛素数法举例
* 有很多重复如flag[10]会在访问flag[2]和flag[5]时各访问一次
* 待阅读，改进的筛素数法 http://blog.csdn.net/morewindows/article/details/7347459
*/

#include <stdio.h>
#include <memory.h>

const int MAXN = 100;
int flag[MAXN / 32 + 1];
int primes[MAXN / 3 + 1], pi;

void example()
{
    // 在一个数指定位上置1
    int j = 0;
    j |= 1 << 10;
    printf("%d\n", j);

    // 判断指定位上是0还是1
    if (j & (1 << 10))
        printf("Is 1\n");
    else
        printf("Is 0\n");

    // 在数组中使用位操作
    int b[5] = {0};
    int i;
    for (i = 0; i < 40; i += 3)
        b[i / 32] |= (1 << (i % 32));
    for (i = 0; i < 40; i++)
    {
        if ((b[i / 32] >> (i % 32)) & 1)
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}

void GetPrime_1()
{
    int i, j;
    pi = 0;
    memset(flag, 0, sizeof(flag));
    for (i = 2; i < MAXN; i++)
        if (!((flag[i / 32] >> (i % 32)) & 1))
        {
            primes[pi++] = i;
            for (j = i; j < MAXN; j += i)
                flag[j / 32] |= (1 << (j % 32));
        }
}

int main()
{
    example();

    GetPrime_1();
    for (int i = 0; i < pi; i++)
        printf("%d ", primes[i]);
    putchar('\n');
    return 0;
}
