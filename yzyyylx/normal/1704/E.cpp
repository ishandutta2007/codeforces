#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define INF 0x3f3f3f3f3f3f3f3f
#define N 1010
#define M 998244353
using namespace std;

ll T,n,m,ans,num[N],ds[N],len[N];
vector<P>have[N];
vector<ll>to[N];
queue<ll>que;

inline void Add(ll &u,ll v){u=(u+v+M)%M;}
inline void Min(ll &u,ll v){if(v<u) u=v;}
inline void Max(ll &u,ll v){if(v>u) u=v;}
inline P operator + (const P &u,const ll &v){return mp(u.fi+v,u.se+v);}
int main()
{
	ll i,j,t,p,q;
	cin>>T;
	while(T--)
	{
		ans=0;
		scanf("%lld%lld",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&num[i]);
			ds[i]=len[i]=0;
			to[i].clear();
			have[i].clear();
			if(num[i]) have[i].push_back(mp(0,num[i]-1));
		}
		for(i=1;i<=m;i++)
		{
			scanf("%lld%lld",&p,&q);
			to[p].push_back(q);
			ds[q]++;
		}
		for(i=1;i<=n;i++) if(!ds[i]) que.push(i);
		for(;!que.empty();)
		{
			ll now=que.front();
			que.pop();
//			cout<<" "<<now<<endl;
			
			sort(have[now].begin(),have[now].end());
//			for(i=0;i<have[now].size();i++) cout<<have[now][i].fi<<" "<<have[now][i].se<<"|";puts("");
			ll l=0,r=0;
			vector<P>tmp;tmp.clear();
			for(i=0;i<have[now].size();i++)
			{
				if(!tmp.size() || have[now][i].fi>tmp[tmp.size()-1].se+1)
				{
					tmp.push_back(have[now][i]);
					continue;
				}
				tmp[tmp.size()-1].se+=(have[now][i].se-have[now][i].fi+1);
			}
			have[now]=tmp;
			for(i=0;i<have[now].size();i++) have[now][i]=have[now][i]+1;
			if(have[now].size())
			{
				if(have[now][have[now].size()-1].se>M)
				{
					Add(len[now],have[now][have[now].size()-1].se-M);
					have[now][have[now].size()-1].se=M;
				}
				ans=have[now][have[now].size()-1].se+len[now];
			}
//			for(i=0;i<have[now].size();i++) cout<<have[now][i].fi<<" "<<have[now][i].se<<"|";puts("");
			
			for(i=0;i<to[now].size();i++)
			{
				t=to[now][i];
				for(j=0;j<have[now].size();j++)
					have[t].push_back(have[now][j]);
				Add(len[t],len[now]);
				ds[t]--;
				if(!ds[t]) que.push(t);
			}
		}
		printf("%lld\n",ans%M);
	}
}
/*
1
3 2
1 1 1
1 2
2 3
*/