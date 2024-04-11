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
int qpow(int a,int b,int mod){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int n,x;
vector<int>fac;
void divide(int n)
{
	for(int i=1;i*i<=n;i++)
		if(n%i==0)
		{
			if(i!=n)fac.push_back(i);
			if(i!=1&&i*i!=n)fac.push_back(n/i);
		}
}
bool isprime(int n)
{
	for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
	return 1;
}
bool check(int x)
{
	if(x%n==0)return 0;
	for(int &i:fac)if(qpow(x,i,n)==1)return 0;
	return 1;
}
int main()
{
	n=read()+1;x=read();
	if(!isprime(n))puts("-1");
	else
	{
		divide(n-1);
		for(int i=x-1;i>=2;i--)
			if(check(i)){printf("%d\n",i);return 0;}
		puts("-1");
	}
	return 0;
}