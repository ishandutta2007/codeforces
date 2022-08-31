#include <cstdio>
using namespace std;

int main()
{
    int a, b, c = 0;
    scanf("%d %d", &a, &b);
    int ans = 0;
    while (true)
    {
        if (c >= b)
            c -= b, a++;
        else if (a > 0)
            a--, c++, ans++;
        else
            break;
    }
    printf("%d\n", ans);
}