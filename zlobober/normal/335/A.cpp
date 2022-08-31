#include <cstdio>
#include <cassert>
#include <cstring>
using namespace std;

const int N = 1050;

char buf[N];
int cnt[256];

int main()
{
    int n;
    gets(buf);
    int l = strlen(buf);
    scanf("%d", &n);
    int df = 0;
    for (int i = 0; i < l; i++)
        cnt[buf[i]]++, df += cnt[buf[i]] == 1;
    if (df > n)
    {
        printf("-1\n");
        return 0;
    }
    int a = 0, b = l;
    while (b - a > 1)
    {
        int m = (a + b) / 2;
        int sum = 0;
        for (int i = 'a'; i <= 'z'; i++)
            sum += (cnt[i] + m - 1) / m;
        if (sum <= n)
            b = m;
        else
            a = m;
    }
    printf("%d\n", b);
    int q = 0;
    for (int i = 'a'; i <= 'z'; i++)
    {
        q += (cnt[i] + b - 1) / b;
        for (int j = 0; j < (cnt[i] + b - 1) / b; j++)
            printf("%c", (char)i);
    }
    assert(q <= n);
    while (q < n)
        printf("x"), q++;
    printf("\n");
}