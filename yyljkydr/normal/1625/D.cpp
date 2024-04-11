#include<bits/stdc++.h>
using namespace std;

const int N=3e5+1e3+7;

int T;

int n,k;

int a[N],tr[N*30][2],tot;

map<int,array<vector<int>,2>>v;

map<int,int>pos;

void ins(int v)
{
    int x=0;
    for(int i=30;i>=0;i--)
    {
        int p=v>>i&1;
        if(tr[x][p]==-1)
        {
            tr[x][p]=++tot;
            for(int j=0;j<2;j++)
                tr[tot][j]=-1;
        }
        x=tr[x][p];
    }
}

int qry(int v)
{
    int x=0,ret=0;
    for(int i=30;i>=0;i--)
    {
        int p=v>>i&1;
        if(tr[x][p^1]!=-1)
            x=tr[x][p^1],ret|=(1<<i);
        else
            x=tr[x][p];
    }
    return ret;
}

int main()
{
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),pos[a[i]]=i;
    if(!k)
    {
        printf("%d\n",n);
        for(int i=1;i<=n;i++)
            printf("%d%c",i," \n"[i==n]);
        return 0;
    }
    int b=-1;
    for(int i=30;i>=0;i--)
        if(k>>i&1)
        {
            b=i;
            break;
        }
    int bs=(((1<<30)-1)>>b+1)<<b+1;
    for(int i=1;i<=n;i++)
        v[a[i]&bs][a[i]>>b&1].push_back(a[i]);
    vector<int>ans;
    for(auto [up,s]:v)
    {
        for(int i=0;i<2;i++)
            tr[0][i]=-1;
        if(!s[0].size()||!s[1].size())
        {
            if(s[0].size())
                ans.push_back(pos[s[0][0]]);
            else
                ans.push_back(pos[s[1][0]]);
            continue;
        }
        tot=0;
        int fd=0;
        for(auto x:s[0])
            ins(x);
        for(auto x:s[1])
        {
            int mx=qry(x);
            if(mx>=k)
            {
                ans.push_back(pos[x]);
                ans.push_back(pos[mx^x]);
                fd=1;
                break;
            }
        }
        if(!fd)
            ans.push_back(pos[s[0][0]]);
    }
    if(ans.size()>=2)
    {
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++)
            printf("%d%c",ans[i]," \n"[i+1==ans.size()]);
    }
    else
        puts("-1");
}