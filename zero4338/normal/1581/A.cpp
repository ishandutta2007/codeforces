#include<iostream>
#include<cstdio>
typedef long long ll;
using namespace std;
int read()
{
	int ret=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return ret;
}
int T;
const int maxn=1e5+5;
const int mod=1e9+7;
int n;
int fac[maxn<<1];
void prework()
{
	fac[0]=1;
	for(int i=1;i<maxn*2;i++)fac[i]=(ll)fac[i-1]*i%mod;
}
int main()
{
	prework();
	T=read();
	while(T--)
	{
		n=read();
		printf("%lld\n",(ll)fac[2*n-1]*n%mod);
	}
	return 0;
}