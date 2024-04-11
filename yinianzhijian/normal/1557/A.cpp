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
int T,a[xx],n;
signed main(){
	T=read();
	while(T--)
	{
		n=read();
		ll s=0;
		for(int i=1;i<=n;i++)a[i]=read(),s+=a[i];
		sort(a+1,a+n+1);
		double ans=-1e18;
		ll s1=0;
		for(int i=1;i<n;i++)
		{
			s1+=a[i];
			ans=max(ans,1.0*s1/i+1.0*(s-s1)/(n-i));
		}
		cout<<fixed<<setprecision(7)<<ans<<"\n";
	}
	return 0;
}