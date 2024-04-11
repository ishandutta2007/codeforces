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
ll a[xx];
signed main(){
	int T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		ll ans=0;
		for(int j=1;j<n;j++)
			ans=max(ans,max(a[j],a[j+1])*min(a[j],a[j+1]));
		cout<<ans<<"\n";
	}
	return 0;
}