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

char s[1010], f[1010];
int n, p;
bool go(int i, char b)
{
    if (i==n) return 1;
    while (b<'a'+p)
    {
        f[i]=b;
        ++b;
        if (i>=1&&f[i-1]==f[i]) continue;
        if (i>=2&&f[i-2]==f[i]) continue;
        return go(i+1, 'a');
    }
    return 0;
}
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d\n", &n, &p);
    gets(s);
    for (int i=n-1;i>=0;--i)
    {
        for (int j=0;j<i;++j) f[j]=s[j];
        if (!go(i, s[i]+1)) continue;
        puts(f);
        return 0;
    }
    puts("NO");
    return 0;
}