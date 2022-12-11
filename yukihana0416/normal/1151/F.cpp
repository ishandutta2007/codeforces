#include <bits/stdc++.h>
using namespace std;

#define LL long long

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(l,r) (((l)+(r))>>1)

const int MOD = (int) 1e9 + 7;
const double eps = (double) 1e-8;
const int maxn = (int) 2e5 + 20;


int n, m;
int a[105];

struct mat
{
    int n;
    int a[105][105];

    mat operator * (const mat &t) const
    {
        mat res;

        res.n = n;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                res.a[i][j] = 0;

        for(int i = 0; i <= n; i++)
            for(int k = 0; k <= n; k++) if(a[i][k])
                for(int j = 0; j <= n; j++) if(t.a[k][j])
                    res.a[i][j] = ((LL) a[i][k] * t.a[k][j] + res.a[i][j]) % MOD;
        return res;
    }
};

mat fp(mat a, int n)
{
    mat res;
    res.n = a.n;
    for(int i = 0; i <= res.n; i++)
        for(int j = 0; j <= res.n; j++)
            res.a[i][j] = 0;
    for(int i = 0; i <= res.n; i++)
        res.a[i][i] = 1;

    while(n)
    {
        if(n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}

int fp(int a, int n)
{
    int res = 1;
    while(n)
    {
        if(n & 1) res = ((LL) res * a) % MOD;
        a = ((LL) a * a) % MOD;
        n >>= 1;
    }
    return res;
}

void work()
{
    cin >>n >>m;
    for(int i = 1; i <= n; i++) cin >>a[i];

    int t = 0;
    for(int i = 1; i <= n; i++) t += !a[i];
    int s = 0;
    for(int i = 1; i <= t; i++) s += !a[i];

    mat base;
    base.n = t;
    for(int i = 0; i <= t; i++)
        for(int j = 0; j <= t; j++)
            base.a[i][j] = 0;

    for(int i = 0; i <= t; i++)
    {
        int a, b, c, d;
        a = i;
        b = t - a;
        c = b;
        d = n - a - b - c;
        base.a[i][i] = t * (t - 1) / 2 + (n - t) * (n - t - 1) / 2 + a * c + b * d ;
        if(i != 0) base.a[i][i - 1] = a * d;
        if(i != t) base.a[i][i + 1] = b * c;
    }

    mat ans = fp(base, m);

    cout <<((LL) ans.a[s][t] * fp(fp(n * (n - 1) / 2, MOD - 2), m)) % MOD <<endl;
}

int main()
{
#ifdef yukihana0416
freopen("in.txt", "r" ,stdin);
//freopen("out.txt", "w", stdout);
#endif // yukihana0416

    int tc = 1;
//    scanf("%d", &tc);
    for(int ca = 1; ca <= tc; ca++)
    {
//        printf("Case #%d: ", ca);
        work();
    }
    return 0;
}