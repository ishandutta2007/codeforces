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
int n, k, f[2222], d[2222];
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d", &n, &k);
    for (int i=0;i<n;++i) scanf("%d", &f[i]);
    sort(f, f+n, less<int>());
    for (int i=1;i<=n;++i)
    {
        int m=0; d[i]=1e9;
        for (int j=i-1;j>=0&&j>=i-k;--j)
        {
            m=max(m, f[j]);
            d[i]=min(d[i], d[j]+2*(m-1));
        }
    }
    printf("%d\n", d[n]);
    return 0;
}