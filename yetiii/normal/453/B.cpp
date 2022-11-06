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
using namespace std;
const int M=60;
int n, a[700], b[111], p[900], ps, d[111][1<<17], w[111][1<<17];
bool pri(int n)
{
    for (int i=2;i<n;++i) if (n%i==0) return 0;
    return 1;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    for (int i=2;i<M;++i) if (pri(i)) p[ps++]=i;
    for (int i=1;i<M;++i)
    {
        int m=0;
        for (int j=0;j<ps;++j) if (i%p[j]==0) m+=1<<j;
        a[i]=m;
    }
    //printf("%d\n", ps);
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &b[i]);
    int mm=1<<ps;
    for (int i=1;i<=n;++i) for (int m=0;m<mm;++m) d[i][m]=1e9;
    for (int i=0;i<n;++i) for (int m=0;m<mm;++m)
    {
        for (int t=1;t<M;++t)
        {
            if (m&a[t]) continue;
            int z=d[i][m]+abs(b[i]-t);
            if (z<d[i+1][m|a[t]])
            {
                d[i+1][m|a[t]]=z;
                w[i+1][m|a[t]]=t;
            }
        }
    }
    vector<int> z;
    int i=n, j=mm-1;
    while (i)
    {
        z.push_back(w[i][j]);
        j=j^a[w[i][j]];
        --i;
    }
    for (int i=0;i<n;++i) printf("%d ", z[n-i-1]);
    return 0;
}