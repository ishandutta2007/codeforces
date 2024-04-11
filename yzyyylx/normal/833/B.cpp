#include<iostream>
#include<cstdio>
#define mid ((l+r)>>1)
#define N 35010
using namespace std;

int n,k,num[N],last[N],pos[N],dp[N][60],tt=1,tmp;
struct Node
{
	int ls,rs,mx,sum;
} node[N<<1];

void build(int now,int l,int r)
{
	if(l==r) return;
	if(l<=mid)
	{
		node[now].ls=++tt;
		build(tt,l,mid);
	}
	if(mid<r)
	{
		node[now].rs=++tt;
		build(tt,mid+1,r);
	}
}

void add(int now,int l,int r,int u,int v,int w)
{
//	if(now==1) cout<<l<<' '<<r<<" "<<u<<" "<<v<<endl;
	if(l==u&&v==r)
	{
		node[now].sum+=w;
		return;
	}
	if(u<=mid)
	{
		add(node[now].ls,l,mid,u,min(mid,v),w);
	}
	if(mid<v)
	{
		add(node[now].rs,mid+1,r,max(mid+1,u),v,w);
	}
	node[now].mx=max(node[node[now].ls].mx+node[node[now].ls].sum,node[node[now].rs].mx+node[node[now].rs].sum);
}

void ql(int now,int l,int r,int u)
{
	node[now].sum=node[now].mx=0;
	if(l==r) return;
	if(l<=mid)
	{
		ql(node[now].ls,l,mid,u);
	}
	if(mid<r)
	{
		ql(node[now].rs,mid+1,r,u);
	}
}

void chg(int now,int l,int r,int u,int v)
{
	if(l==r)
	{
		node[now].mx=v;
		return;
	}
	int res=0;
	if(u<=mid)
	{
		chg(node[now].ls,l,mid,u,v);
	}
	else
	{
		chg(node[now].rs,mid+1,r,u,v);
	}
	node[now].mx=max(node[node[now].ls].mx+node[node[now].ls].sum,node[node[now].rs].mx+node[node[now].rs].sum);
}

void out(int now,int l,int r)
{
	printf("%d<%d %d>%d %d\n",now,l,r,node[now].mx,node[now].sum);
	if(l==r) return;
	if(l<=mid) out(node[now].ls,l,mid);
	if(mid<r) out(node[now].rs,mid+1,r);
}

int main()
{
	int i,j;
	cin>>n>>k;
	for(i=1; i<=n; i++)
	{
		scanf("%d",&num[i]);
		if(!pos[num[i]]) tmp++;
		last[i]=pos[num[i]];
		pos[num[i]]=i;
		dp[i][1]=tmp;
	}
//	for(i=1;i<=n;i++) cout<<dp[i][1]<<" ";puts("");
	build(1,1,n);
	for(i=2; i<=k; i++)
	{
		ql(1,1,n,i-1);
//		out(1,1,n);puts("");
		for(j=1;j<i;j++) chg(1,1,n,j,dp[j][i-1]);
//		out(1,1,n);puts("");
		for(j=i; j<=n; j++)
		{
			add(1,1,n,max(i-1,last[j]),j-1,1);
//			out(1,1,n);puts("");
			dp[j][i]=node[1].mx+node[1].sum;
			chg(1,1,n,j,dp[j][i-1]);
//			cout<<dp[j][i]<<" ";
		}
//		puts("");
	}
	cout<<dp[n][k];
}