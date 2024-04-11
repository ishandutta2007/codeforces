#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;

const int mod=1000000007, T=1111;
int n, f[T][T], x[T], y[T];
int add(int a, int b)
{
    a+=b; if (a>=mod) a-=mod;
    return a;
}
int mul(int a, int b)
{
    return (a*1LL*b)%mod;
}
int pw(int a, int p)
{
    int r=1;
    while (p)
    {
        if (p&1) r=mul(r, a);
        a=mul(a, a);
        p/=2;
    }
    return r;
}
int main()
{
    f[0][0]=1;
    for (int t=1;t<T;++t) for (int k=1;k<T;++k)
    {
        if (t>=k) f[t][k]=add(f[t-k][k], f[t-k][k-1]);
    }
    x[0]=1; for (int i=1;i<T;++i) x[i]=mul(x[i-1], i);
    for (int i=0;i<T;++i) y[i]=pw(x[i], mod-2);
    int t, n, k;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &k);
        int r=0;
        for (int t=0;t<=n;++t) r=add(r, mul(mul(x[n+k-t], y[n-t]), f[t][k]));
        printf("%d\n", r);
    }
    return 0;
}