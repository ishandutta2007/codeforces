#pragma GCC optimize(2)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<queue>
#include<bitset>
#define ll long long
#define ull unsigned long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
int n,Q,a[maxn],siz,pw[maxn],ans[maxn];
struct question
{
	int l,x,bh;
	inline bool operator<(const question &rhs)const
	{
		return l<rhs.l;
	}
}q[maxn];
struct XXJ
{
	int a[21];
	inline void insert(int x)
	{
		for(int i=20;i>=0;--i)
		{
			if(!((x>>i)&1))continue;
			else 
			{
				if(a[i])x^=a[i];
				else
				{
					a[i]=x;
					siz++;
					return ;
				}
			}
		}
	}
	inline int query(int sum,int x)
	{
		for(int i=20;i>=0;--i)
		{
			if(a[i]&&((x>>i)&1))x^=a[i];
		}
		if(x==0)return pw[sum-siz];
		else return 0;
	}
}xxj;
int main()
{
	scanf("%d",&n);
	scanf("%d",&Q);
	pw[0]=1;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),pw[i]=(pw[i-1]*2)%mod;
	for(int i=1;i<=Q;++i)
	{
		scanf("%d%d",&q[i].l,&q[i].x);
		q[i].bh=i;
	}
	sort(q+1,q+Q+1);
	int last=0;
	for(int i=1;i<=Q;++i)
	{
		for(int j=last+1;j<=q[i].l;++j)
		{
			xxj.insert(a[j]);
			last=j;
		}
		ans[q[i].bh]=xxj.query(q[i].l,q[i].x);
	}
	for(int i=1;i<=Q;++i)printf("%d\n",ans[i]);
	return 0;
}