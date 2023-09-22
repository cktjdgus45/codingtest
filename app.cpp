#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int n;
int a[12], b[4];
int p, minu, mul, divi;
int ret = -1000000001;
int ret2 = 1000000001;

void go(int index, int cur, int p, int minu, int mul, int divi)
{
    if (index == n - 1)
    {
        ret = max(cur, ret);
        ret2 = min(ret2, cur);
        return;
    }
    if (p)
        go(index + 1, cur + a[index + 1], p - 1, minu, mul, divi);
    if (minu)
        go(index + 1, cur - a[index + 1], p, minu - 1, mul, divi);
    if (mul)
        go(index + 1, cur * a[index + 1], p, minu, mul - 1, divi);
    if (divi)
        go(index + 1, cur / a[index + 1], p, minu, mul, divi - 1);
    return;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    scanf("%d %d %d %d", &p, &minu, &mul, &divi);
    go(0, a[0], p, minu, mul, divi);
    printf("%d\n%d\n", ret, ret2);
    return 0;
}