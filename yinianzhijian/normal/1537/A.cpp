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
int T;
signed main(){
	T=read();
	while(T--)
	{
		int n=read();
		ll ans=0;
		for(int i=1;i<=n;i++)ans+=read()-1;
		if(ans<0)cout<<1<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}