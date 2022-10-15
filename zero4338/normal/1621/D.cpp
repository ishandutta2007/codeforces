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
const int maxn=505;
int n;
ll c[maxn][maxn];
ll ans;
int main()
{
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=2*n;i++)
			for(int j=1;j<=2*n;j++)c[i][j]=read();
		ans=1e9;
		ans=min(ans,c[1][n+1]);
		ans=min(ans,c[1][2*n]);
		ans=min(ans,c[n][n+1]);
		ans=min(ans,c[n+1][n]);
		ans=min(ans,c[n][2*n]);
		ans=min(ans,c[n+1][1]);
		ans=min(ans,c[2*n][1]);
		ans=min(ans,c[2*n][n]);
		
		for(int i=n+1;i<=2*n;i++)
			for(int j=n+1;j<=2*n;j++)ans+=c[i][j];
		printf("%lld\n",ans);
	}
	return 0;
}