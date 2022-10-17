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
int n;
const int xx=1005;
ll a[xx];
signed main(){
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!(i&1))continue;
		ll res=0,pre=0;
		for(int j=i+1;j<=n;j++)
		{
			if(!(j&1))
			{
				res-=a[j];
				if(res<0)//0 
				{
					ans+=max(0ll,(min(a[i],-res)-pre));
					
//					cout<<j<<" "<<ans<<'\n';
//					if(-res<=a[i]&&-res>pre)ans++;//0 
					pre=max(pre,-res-1);// 
					if(pre>a[i])break;
				}
			}
			else res+=a[j];
		}
//		cout<<i<<" "<<ans<<"\n";
	}
	cout<<ans<<"\n";
	return 0;
}