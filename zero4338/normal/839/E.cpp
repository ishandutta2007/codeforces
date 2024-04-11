#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
mt19937 rnd((unsigned long long)(new int));
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=45;
int n,m,x;
int ans;
ll to[maxn];
int p[maxn];
int main()
{
    //
	n=read();x=read();
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)if(!read())to[i]|=1ll<<j;
	for(int i=1;i<=n;i++)p[i]=i-1;
	for(int T=1;T<=10000;T++)
	{
		shuffle(p+1,p+n+1,rnd);
		ll s=0;int ret=0;
		for(int i=1;i<=n;i++)
			if((to[p[i]]&s)==0){ret++;s|=1ll<<p[i];}
		ans=max(ans,ret);
	}
	printf("%.6lf\n",1.0*x*x/ans*(ans-1)/2);
	return 0;
}