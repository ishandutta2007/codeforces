#include<bits/stdc++.h>
#define maxn 300050
using namespace std;
typedef pair<int,int> pii;

const int B=605;

int n,m;
vector<int> path[maxn];

int belong[maxn],pos[maxn];

vector<pii> nxt[maxn];
int go[maxn];

void init()
{
    scanf("%d%d",&n,&m);
    for (int k,i=0;i<m;++i)
    {
        scanf("%d",&k);
        path[i].resize(k);
        for (int &v:path[i])
            scanf("%d",&v);
    }
}

bool solve()
{
    for (int i=1;i<=n;++i)  belong[i]=-1;
    for (int i=1;i<=n;++i) nxt[i].clear();

    for (int i=0;i<m;++i)
    {
        if (path[i].size()>=B)
        {
            for (int k=0;k<path[i].size();++k)
                belong[path[i][k]]=i,pos[path[i][k]]=k;
            for (int j=0;j<m;++j)
            {
                if (i==j)   continue;
                int p=maxn;
                for (int k=0;k<path[j].size();++k)
                {
                    int v=path[j][k];
                    if (belong[v]!=i)   continue;
                    if (p>pos[v])
                        p=pos[v];
                    else
                        if (p+1==path[i].size()||path[j][k-1]!=path[i][p]||path[j][k]!=path[i][p+1])
                            return 1;
                        else
                            ++p;
                }
            }
        } else
        {
            for (int k=0;k<path[i].size();++k)
                for (int j=0;j<k;++j)
                    nxt[path[i][k]].emplace_back(path[i][j],path[i][j+1]);
        }
    }
    for (int i=1;i<=n;++i)  belong[i]=go[i]=-1;
    for (int i=1;i<=n;++i)
    {
        // cout<<i<<":";
        for (auto p:nxt[i])
        {
            // cout<<"("<<p.first<<","<<p.second<<") ";
            if (belong[p.first]==i&&go[p.first]!=p.second)  
            {
                // cout<<belong[p.first]<<" "<<go[p.first]<<" "<<p.second<<endl;
                return 1;
            }
            belong[p.first]=i;
            go[p.first]=p.second;
        }
        // cout<<endl;
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        init();
        puts(solve()?"Human":"Robot");
    }
    return 0;
}