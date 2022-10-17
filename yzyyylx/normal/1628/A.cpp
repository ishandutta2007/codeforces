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

ll T,n,m,num[N],ps[N];
vector<ll>pos[N],ans;

ll gcd(ll u,ll v){return v?gcd(v,u%v):u;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		ans.clear();
		scanf("%lld",&n);
		for(i=0;i<=n;i++) pos[i].clear(),ps[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			pos[num[i]].push_back(i);
		}
		for(i=1;i<=n;)
		{
			t=i;
			for(j=0;;j++)
			{
				for(;ps[j]<pos[j].size() && pos[j][ps[j]]<i;ps[j]++);
				if(ps[j]==(ll)pos[j].size()) break;
				Max(t,pos[j][ps[j]]);
			}
			i=t+1;
			ans.push_back(j);
		}
		printf("%lld\n",(ll)ans.size());
		for(i=0;i<ans.size();i++) printf("%lld ",ans[i]);puts("");
	}
}