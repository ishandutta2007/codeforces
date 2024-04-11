#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
ll a[2][xx];
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[0][i]=read();
		for(int i=1;i<=n;i++)a[1][i]=read();
		a[0][n+1]=a[1][n+1]=a[0][0]=a[1][0]=0;
		for(int i=1;i<=n;i++)a[1][i]+=a[1][i-1];
		for(int i=n;i>=1;i--)a[0][i]+=a[0][i+1];
		ll ans=1e18;
		for(int i=1;i<=n;i++)
			ans=min(ans,max(a[0][i+1],a[1][i-1]));
		cout<<ans<<'\n';
	}
	return 0;
}