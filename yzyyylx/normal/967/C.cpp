#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define mid ((l+r)>>1)
#define N 100100
using namespace std;

ll n,m,clt,cdt,lt[N],dt[N],V,Q,ans;

int main()
{
	ll i,j,p,q,u,v,k,l,r;
	cin>>n>>m>>clt>>cdt>>V;
	for(i=1; i<=clt; i++)
	{
		scanf("%lld",&lt[i]);
	}
	for(i=1; i<=cdt; i++)
	{
		scanf("%lld",&dt[i]);
	}
	cin>>Q;
	for(i=1; i<=Q; i++)
	{
		ans=INF;
		scanf("%lld%lld%lld%lld",&q,&p,&v,&u);
		if(q==v)
		{
			printf("%lld\n",abs(p-u));
			continue;
		}
		for(l=1,r=clt+1; l<r;)
		{
			lt[mid]<p?l=mid+1:r=mid;
		}
		if(l!=clt+1)
		{
			k=lt[l];
			ans=min(ans,abs(k-p)+abs(k-u)+abs(v-q));
		}
		if(l!=1)
		{
			k=lt[l-1];
			ans=min(ans,abs(k-p)+abs(k-u)+abs(v-q));
		}
		
		for(l=1,r=cdt+1; l<r;)
		{
			dt[mid]<p?l=mid+1:r=mid;
		}
		if(l!=cdt+1)
		{
			k=dt[l];
			ans=min(ans,abs(k-p)+abs(k-u)+(abs(v-q)+V-1)/V);
		}
		if(l!=1)
		{
			k=dt[l-1];
			ans=min(ans,abs(k-p)+abs(k-u)+(abs(v-q)+V-1)/V);
		}
		printf("%lld\n",ans);
	}
}