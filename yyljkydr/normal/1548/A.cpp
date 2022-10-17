#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,m,q;

set<int>s[N];

int ans;

void ins(int x)
{
    if(s[x].size()&&*s[x].rbegin()>x)
        ans--;
}

void del(int x)
{
    if(s[x].size()&&*s[x].rbegin()>x)
        ans++;
}

void adde(int x,int y)
{
    del(x),del(y);
    s[x].insert(y);
    s[y].insert(x);
    ins(x),ins(y);
}

void rmve(int x,int y)
{
    del(x),del(y);
    s[x].erase(y);
    s[y].erase(x);
    ins(x),ins(y);
}

int main()
{
    scanf("%d%d",&n,&m);
    ans=n;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        adde(u,v);
    }
    scanf("%d",&q);
    while(q--)
    {
        int op,u,v;
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d%d",&u,&v);
            adde(u,v);
        }
        else if(op==2)
        {
            scanf("%d%d",&u,&v);
            rmve(u,v);
        }
        else
            printf("%d\n",ans);
    }
}