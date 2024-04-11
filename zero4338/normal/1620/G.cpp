#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=23;
const int mod=998244353;
int n;
string s[maxn];
int cnt[maxn][26];
int f[26][1<<maxn],bit[1<<maxn];
int val[1<<maxn];
int Log2[1<<maxn];
ll ans;
int main()
{
	// freopen("in.in","r",stdin);
	n=read();
	for(int i=0;i<n;i++)cin>>s[i];
	for(int i=0;i<n;i++)
		for(char &j:s[i])cnt[i][j-'a']++;
	for(int i=0;i<n;i++)Log2[1<<i]=i;
	for(int i=0;i<26;i++)f[i][0]=1e9;
	for(int i=1;i<(1<<n);i++)
	{
		int id=Log2[i&(-i)];
		for(int j=0;j<26;j++)f[j][i]=min(f[j][i-(i&(-i))],cnt[id][j]);
	}
	for(int i=0;i<(1<<n);i++)bit[i]=bit[i>>1]+(i&1);
	for(int i=1;i<(1<<n);i++)
	{
		val[i]=1;
		for(int j=0;j<26;j++)val[i]=(ll)val[i]*(f[j][i]+1)%mod;
		if(!(bit[i]&1))val[i]=mod-val[i];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<(1<<n);j++)
			if((j>>i)&1)
				(val[j]+=val[j-(1<<i)])%=mod;
	for(int i=0;i<(1<<n);i++)
	{
		ll sum=0;
		for(int j=0;j<n;j++)
			if((i>>j)&1)sum+=j+1;
		sum*=bit[i];
		ans^=(ll)val[i]*sum;
	}
	printf("%lld\n",ans);
	return 0;
}