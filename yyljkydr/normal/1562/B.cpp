#include<bits/stdc++.h>
using namespace std;

const int N=55;

int T,k;

char s[N];

bool isprime(int x)
{
    if(x==1)
        return 0;
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return 0;
    return 1;
}

int ans;

typedef long long ll;

int isp[100001];

ll fans;

void dfs(int x,ll v,int tot)
{
    if(tot==4)
        return;
    if(x==k+1)
    {
        if(v==0)
            return;
        if(tot>ans)
            return;
        if(!isp[v])
        {
            ans=tot;
            fans=v;
        }
        return;
    }
    dfs(x+1,v,tot);
    dfs(x+1,v*10+s[x]-'0',tot+1);
}

int main()
{
    for(int i=1;i<=10000;i++)
        isp[i]=isprime(i);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&k);
        scanf("%s",s+1);
        ans=k+1;
        dfs(1,0,0);
        printf("%d\n%lld\n",ans,fans);
    }
}