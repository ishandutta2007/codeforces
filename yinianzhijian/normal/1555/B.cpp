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

signed main(){
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		int x1=read(),y1=read(),x2=read(),y2=read();
		int w=read(),h=read();
			int ans=1e9;
//		cout<<x2-x1+w+1<<" "<<y2-y1+h+1<<'\n';
		if(x2-x1+w>n&&y2-y1+h>m){puts("-1");continue;}
		else 
		{
			if(!(x2-x1+w>n))
			{
				ans=min(ans,max(0,w-x1));
				ans=min(ans,max(0,x2-(n-w)));
			}
			if(!(y2-y1+h>m))
			{
				ans=min(ans,max(0,h-y1));
				ans=min(ans,max(0,y2-(m-h)));
			}
		}
		cout<<fixed<<setprecision(6)<<ans<<"\n";
	}
	return 0;
}