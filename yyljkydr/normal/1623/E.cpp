#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

int n,k;

char s[N];

int ok[N];

int ls[N],rs[N];

vector<int>v;

int dep[N];

void dfs(int x)
{
    if(!x)
        return;
    dfs(ls[x]);
    v.push_back(x);
    dfs(rs[x]);
}

int cho[N];

void calc(int x,int last)
{
    if(ls[x])
    {
        dep[ls[x]]=dep[x]+1;
        calc(ls[x],last);
    }
    if(ls[x]&&cho[ls[x]])
        cho[x]=1;
    else
    {
        if(dep[x]-dep[last]<=k&&cho[last]&&ok[x])
            cho[x]=1,k-=dep[x]-dep[last];
    }
    if(rs[x])
    {
        dep[rs[x]]=dep[x]+1;
        calc(rs[x],x);
    }
}

int main()
{
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&ls[i],&rs[i]);
    dfs(1);
    for(int i=n-2;i>=0;i--)
        ok[v[i]]=(s[v[i]]==s[v[i+1]]?ok[v[i+1]]:(s[v[i]]<s[v[i+1]]));
    cho[0]=1;
    dep[1]=1;
    calc(1,0);
    string ans;
    for(auto p:v)
    {
        ans+=s[p];
        if(cho[p])
            ans+=s[p];
    }
    printf("%s\n",ans.c_str());
}