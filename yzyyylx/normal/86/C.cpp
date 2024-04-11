#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define ll long long
#define N 110
#define M 1000000009
#define L 1010
using namespace std;

ll T,n,m,dp[N][L][15],ans,tt,tmp,zh[110];
char str[L];
struct Node
{
	ll son[4],fail,len,hl;
} node[N];
queue<ll>que;

inline void add(ll v)
{
	ll now=0,u,i,t;
	for(i=1,t=strlen(str+1); i<=t; i++)
	{
		u=zh[str[i]];
		if(!node[now].son[u])
		{
			node[now].son[u]=++tt;
			node[tt].len=node[now].len+1;
		}
		now=node[now].son[u];
	}
	node[now].hl=node[now].len;
}

inline void build()
{
	ll i,j,k,p,q;
	for(i=0; i<4; i++)
	{
		if(node[0].son[i])
		{
			node[node[0].son[i]].fail=0;
			que.push(node[0].son[i]);
		}
	}
	for(; !que.empty();)
	{
		p=que.front();
		que.pop();
		for(i=0; i<4; i++)
		{
			if(node[p].son[i])
			{
				for(k=node[p].fail; k&&!node[k].son[i]; k=node[k].fail);
				node[node[p].son[i]].fail=node[k].son[i];
				node[node[p].son[i]].hl=max(node[node[p].son[i]].hl,node[node[k].son[i]].hl);
				que.push(node[p].son[i]);
			}
			else
			{
				node[p].son[i]=node[node[p].fail].son[i];
			}
		}
	}
}

ll dfs(ll now,ll len,ll sp)
{
	if(sp>10) return 0;
	if(len>n) return node[now].hl>=sp;
	if(dp[now][len][sp]!=-1) return dp[now][len][sp];
	ll i,j,k,res=0,t=sp;
	if(node[now].hl>=sp) sp=0;
	for(i=0;i<4;i++)
	{
		res=(res+dfs(node[now].son[i],len+1,sp+1))%M;
	}
	return dp[now][len][t]=res;
}

int main()
{
	memset(dp,-1,sizeof(dp));
	zh['A']=0,zh['C']=1,zh['G']=2,zh['T']=3;
	ll i,j;
	cin>>n>>m;
	for(i=1; i<=m; i++)
	{
		scanf("%s",str+1);
		add(i);
	}
	build();
	/////
	cout<<dfs(0,1,0);
}