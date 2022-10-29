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

using namespace std;
int n, m, a[5555], b[5555], d[5555], g[5555], f[5555], s[5555];
int gcd(int a, int b)
{
    while (b) a%=b, swap(a, b); return a;
}
int bal(int x)
{
    int r=0;
    for (int i=0;i<m;++i)
    {
        while (x%b[i]==0) x/=b[i], --r;
    }
    for (int i=2;i*i<=x;++i)
    {
        while (x%i==0) x/=i, ++r;
    }
    if (x>1) ++r;
    return r;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    for (int i=0;i<m;++i) scanf("%d", &b[i]);
    g[0]=0;
    for (int i=0;i<n;++i)
    {
        g[i+1]=gcd(g[i], a[i]);
        f[i+1]=bal(g[i+1]);
    }
    for (int i=0;i<n;++i) s[i+1]=s[i]+bal(a[i]);
    for (int i=1;i<=n;++i)
    {
        d[i]=-1e9;
        for (int j=0;j<i;++j)
        {
            int t=d[j]+s[i]-s[j]-f[i]*(i-j);
            d[i]=max(d[i], t);
        }
    }
    int rs=-1e9;
    for (int i=0;i<=n;++i) rs=max(rs, d[i]+s[n]-s[i]);
    printf("%d\n", rs);
    return 0;
}