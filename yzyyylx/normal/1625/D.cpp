#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define BB 29
#define N 300100
using namespace std;
 
int T,n,m,K,num[N],tt=1;
struct Node
{
	int son[2],cnt,gg;
} node[N*BB];
vector<int>ans;
 
inline void in(int u,int v)
{
	int i,t,now=1;
	for(i=BB;i>=0;i--)
	{
		node[now].cnt++;
		if((1 << i)&u) t=1;
		else t=0;
		if(!node[now].son[t]) node[now].son[t]=++tt,node[tt].gg=v;
		now=node[now].son[t];
	}
	node[now].cnt++;
}
 
bool find(int u,int v,int B)
{
	if(B<0)
	{
		ans.push_back(node[u].gg);
		ans.push_back(node[v].gg);
		return 1;
	}
	if((1 << B)&m)
	{
		if(node[u].son[0] && node[v].son[1] && find(node[u].son[0],node[v].son[1],B-1)) return 1;
		if(node[u].son[1] && node[v].son[0] && find(node[u].son[1],node[v].son[0],B-1)) return 1;
		return 0;
	}
	else
	{
		if(node[u].son[0] && node[v].son[1])
		{
			ans.push_back(node[node[u].son[0]].gg);
			ans.push_back(node[node[v].son[1]].gg);
			return 1;
		}
		if(node[u].son[1] && node[v].son[0])
		{
			ans.push_back(node[node[u].son[1]].gg);
			ans.push_back(node[node[v].son[0]].gg);
			return 1;
		}
		if(node[u].son[0] && node[v].son[0] && find(node[u].son[0],node[v].son[0],B-1)) return 1;
		if(node[u].son[1] && node[v].son[1] && find(node[u].son[1],node[v].son[1],B-1)) return 1;
		return 0;
	}
}
 
void dfs(int now,int B)
{
	if(B<0)
	{
		ans.push_back(node[now].gg);
		return;
	}
	if((1 << B)>m)
	{
		if(node[now].son[0]) dfs(node[now].son[0],B-1);
		if(node[now].son[1]) dfs(node[now].son[1],B-1);
	}
	else
	{
		if(node[now].cnt==1)
		{
			ans.push_back(node[now].gg);
			return;
		}
		if((1 << B)&m)
		{
			if(!node[now].son[0] || !node[now].son[1])
			{
				ans.push_back(node[now].gg);
				return;
			}
			if(!find(node[now].son[0],node[now].son[1],B-1))
			{
				ans.push_back(node[now].gg);
				return;
			}
		}
		else
		{
			if(node[now].son[0] && node[now].son[1])
			{
				ans.push_back(node[node[now].son[0]].gg);
				ans.push_back(node[node[now].son[1]].gg);
				return;
			}
			if(node[now].son[0]) dfs(node[now].son[0],B-1);
			if(node[now].son[1]) dfs(node[now].son[1],B-1);
		}
	}
}
 
int main()
{
	int i,j;
	cin>>n>>m;
	if(!m)
	{
		cout<<n<<endl;
		for(i=1;i<=n;i++) printf("%d ",i);
		return 0;
	}
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		in(num[i],i);
	}
	dfs(1,BB);
	if(ans.size()==1)
	{
		puts("-1");
		return 0;
	}
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
	{
		printf("%d ",ans[i]);
	}
}