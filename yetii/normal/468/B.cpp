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

int n, a, b, p[1000*1000], rs[1000*1000];
map<int, int> g;
int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d %d %d", &n, &a, &b);
    for (int i=0;i<n;++i) scanf("%d", &p[i]), g[p[i]]=i;
    if (a==b)
    {
        for (int i=0;i<n;++i) if (!g.count(a-p[i]))
        {
            puts("NO");
            return 0;
        }
    }
    else
    {
        bool re=0;
        if (a<b) swap(a, b), re=1;
        while (g.size())
        {
            pair<int, int> z=*g.begin();
            int x, y;
            if (g.count(a-z.first))
            {
                x=z.first, y=a-z.first;
            }
            else
            {
                if (!g.count(b-z.first))
                {
                    puts("NO");
                    return 0;
                }
                x=z.first, y=b-z.first;
                rs[g[x]]=1;
                rs[g[y]]=1;
            }
            g.erase(g.find(x));
            if (g.find(y)!=g.end()) g.erase(g.find(y));
        }
        if (re) for (int i=0;i<n;++i) rs[i]^=1;
    }
    puts("YES");
    for (int i=0;i<n;++i) printf("%d ", rs[i]);
    puts("");
    return 0;
}