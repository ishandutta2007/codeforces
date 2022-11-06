#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int k, n[4], t[4], d[4][10010], z[10010];
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &k);
    for (int i=0;i<3;++i) scanf("%d", &n[i]);
    for (int i=0;i<3;++i) scanf("%d", &t[i]);
    for (int m=0;m<3;++m)
    {
        for (int i=0;i<n[m];++i) z[i]=0;
        int p=0;
        for (int i=0;i<k;++i)
        {
            d[m+1][i]=t[m]+max(d[m][i], z[p]);
            z[p]=d[m+1][i];
            ++p; if (p==n[m]) p=0;
        }
    }
    printf("%d\n", d[3][k-1]);
    return 0;
}