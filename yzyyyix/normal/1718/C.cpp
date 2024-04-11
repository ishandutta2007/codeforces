#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0z3f3f3f3f3f3f3f3f
#define MN 200000
#define N 200100
#define M 4001000
using namespace std;

ll T,n,m,tt,num[N],sum[M],cnt[M];
bool gg[N];
struct Pq
{
	priority_queue<P>A,B;
	inline void push(P u){A.push(u);}
	inline void del(P u){B.push(u);}
	inline void cle(){for(;!B.empty() && A.top()==B.top();A.pop(),B.pop());}
	inline P top(){return cle(),A.top();}
	inline void pop(){cle(),A.pop();}
	inline bool empty(){return A.size()==B.size();}
}pq;
vector<ll>have[N];

inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline ll ask(){return pq.top().fi;}
int main()
{
	ll i,j,k,t,p,q;
	for(i=2;i<=MN;i++)
	{
		if(gg[i]) continue;
		for(j=i+i;j<=MN;j+=i)
			gg[j]=1;
	}
//	for(i=1;i<=10;i++) cout<<gg[i]<<" ";return 0;
	cin>>T;
	while(T--)
	{
		tt=0;
		for(;!pq.empty();pq.pop());
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++) scanf("%lld",&num[i]),have[i].clear();
		for(i=1;i<n;i++)
		{
//			cout<<i<<endl;
			if(n%i || gg[n/i]) continue;
//			cout<<" "<<i<<endl;
			ll step=i;
			for(j=1;j<=step;j++)
			{
				tt++;
				cnt[tt]=step;
				sum[tt]=0;
				for(k=j;k<=n;k+=step)
				{
					sum[tt]+=num[k];
					have[k].push_back(tt);
				}
				pq.push(mp(cnt[tt]*sum[tt],tt));
			}
		}
		printf("%lld\n",ask());
		while(m--)
		{
			scanf("%lld%lld",&p,&q);
			for(auto t:have[p])
			{
				pq.del(mp(cnt[t]*sum[t],t));
				sum[t]+=q-num[p];
//				cout<<" "<<sum[t]<<endl;
				pq.push(mp(cnt[t]*sum[t],t));
			}
			num[p]=q;
			printf("%lld\n",ask());
		}
	}
}