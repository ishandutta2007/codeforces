#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7;

typedef long long ll;

int T,n,m,p;

char s[N];

ll c[N],sta[N];

int cnt[N],rc[N];

int main()
{
	srand(time(NULL));
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<m;j++)
			c[i]=(c[i]<<1)|(s[j]-'0');
	}
	int test=100;
	ll ans=0;
	vector<int>nst;
	while(test--)
	{
		int x=(1ll*rand()*rand()+rand())%n+1;
		int t=__builtin_popcountll(c[x]);
		nst.clear();
		for(int i=0;i<m;i++)
			if(c[x]&(1ll<<i))
				nst.push_back(i);
		for(int S=0;S<(1<<t);S++)
			cnt[S]=rc[S]=0;
		for(int i=1;i<=n;i++)
		{
			ll nS=c[x]&c[i];
			ll rS=0;
			for(int j=0;j<nst.size();j++)
				if(nS&(1ll<<nst[j]))
					rS|=1<<j;
			cnt[rS]++;
		}
		for(int S=0;S<(1<<t);S++)
			for(int T=S;T;T=(T-1)&S)
				rc[T]+=cnt[S];
		int mx=0;
		for(int S=0;S<(1<<t);S++)
			if(rc[S]>=(n+1)/2&&__builtin_popcount(S)>__builtin_popcount(mx))
				mx=S;
		ll rmx=0;
		for(int i=0;i<nst.size();i++)
			if(mx&(1<<i))
				rmx|=1ll<<nst[i];
		if(__builtin_popcountll(rmx)>__builtin_popcountll(ans))
			ans=rmx;
	}
	vector<int>v;
	for(int i=0;i<m;i++)
		v.push_back(ans&1),ans>>=1;
	reverse(v.begin(),v.end());
	for(int i=0;i<v.size();i++)
		printf("%d",v[i]);
	puts("");
}