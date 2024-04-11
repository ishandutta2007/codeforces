#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define MN 200
#define B1 23
#define B2 29 
#define N 200100
#define M1 1000000007
#define M2 1000000009
using namespace std;

ll T,n,m,K,ans,num[N],cnt[N],qz[N];

inline void work(ll u,ll v)
{
	ll i,gg=K,last=1,t=0;
	for(i=1;i<=n;i++)
	{
		if(num[i]>=u && num[i]<=v) t++;
		else t--;
		if(gg>1 && t==1)
		{
			printf("%lld %lld\n",last,i);
			last=i+1,t=0,gg--;
		}
	}
	printf("%lld %lld\n",last,n);
}

int main()
{
	ll i,j,k,t,l,r,p,q;
	cin>>T;
	while(T--)
	{
		ans=INF;
		scanf("%lld%lld",&n,&K);
		for(i=1;i<=n;i++) cnt[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			cnt[num[i]]++;
		}
		for(i=1;i<=n;i++) qz[i]=qz[i-1]+cnt[i];
		for(l=r=1;l<=n;l++)
		{
			for(;r<=n && 2*(qz[r]-qz[l-1])<n+K;r++);
			if(r>n) break;
			if(r-l<ans) ans=r-l,p=l,q=r;
		}
		printf("%lld %lld\n",p,q);
		work(p,q);
	}
}