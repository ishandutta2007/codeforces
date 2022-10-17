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
		int a,b;
		a=read(),b=read();
		if(!a&&!b)
		{
			cout<<"0\n";
		}
		else if(a==b)
		{
			cout<<"1"<<"\n";
		}
		else if((max(a,b)-min(a,b))&1)
		{
			puts("-1");
		}
		else puts("2");
	}
	return 0;
}