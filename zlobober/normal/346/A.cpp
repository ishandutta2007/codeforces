#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    while (b)
        a %= b, swap(a, b);
    return a;
}

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 0;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        ans = gcd(ans, t);
        mx = max(mx, t);
    }
    printf("%s\n", (((mx / ans) - n) % 2 ? "Alice" : "Bob"));
    return 0;
}