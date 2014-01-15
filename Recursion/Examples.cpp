/*
* 递归问题
*/

#include <stdio.h>

int b_search(int *data, int n, int key)
{
    int mid;

    for (int *p = data, i = 0; i < n; i++, p++)
        printf("%d ", *p);
    putchar('\n');

    if (n == 1)
        return (data[0] == key);
    else
    {
        mid = n / 2;

        printf("compare with %d\n", data[mid - 1]);

        if (data[mid - 1] == key)
            return 1;
        else if (data[mid - 1] > key)
            return b_search(&data[0], mid, key);
        else
            return b_search(&data[mid], n - mid, key);
    }
}

// 二分查找的递归实现
void example1()
{
    int arr[10] = {15, 17, 20, 23, 25, 26, 27, 53, 63, 99};
    int key = 20;
    int rs = b_search(arr, 10, key);
    printf("%s\n", rs == 0 ? "NO" : "YES");
}

int mystrlen(char *buf, int n)
{
    if (buf[0] == 0 || n == 0)
        return 0;
    else if (n == 1)
        return 1;
    int t = mystrlen(buf, n / 2);

    for (int i = 0; i < n; i++)
        printf("%c ", buf[i] == '\0' ? '*' : buf[i]);
    putchar('\n');
    printf("t is %d, n is %d\n", t, n);

    if (t < n / 2)
        return t;
    else
        return t + mystrlen(buf + n / 2, (n + 1) / 2);
}

// 递归计算字符串长度
void example2()
{
    char buf[] = "abcdef\0xyz";
    int k = mystrlen(buf, 20);
    printf("%d\n", k);
}

/*
* 将下面的递归版本转化为非递归
*
void example3_r(int m, int n)
{
    if (m == 1)
        return n;
    if (n == 1)
        return m;
    return f(m - 1, n) + f(m, n - 1);
}
*/
void example3()
{
    int a[10][10];
    int m = 5, n = 5;
    for (int i = 0; i < m; i++)
        a[i][0] = i + 1;
    for (int i = 0; i < n; i++)
        a[0][i] = i + 1;
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            a[i][j] = a[i - 1][j] + a[i][j - 1];

    printf("%d\n", a[m - 1][n - 1]);
}

// 形成一个N×N的zigzag数组
void example4()
{
    const int N = 6;
    int a[N][N];
    int squa = N * N;
    int s;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            s = i + j;
            if (s < N) // 左上三角
                a[i][j] = s * (s + 1) / 2 +
                          ((i + j) % 2 == 0 ? i : j);
            else // 右下三角
            {
                s = (N - 1 - i) + (N - 1 - j);
                a[i][j] = squa - s * (s + 1) / 2 -
                          (N - ((i + j) % 2 == 0 ? i : j));
            }
        }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%3d", a[i][j]);
        putchar('\n');
    }
}

int main()
{
    example1();
    example2();
    example3();
    example4();

    return 0;
}
