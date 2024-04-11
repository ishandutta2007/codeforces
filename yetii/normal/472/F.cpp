#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <numeric>
using namespace std;
typedef long long ll;

const int N=100000, M=30;
int n, x[N], y[N], xx[N], yy[N], b[M], u[N];
void xo(int *x, vector<pair<int, int>> &rx, int l, int r)
{
    rx.push_back({l+1, r+1});
    x[l]^=x[r];
}
void sw(int *x, vector<pair<int, int>> &rx, int l, int r)
{
    if (l!=r)
    {
        xo(x, rx, l, r);
        xo(x, rx, r, l);
        xo(x, rx, l, r);
    }
}
int BT(int a, int p)
{
    return bool(a&(1<<p));
}
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &x[i]), xx[i]=x[i];
    for (int i=0;i<n;++i) scanf("%d", &y[i]), yy[i]=y[i];
    vector<pair<int, int>> rx, ry;
    for (int i=0;i<M;++i)
    {
        int m=-1, bi=1<<i;
        for (int j=0;j<n;++j) if (!u[j]&&(x[j]&bi)) m=j;
        b[i]=m; if (m==-1) continue;
        u[m]=1; for (int j=0;j<n;++j) if ((x[j]&bi)&&(j!=m)) xo(x, rx, j, m);
    }
    for (int i=0;i<n;++i)
    {
        int t=y[i];
        for (int j=0;j<M;++j) if (t&(1<<j))
        {
            if (b[j]==-1)
            {
                puts("-1");
                return 0;
            }
            t^=x[b[j]];
        }
        if (t) throw;
    }
    for (int i=0;i<n;++i) u[i]=0;
    for (int i=0;i<M;++i)
    {
        int m=-1, bi=1<<i;
        for (int j=0;j<n;++j) if (!u[j]&&(y[j]&bi)) m=j;
        if (m==-1)
        {
            if (b[i]!=-1) xo(x, rx, b[i], b[i]);
            continue;
        }
        if (b[i]==-1) throw;
        sw(y, ry, b[i], m);
        m=b[i]; u[m]=1;
        for (int j=0;j<M;++j) if (BT(x[m], j)!=BT(y[m], j))
        {
            if (j<=i) throw;
            if (b[j]==-1) throw;
            xo(x, rx, m, b[j]);
        }
        for (int j=0;j<n;++j) if (!u[j]&&(y[j]&bi))
        {
            xo(y, ry, j, m);
        }
    }
    for (int i=ry.size();i;--i) rx.push_back(ry[i-1]);
    printf("%d\n", rx.size());
    for (int i=0;i<rx.size();++i) printf("%d %d\n", rx[i].first, rx[i].second);
    for (int i=0;i<rx.size();++i)
    {
        xx[rx[i].first-1]^=xx[rx[i].second-1];
    }
    for (int i=0;i<n;++i) if (xx[i]!=yy[i]) throw;
    return 0;
}