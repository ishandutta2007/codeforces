#include<bits/stdc++.h>
#define L 810
#define N 2010
#define M 20010
using namespace std;

int n,tt,l1,l2,dp[N][M],to[N][M];
char a[L],b[L];
struct Node
{
    int to[10],sum[N],fail;
}node[M];
queue<int>que;

inline int get(int u,int v)
{
    if(!node[u].to[v]) node[u].to[v]=++tt;
    return node[u].to[v];
}

inline void in()
{
    int i,j,k,u,v,p,q,t;
    u=v=1;
    if(l1==l2)
    {
	for(i=1;i<=l1;i++)
	{
	    p=a[i]-'0',q=b[i]-'0';
	    if(u==v)
	    {
		for(j=p+1;j<q;j++) node[get(u,j)].sum[l1-i]++;
		u=get(u,p),v=get(v,q);
	    }
	    else
	    {
		for(j=p+1;j<=9;j++) node[get(u,j)].sum[l1-i]++;
		for(j=0;j<q;j++) node[get(v,j)].sum[l1-i]++;
		u=get(u,p),v=get(v,q);
	    }
	}
	node[u].sum[0]++;
	if(u!=v) node[v].sum[0]++;
    }
    else
    {
	for(i=1;i<=l1;i++)
	{
	    p=a[i]-'0';
	    for(j=p+1;j<=9;j++) node[get(u,j)].sum[l1-i]++;
	    u=get(u,p);
	}
	node[u].sum[0]++;

	for(i=1;i<=l2;i++)
	{
	    q=b[i]-'0';
	    for(j=(i==1);j<q;j++) node[get(v,j)].sum[l2-i]++;
	    v=get(v,q);
	}
	node[v].sum[0]++;

	for(i=1;i<=9;i++)
	{
	    for(j=l1+1;j<l2;j++)
	    {
		node[get(1,i)].sum[j-1]++;
	    }
	}
    }
}

inline void build()
{
    int i,j,p,q;
    for(i=0;i<=9;i++)
    {
	if(node[1].to[i])
	{
	    node[node[1].to[i]].fail=1;
	    que.push(node[1].to[i]);
	}
	else node[1].to[i]=1;
    }
    for(;!que.empty();)
    {
	q=que.front();
	que.pop();
	for(i=0;i<=l2;i++) node[q].sum[i]+=node[node[q].fail].sum[i];
	for(i=0;i<=9;i++)
	{
	    if(node[q].to[i])
	    {
		node[node[q].to[i]].fail=node[node[q].fail].to[i];
		que.push(node[q].to[i]);
	    }
	    else node[q].to[i]=node[node[q].fail].to[i];
	}
    }
    for(i=1;i<=tt;i++)
    {
	for(j=1;j<=n;j++)
	{
//	    if(node[1].sum[j]) puts("gg");
	    node[i].sum[j]+=node[i].sum[j-1];
	}
    }
}

int dfs(int now,int pos)
{
    if(now==n) return 0;
    if(dp[now][pos]!=-1) return dp[now][pos];
    int i,j,t,res=-1;
    for(i=0;i<=9;i++)
    {
	t=dfs(now+1,node[pos].to[i])+node[node[pos].to[i]].sum[n-now-1];
	if(t>res)
	{
	    to[now][pos]=i;
	    res=t;
	}
    }
    return dp[now][pos]=res;
}

int main()
{
    memset(dp,-1,sizeof(dp));
    int i,j,k,t;
    scanf("%s",a+1);l1=strlen(a+1);
    scanf("%s",b+1);l2=strlen(b+1);
    cin>>n;
    tt=1,in();
    build();
    cout<<dfs(0,1)<<endl;
    for(i=0,t=1;i<n;i++)
    {
//	cerr<<dp[i][t]<<endl;
	printf("%d",to[i][t]);
	t=node[t].to[to[i][t]];
    }
}