#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int a[xx];
signed main(){
	int T=read();
	while(T--)
	{
		int n,k;
		n=read(),k=read();
		for(int i=1;i<=n;i++)a[i]=read();
			ll ans=-1e18;
		if(n<=105)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					if(i!=j)ans=max(ans,1ll*i*j-1ll*k*(a[i]|a[j]));
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=100;j++)
				{
					int x=n-i+1,y=n-j+1;
					if(x==y)continue;
					ans=max(ans,1ll*x*y-1ll*k*(a[x]|a[y]));
				}
		cout<<ans<<'\n';
	}
	return 0;
}