#pragma GCC optimize(3,"inline","Ofast")
#include<bits/stdc++.h>
using namespace std;
const int N = 35010;
int mp[N],dp[60][N],nw,seg[N*8],add[N*8],pos[N],las[N];
void push_up(int k)
{seg[k]=max(seg[k<<1],seg[k<<1|1]);}
void push_down(int k)
{
	if(add[k])
	{
		seg[k<<1]+=add[k];
		seg[k<<1|1]+=add[k];
		add[k<<1]+=add[k];
		add[k<<1|1]+=add[k];
		add[k]=0;
	}
}
void build(int l,int r,int k)
{
	if(l==r)
	{
		seg[k]=dp[nw][l-1];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,k<<1);
	build(mid+1,r,k<<1|1);
	push_up(k);
}
void cg(int L,int R,int l,int r,int k)
{
	if(l>R||r<L)return;
	push_down(k);
	if(L<=l&&r<=R)
	{
		++seg[k];
		++add[k];
		return;
	}
	int mid=(l+r)>>1;
	cg(L,R,l,mid,k<<1);
	cg(L,R,mid+1,r,k<<1|1);
	push_up(k);
}
int ask(int L,int R,int l,int r,int k)
{
	if(l>R||r<L)return 0;
	push_down(k);
	if(L<=l&&r<=R)return seg[k];
	int mid=(l+r)>>1;
	return max(ask(L,R,l,mid,k<<1),ask(L,R,mid+1,r,k<<1|1));
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&mp[i]);
		las[i]=pos[mp[i]];
		pos[mp[i]]=i;
	}
	for(int i=1;i<=k;i++)
	{		
		memset(seg,0,sizeof seg),
		memset(add,0,sizeof add);
		nw=i-1;build(1,n,1);
		for(int x=1;x<=n;x++)
		{
			cg(las[x]+1,x,1,n,1);
			dp[i][x]=ask(i,x,1,n,1);
		}
	}
	cout<<dp[k][n];
}