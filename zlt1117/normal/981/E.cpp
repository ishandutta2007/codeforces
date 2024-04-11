#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
const int maxn=10005;
bitset<maxn>ans;
int n,q,x,y,v;
// s|=(s<<p);
/// 
struct segmentree
{
	#define ls u<<1
	#define rs u<<1|1
	bitset<maxn>s[maxn<<2];
	vector<int>tag[maxn<<2];/// 
	inline void update(int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)
		{
			tag[u].push_back(v);///O(nlogn) 
			return ;
		}
		else
		{
			int mid=(l+r)>>1;
			if(x<=mid)update(ls,l,mid,x,y,v);
			if(y>mid)update(rs,mid+1,r,x,y,v);
		}
	}
	inline void dfs(int u,int l,int r)
	{
		s[u].set(0);
		s[u]|=s[u>>1];
		for(int i=0;i<tag[u].size();++i)
		{
			s[u]=s[u]|(s[u]<<tag[u][i]);
		}
		if(l==r)
		{
			ans|=s[u];
			return ;
		}
		else
		{
			int mid=(l+r)>>1;
			dfs(ls,l,mid);
			dfs(rs,mid+1,r);
		}
	}
}tree;
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=q;++i)
	{
		scanf("%d%d%d",&x,&y,&v);
		tree.update(1,1,n,x,y,v);
	}
	tree.dfs(1,1,n);
	int cnt=0;
	for(int i=1;i<=n;++i)if(ans[i])cnt++;
	printf("%d\n",cnt);
	for(int i=1;i<=n;++i)if(ans[i])printf("%d ",i);
	printf("\n");
	return 0;//
}