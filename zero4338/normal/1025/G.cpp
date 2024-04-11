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
const int maxn=505,mod=1e9+7;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,ans,siz[maxn];
int main()
{
	n=read();
	for(int i=1;i<=n;i++){int x=read();if(x!=-1)siz[x]++;}
	ans=qpow(2,n-1)-1;
	for(int i=1;i<=n;i++)if(siz[i])(ans+=mod-qpow(2,siz[i])+1)%=mod;
	printf("%d\n",ans);
	return 0;
}