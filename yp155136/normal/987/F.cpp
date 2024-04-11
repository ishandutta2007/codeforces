#include <bits/stdc++.h>
using namespace std;

const int N = (1<<22);

inline int rit()
{
    int ret=0;
    char c;
    do {
        c=getchar();
    } while (c < '0' || c > '9');
    do {
        ret = (ret<<1) + (ret<<3) + (c-'0');
        c = getchar();
    } while ('0' <= c && c <= '9');
    return ret;
}

int to[N];
int to2[N];

bitset<2*N> vis;

int base;
int n;

void dfs(int now)
{
    vis[now] = true;
    if (now >= base)
    {
        now -= base;
        if (to2[now] != 0 && !vis[ to2[now]-1 ]) dfs( to2[now]-1 );
        for (int i=0;n>i;i++)
        {
            int nxt = ((1<<i)|now);
            if (now != nxt && !vis[nxt+base]) dfs(nxt+base);
        }
    }
    else
    {
        if (to[now] != 0 && !vis[ to[now] ]) dfs(to[now]);
    }
}

int main ()
{
    vector<int> v;
    int m,x;
    n = rit();
    m = rit();
    base = (1<<n);
    for (int i=0;i<m;++i)
    {
        x = rit();
        v.push_back(x);
        to[x] = x+base;
        to2[base-1-x] = x+1;
        //G[x].push_back(x+base);
        //G[ (base-1)-x + base ].push_back(x);
    }
    int ans=0;
    for (int i=0;base>i;i++)
    {
        if (to[i] == i+base && !vis[i])
        {
            dfs(i);
            ++ans;
        }
    }
    printf("%d\n",ans);
}