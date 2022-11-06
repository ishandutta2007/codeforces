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
const int N=1000*1000;
int n, m, a[N+5], b[N+5];
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i=0;i<n; ++i) scanf("%d", &a[i]);
    for (int i=0;i<m; ++i) scanf("%d", &b[i]);
    sort(a, a+n);
    sort(b, b+m);
    long long rs=1e18;
    for (int it=0;it<2;++it, swap(a, b), swap(n, m))
    {
        long long s1=accumulate(a, a+n, 0LL), s2=accumulate(b, b+m, 0LL);
        for (int t=1;t<=n;++t)
        {
            s1-=a[n-t];
            double x=s1+t*1.0*s2;
            if (x<1e18) rs=min(rs, s1+t*s2);
        }
    }
    cout<<rs<<endl;
    return 0;
}