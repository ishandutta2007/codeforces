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
const int M=1000000+10;
bool p[M];
int main()
{
    // freopen("in.txt", "r", stdin);
    for (int i=2;i<M;++i)
    {
        if (p[M]) continue;
        for (ll j=i*1LL*i;j<M;j+=i) p[j]=1;
    }
    int n; scanf("%d", &n);
    for (int i=2;i<n;++i) if (p[i]&&p[n-i])
    {
        printf("%d %d\n", i, n-i);
        return 0;
    }
    throw;
    return 0;
}