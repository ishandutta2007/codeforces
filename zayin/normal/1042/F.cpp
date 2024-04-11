#include<bits/stdc++.h>
#include<algorithm>
#define maxn 1000050
using namespace std;

int n,m,rt;

vector<int> G[maxn];

void join(int u,int v)
{
    G[u].push_back(v);
    G[v].push_back(u);
}

void init()
{
    scanf("%d%d",&n,&m);
    for (int k=1;k<n;++k)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        join(u,v);
    }
}

int ans;
int mx[maxn];

bool cmp(int i,int j)
{
    return mx[i]<mx[j];
}

void dfs(int i,int fa=0)
{
    if (G[i].size()==1)    mx[i]=0;
    for (auto j:G[i])
    {
        if (fa==j)  continue;
        dfs(j,i);
    }
    sort(G[i].begin(),G[i].end(),cmp);

    // cout<<i<<":";
    // for (auto j:G[i])   cout<<j<<" "; cout<<endl;

    for (int k=(i!=rt);k<G[i].size();++k)
    {
        mx[i]=max(mx[i],mx[G[i][k]]+1);
        if (k!=G[i].size()-1&&mx[G[i][k]]+mx[G[i][k+1]]+2>m)
        {
            ans+=G[i].size()-1-k;
            // cout<<"~ "<<k<<endl;
            break;
        }
    }
    // cout<<i<<" "<<mx[i]<<endl;
}

void solve()
{
    memset(mx,0x80,sizeof(mx));
    for (rt=1;G[rt].size()==1;++rt);
    dfs(rt);
    if (mx[rt]>0)
        ++ans;
    printf("%d\n",ans);
}

int main()
{
    // freopen("c.in","r",stdin);
    // freopen("c.out","w",stdout);
    init();
    solve();
    return 0;
}