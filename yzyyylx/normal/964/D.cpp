#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define N 200100
using namespace std;

int n,bb,first[N],size[N],ds[N],ans[N],aa;
struct Bn
{
	int to,next;
}bn[N<<1];
vector<int>vec[N];
queue<int>que;

inline void add(int u,int v)
{
	bb++;
	bn[bb].to=v;
	bn[bb].next=first[u];
	first[u]=bb;
}

void gs(int now,int last)
{
	int p,q;
	size[now]=1;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		gs(bn[p].to,now);
		size[now]+=size[bn[p].to];
	}
}

void dfs(int now,int last)
{
	int p;
	for(p=first[now];p!=-1;p=bn[p].next)
	{
		if(bn[p].to==last) continue;
		if(size[bn[p].to]%2)
		{
			vec[now].push_back(bn[p].to);
			ds[bn[p].to]++;
		}
		else
		{
			vec[bn[p].to].push_back(now);
			ds[now]++;
		}
		dfs(bn[p].to,now);
	}
}

int main()
{
	memset(first,-1,sizeof(first));
	int i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p);
		if(p) add(p,i),add(i,p);
	}
	if(n%2==0)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	gs(1,-1);
	dfs(1,-1);
	for(i=1;i<=n;i++)
	{
		if(!ds[i]) que.push(i);
	}
	for(;!que.empty();)
	{
		p=que.front();
		que.pop();
		printf("%d\n",p);
		for(i=0;i<vec[p].size();i++)
		{
			ds[vec[p][i]]--;
			if(!ds[vec[p][i]])
			{
				que.push(vec[p][i]);
			}
		}
	}
}