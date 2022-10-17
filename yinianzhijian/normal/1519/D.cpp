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
int n;
ll ans;
const int xx=5005;
int a[xx];
int b[xx];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)ans+=1ll*a[i]*b[i];
	ll maxx=ans;
	for(int i=1;i<=n;i++)
	{
		ll res=ans;
		int l=i,r=i;
		while(l>=1&&r<=n)
		{
			res-=1ll*a[l]*b[l];
			res-=1ll*a[r]*b[r];
			res+=1ll*a[l]*b[r];
			res+=1ll*a[r]*b[l];
			maxx=max(maxx,res);
			l--,r++;
		}
	}
	for(int i=1;i<n;i++)
	{
		ll res=ans;
		int l=i,r=i+1;
		while(l>=1&&r<=n)
		{
			res-=1ll*a[l]*b[l];
			res-=1ll*a[r]*b[r];
			res+=1ll*a[l]*b[r];
			res+=1ll*a[r]*b[l];
			maxx=max(maxx,res);
			l--,r++;
		}
	}
	cout<<maxx<<"\n";
	return 0;
}