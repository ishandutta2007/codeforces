#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = (int) 2e5+20;

int n;
int x, f;
int a[maxn];

LL calc(LL y)
{
    if(x >= y) return 0;
    LL times = y / (x + f);
    LL mod = y % (x + f);
    if(mod > x) times++;
    return times * f;
}

void work()
{
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", a + i);
    scanf("%d%d", &x, &f);

    LL ans = 0;
    for(int i = 0; i < n; i++)
        ans += calc(a[i]);

    cout <<ans <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416
    work();
    return 0;
}