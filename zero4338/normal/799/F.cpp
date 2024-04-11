#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
mt19937_64 rnd((unsigned long long)(new int));
int n,m;
ull val[maxn];int cover[maxn];
map<ull,pair<int,ll>>cnt;
ll ans;
int main()
{
	m=read();n=read();
	for(int i=1;i<=m;i++)
	{
		int l=read(),r=read();
		ull now=rnd();
		val[l+1]^=now;val[r+1]^=now;
		cover[l]++;cover[r+1]--;
	}
	for(int i=1;i<=n;i++)val[i]^=val[i-1];
	for(int i=1;i<=n;i++)cover[i]+=cover[i-1];
	
	for(int i=1;i<=n;i++)val[i]^=val[i-1];
	for(int i=1;i<=n;i++)
	{
		cnt[val[i]].first++;
		cnt[val[i]].second+=i-1;
		ans+=(ll)cnt[val[i]].first*i-cnt[val[i]].second;
	}
	int ls=0;
	for(int i=1;i<=n;i++)
	{
		if(cover[i])ls=i;
		ans-=(ll)(i-ls+1)*(i-ls)/2;
	}
	printf("%lld\n",ans);
	return 0;
}