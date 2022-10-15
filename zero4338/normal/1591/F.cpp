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
const int maxn=5e5+5;
const int mod=998244353;
int n,a[maxn];
int f[maxn],pre[maxn];
stack<pair<int,int>>s;int sum;
int main()
{
	generate_n(a+1,n=read(),read);
	f[0]=1;pre[0]=1;
	for(int i=1;i<=n;i++)
	{
		while(!s.empty()&&a[s.top().first]>=a[i])
		{
			(sum+=mod-s.top().second)%=mod;
			s.pop();
		}
		if(!s.empty())(sum+=(ll)(pre[i-1]-pre[s.top().first-1]+mod)*a[i]%mod)%=mod,s.push({i,(ll)(pre[i-1]-pre[s.top().first-1]+mod)*a[i]%mod});
		else (sum+=(ll)pre[i-1]*a[i]%mod)%=mod,s.push({i,(ll)pre[i-1]*a[i]%mod});
		f[i]=(mod-sum)%mod;pre[i]=(pre[i-1]+f[i])%mod;
	}
	if(n&1)f[n]=(mod-f[n])%mod;
	printf("%d\n",f[n]);
	return 0;
}