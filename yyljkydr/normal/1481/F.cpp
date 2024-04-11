#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,x;

vector<int>g[N];

int dep[N],cnt[N];

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

vector<pii>v;

vector<int>lev[N],lef[N];

bool f[501][N];

int to[501][N],mxd,nd[N],ct[N],cho[N];

char ans[N];

void dfs(int x,int f)
{
    dep[x]=dep[f]+1;
    lev[dep[x]].push_back(x);
    mxd=max(mxd,dep[x]);
    if(!g[x].size())
        lef[dep[x]].push_back(x);
    cnt[dep[x]]++;
    for(auto v:g[x])
    {
        if(v==f)
            continue;
        dfs(v,x);
    }
}

int main()
{
    scanf("%d%d",&n,&x);
    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%d",&p);
        g[p].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        ct[cnt[i]]++;
    for(int i=1;i<=n;i++)
        if(ct[i])
            v.push_back(mp(i,ct[i]));
    f[0][0]=1;
    for(int i=0;i<v.size();i++)
    {
        int s=v[i].fs,y=v[i].sd;
        for(int t=0;t<=x;t++)
            if(f[i][t])
            {
                f[i+1][t]=1;
                to[i+1][t]=0;
            }
        for(int j=1;j<=y;j*=2)
        {
            for(int t=x;t>=j*s;t--)
                if(f[i+1][t-j*s])
                {
                    f[i+1][t]=1;
                    to[i+1][t]=to[i+1][t-j*s]+j*s;
                }
            y-=j;
        }
        if(y)
            for(int t=x;t>=y*s;t--)
                if(f[i+1][t-y*s])
                {
                    f[i+1][t]=1;
                    to[i+1][t]=to[i+1][t-y*s]+y*s;
                }
    }
    int tot=v.size();
    if(f[tot][x])
    {
        printf("%d\n",mxd);
        int y=x;
        for(int i=tot;i>=1;i--)
        {
            int s=to[i][y];
            nd[v[i-1].fs]=s/v[i-1].fs;
            y-=s;
        }
        for(int i=1;i<=n;i++)
            if(nd[cnt[i]])
            {
                nd[cnt[i]]--;
                for(auto x:lev[i])
                    ans[x]='a';
            }
            else
                for(auto x:lev[i])
                    ans[x]='b';
        puts(ans+1);
    }
    else
    {
        printf("%d\n",mxd+1);
        int res;
        for(int i=x;i>=0;i--)
            if(f[tot][i])
            {
                res=x-i;
                break;
            }
        int y=x-res;
        for(int i=tot;i>=1;i--)
        {
            int s=to[i][y];
            nd[v[i-1].fs]=s/v[i-1].fs;
            y-=s;
        }
        for(int i=1;i<=n;i++)
            if(nd[cnt[i]])
            {
                nd[cnt[i]]--;
                for(auto x:lev[i])
                    ans[x]='a';
                cho[i]=1;
            }
            else
                for(auto x:lev[i])
                    ans[x]='b';
        for(int i=1;i<=n;i++)
            if(!cho[i]&&(int)lef[i].size()>=res)
            {
                for(int j=0;j<res;j++)
                    ans[lef[i][j]]='a';
                break;
            }
        puts(ans+1);
    }
}