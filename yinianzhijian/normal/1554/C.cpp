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
int n,m;
int check(int x)
{
	int mx=n,now=0;
	for(int i=30;i>=0;i--)
	{
		if(!(mx>>i&1)&&now+(1<<i)<=x)
		{
			mx+=(1<<i);
			now+=(1<<i);
		}
	}
	return mx;
}
signed main(){
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		int l=0,r=m,ans=m+1;
		while(l<=r)
		{
			int mid=l+r>>1;
			if(check(mid)>m)ans=mid,r=mid-1;
			else l=mid+1;
		}
		cout<<ans<<'\n';
	}
	return 0;
}