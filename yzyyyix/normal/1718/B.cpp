#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0z3f3f3f3f3f3f3f3f
#define N 100100
#define M 
using namespace std;

ll T,n,m,num[N],qz[N],feb[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
int main()
{
	ll i,j,t;
	cin>>T;
	while(T--)
	{
		ll sum=0;
		priority_queue<P>pq;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			pq.push(mp(num[i],i));
			sum+=num[i];
		}
		if(sum==1)
		{
			puts("YES");
			continue;
		}
		else if(sum==2)
		{
			puts(n==2?"YES":"NO");
			continue;
		}
		feb[1]=feb[2]=1,sum-=2;
		for(i=3;;i++)
		{
			feb[i]=feb[i-1]+feb[i-2];
			sum-=feb[i];
//			cout<<" "<<sum<<endl;
			if(sum<=0) break;
		}
		if(sum<0)
		{
			puts("NO");
			continue;
		}
		ll last=-1;
		bool gg=0;
		for(;i;i--)
		{
			P now=pq.top();
			pq.pop();
			if(num[now.se]<feb[i]) break;
//			cout<<" "<<feb[i]<<" "<<now.se<<endl;
			if(last==now.se)
			{
				if(pq.empty()) break;
				P tmp=pq.top();
				pq.pop();
				if(tmp.fi<feb[i]) break;
				num[tmp.se]-=feb[i];
				if(num[tmp.se]) pq.push(mp(num[tmp.se],tmp.se));
				pq.push(now);
				last=tmp.se;
				continue;
			}
			num[now.se]-=feb[i];
			if(num[now.se]) pq.push(mp(num[now.se],now.se));
			last=now.se;
		}
		if(!i) puts("YES");
		else puts("NO");
	}
}