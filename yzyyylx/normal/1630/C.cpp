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

ll T,n,m,K,pp,ans,num[N],L[N],R[N];
P pi[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,k,t,l,r,p,q;
	T=1;
	while(T--)
	{
		pp=ans=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++) L[i]=n,R[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			Min(L[num[i]],i);
			Max(R[num[i]],i);
		}
		for(i=1;i<=n;i++)
		{
			if(R[i]<=L[i]+1) continue;
			pi[++pp]=mp(L[i],R[i]);
		}
		sort(pi+1,pi+pp+1);
		pi[pp+1].fi=INF;
		for(i=1;i<=pp;i=j)
		{
			r=0,t=pi[i].se;
			for(j=i;;j++)
			{
				if(pi[j].fi>r && r<t) r=t,ans--;
				if(pi[j].fi>r) break;
				Max(t,pi[j].se);
			}
//			cout<<i<<" "<<j<<" "<<r-pi[i].fi<<" "<<ans<<endl;
			ans+=r-pi[i].fi;
		}
		printf("%lld\n",ans);
	}
}