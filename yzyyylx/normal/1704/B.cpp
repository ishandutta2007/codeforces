#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 200100
#define M 
using namespace std;

ll T,n,m,num[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,mn,mx;
	cin>>T;
	while(T--)
	{
		ll ans=0;
		scanf("%lld%lld",&n,&m);m=m*2;
		for(i=1;i<=n;i++) scanf("%lld",&num[i]);
		mn=INF,mx=-INF;
		for(i=1;i<=n;i++)
		{
			Min(mn,num[i]);
			Max(mx,num[i]);
//			cout<<"      "<<mn<<" "<<mx<<endl;
			if(mx-mn>m)
			{
//				cout<<" "<<i<<endl;
				mn=mx=num[i];
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
}