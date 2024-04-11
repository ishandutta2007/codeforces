#include<bits/stdc++.h>
#define ll long long
#define db double
#define P pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define N 500100
#define M
using namespace std;

ll n,m,K,s,cnt[N],ct[N],num[N],ok,need;
vector<ll>gg;

inline void add(ll u)
{
	ct[u]++;
	if(ct[u]==cnt[u]) ok++;
}

inline void del(ll u)
{
	if(ct[u]==cnt[u]) ok--;
	ct[u]--;
}

inline void work(ll u,ll v)
{
	if(n-((u-1)%s+(v-u+1)-s)<s*K) return;
	memset(ct,0,sizeof(ct));
	ll i,j;
	for(i=1; i<=(u-1)%s; i++) gg.push_back(i);
	for(i=u,j=1; i<=v&&j<=(v-u+1)-s; i++)
	{
		if(ct[num[i]]==cnt[num[i]]) gg.push_back(i),j++;
		else ct[num[i]]++;
	}
	cout<<gg.size()<<endl;
	for(i=0; i<gg.size(); i++)
	{
		printf("%lld ",gg[i]);
	}
	exit(0);
}

int main()
{
	ll i,j,p,l,r;
	cin>>n>>s>>K>>m;
	for(i=1; i<=n; i++)
	{
		scanf("%lld",&num[i]);
	}
	for(i=1; i<=m; i++)
	{
		scanf("%lld",&p);
		if(!cnt[p]) need++;
		cnt[p]++;
	}
	for(l=1,r=0;l<=n;l++)
	{
		for(; r<n&&ok<need; r++) add(num[r+1]);
		if(ok==need) work(l,r);
		del(num[l]);
	}
	puts("-1");
}