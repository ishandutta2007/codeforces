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
int T;
const int maxn=100;
const int mod=1e9+7;
int n;
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=(ll)a*a%mod)if(b&1)ret=(ll)ret*a%mod;return ret;}
int p[maxn],cnt,val[maxn];
bool vis[maxn];
void prework()
{
	int n=70;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]){p[cnt]=i;val[i]=1<<cnt;cnt++;}
		for(int j=0;j<cnt&&i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;val[i*p[j]]=val[i]^val[p[j]];
			if(i%p[j]==0)break;
		}
	}
}
struct basis
{
	int bas[19];int cnt;
	void insert(int x)
	{
		for(int i=18;i>=0;i--)
			if((x>>i)&1)
			{
				if(bas[i])x^=bas[i];
				else{bas[i]=x;return;}
			}
		cnt++;
	}
}bas;
int main()
{
	prework();
	n=read();
	for(int i=1;i<=n;i++)bas.insert(val[read()]);
	printf("%d\n",qpow(2,bas.cnt)-1);
	return 0;
}