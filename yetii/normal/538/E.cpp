//
//         ."".    ."",
//         |  |   /  /
//         |  |  /  /
//         |  | /  /
//         |  |/  ;-._ 
//         }  ` _/  / ;
//         |  /` ) /  /
//         | /  /_/\_/\
//         |/  /      |
//         (  ' \ '-  |
//          \    `.  /
//           |      |
//           |      |
//

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

const int N=2*1000*100+10;
int n, d1[N], d2[N], sz[N], le[N];
vector<int> g[N];
void go(int v, int pl, int pr)
{
    int sm1=0,mx1=-1e9;
    int sm2=0,mx2=-1e9;
    sz[v]=0;
    le[v]=0;
    for (int i=0;i<g[v].size();++i)
    {
        int t=g[v][i];
        if (t==pr) continue;
        go(t, pl^1, v);
        ++le[v];
        sz[v]+=sz[t];

        sm1+=d1[t]-1;
        mx1=max(mx1, d1[t]-sz[t]);

        sm2+=d2[t]-1;
        mx2=max(mx2, d2[t]-sz[t]);
    }
    if (!le[v]) d1[v]=d2[v]=1,sz[v]=1;
    else
    {
        if (pl) d1[v]=sm1+1, d2[v]=sz[v]+mx2;
        else d1[v]=sz[v]+mx1, d2[v]=sm2+1;
    }
}
int main()
{
    scanf("%d", &n);
    for (int i=0;i<n-1;++i)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        --a; --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    go(0, 0, -1);
    printf("%d %d\n", d1[0], sz[0]+1-d2[0]);

    // for (int i=0;i<n;++i) { printf("%d %d %d\n", i+1, d1[i], d2[i]); }
    return 0;
}