#pragma GCC optimize(4)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e5+5,maxsum=26;
int n,m;
char s[maxn];
char out[maxn];
struct segmentree
{
	static const int maxn=1e5+5;
	int ls[maxn<<1][maxsum+1],rs[maxn<<1][maxsum+1],sum[maxn<<1][maxsum+1],tag[maxn<<1][maxsum+1],cnt[maxsum+1]={0},cov[maxn<<1][maxsum+1];
	inline void pushup(int bh,int u)
	{
		sum[u][bh]=sum[ls[u][bh]][bh]+sum[rs[u][bh]][bh];
	}
	inline void pushdown(int bh,int u,int l,int r)
	{
		if(cov[u][bh]!=0)
		{
			tag[ls[u][bh]][bh]=tag[rs[u][bh]][bh]=sum[ls[u][bh]][bh]=sum[rs[u][bh]][bh]=cov[u][bh]=0;
			cov[ls[u][bh]][bh]=cov[rs[u][bh]][bh]=1;
		}
		if(tag[u][bh]!=0)
		{
			int mid=(l+r)>>1;
			tag[ls[u][bh]][bh]+=tag[u][bh];
			tag[rs[u][bh]][bh]+=tag[u][bh];
			sum[ls[u][bh]][bh]+=(mid-l+1)*tag[u][bh];
			sum[rs[u][bh]][bh]+=(r-mid)*tag[u][bh];
			tag[u][bh]=0;
		}
	}
	inline void build(int bh,int &u,int l,int r)
	{
		u=++cnt[bh];
		if(l==r)
		{
			if(s[l]==bh+'a'-1)
			{
				sum[u][bh]=1;
			}
			else sum[u][bh]=0;
			return ;
		}
		else
		{
			int mid=(l+r)>>1;
			build(bh,ls[u][bh],l,mid);
			build(bh,rs[u][bh],mid+1,r);
			pushup(bh,u);
		}
	}
	inline void update(int bh,int u,int l,int r,int x,int y,int v)
	{
		if(x<=l&&y>=r)
		{
			sum[u][bh]+=v*(r-l+1);
			tag[u][bh]+=v;
			return ;
		}
		else
		{
			pushdown(bh,u,l,r);
			int mid=(l+r)>>1;
			if(x<=mid)
			{
				update(bh,ls[u][bh],l,mid,x,y,v);
			}
			if(y>mid)
			{
				update(bh,rs[u][bh],mid+1,r,x,y,v);
			}
			pushup(bh,u);
		}
	}
	inline int query(int bh,int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)
		{
			return sum[u][bh];
		}
		else
		{
			pushdown(bh,u,l,r);
			int mid=(l+r)>>1;
			int val=0;
			if(x<=mid)
			{
				val+=query(bh,ls[u][bh],l,mid,x,y);
			}
			if(y>mid)
			{
				val+=query(bh,rs[u][bh],mid+1,r,x,y);
			}
			return val;
		}
	}
	inline void cover(int u,int l,int r,int x,int y)
	{
		if(x<=l&&y>=r)
		{
			memset(sum[u],0,sizeof(sum[u]));
			memset(tag[u],0,sizeof(tag[u]));
			memset(cov[u],0x3f,sizeof(cov[u]));
			return ;
		}
		else
		{
			for(int i=1;i<=maxsum;++i)pushdown(i,u,l,r);
			int mid=(l+r)>>1;
			if(x<=mid)
			{
				cover(ls[u][1],l,mid,x,y);
			}
			if(y>mid)
			{
				cover(rs[u][1],mid+1,r,x,y);
			}
			for(int i=1;i<=maxsum;++i)pushup(i,u);
		}
	}
} tree;
inline void dfs(int bh,int u,int l,int r)
{
	if(l==r)
	{
		if(tree.sum[u][bh]==1)
		{
			out[l]='a'+bh-1;
		}
		return ;
	}
	tree.pushdown(bh,u,l,r);//!!
	int mid=(l+r)>>1;
	dfs(bh,tree.ls[u][bh],l,mid);
	dfs(bh,tree.rs[u][bh],mid+1,r);
}
inline void output()
{
	for(int i=1; i<=maxsum; ++i)
	{
		dfs(i,1,1,n);
	}
	printf("%s\n",out+1);
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1; i<=maxsum; ++i)
	{
		int temp=0;
		tree.build(i,temp,1,n);
	}
	for(int i=1; i<=m; ++i)
	{
		int l,r,cntt=0;
		scanf("%d%d",&l,&r);
		int ans[maxsum+5];
		memset(ans,0,sizeof(ans));
		bool ok=true;
		for(int j=1; j<=maxsum; ++j)
		{
			ans[j]=tree.query(j,1,1,n,l,r);
			if(ans[j]%2==1)
			{
				if(cntt==0)cntt=j;
				else
				{
					ok=false;
					break;
				}
			}
		}
		if(!ok)continue;
		tree.cover(1,1,n,l,r);
		if(cntt!=0)
		{
			int mid=(l+r)>>1;
			tree.update(cntt,1,1,n,mid,mid,1);
		}
		int posl=l,posr=r;
		for(int j=1; j<=maxsum; ++j)
		{
			if(ans[j]>1)
			{
				ans[j]/=2;
				tree.update(j,1,1,n,posl,posl+ans[j]-1,1);
				tree.update(j,1,1,n,posr-ans[j]+1,posr,1);
				posl+=ans[j],posr-=ans[j];
			}
		}
	}
	output();
	return 0;
}