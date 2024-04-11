# include <cstdio>
# include <set>
using namespace std;
long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    else
        return gcd(b % a, a);
    
}
long long lcm(long long a, long long b)
{
    return a / gcd(a, b) * b;
}
int main()
{
    int n;
    scanf("%d", &n);
    long long res = 0;
    for (int i = n; i >= max(1, n - 4); --i)
        for (int k = n; k >= max(1, n - 4); --k)
            for (int l = n; l >= max(1, n - 4); --l)
            {
                long long v = lcm(i, lcm(k, l));
                if (v > res)
                    res = v;
            }
    printf("%I64d\n", res);
}