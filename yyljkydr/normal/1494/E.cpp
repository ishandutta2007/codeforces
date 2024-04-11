#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,m;

unordered_map<int,int>g[N];

int even,odd;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        char op[2];
        scanf("%s",op);
        if(op[0]=='+')
        {
            int u,v;
            char ch[2];
            scanf("%d%d",&u,&v);
            scanf("%s",ch);
            g[u][v]=ch[0];
            if(g[v].find(u)!=g[v].end())
            {
                odd++;
                if(g[v][u]==g[u][v])
                    even++;
            }
        }
        if(op[0]=='-')
        {
            int u,v;
            scanf("%d%d",&u,&v);
            if(g[v].find(u)!=g[v].end())
            {
                odd--;
                if(g[v][u]==g[u][v])
                    even--;
            }
            g[u].erase(v);
        }
        if(op[0]=='?')
        {
            int k;
            scanf("%d",&k);
            if(k&1)
                puts(odd?"YES":"NO");
            else
                puts(even?"YES":"NO");
        }
    }
}