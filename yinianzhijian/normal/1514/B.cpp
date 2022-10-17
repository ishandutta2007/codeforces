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
const int mod=1e9+7;
int main(){
	int T=read();
	while(T--)
	{
		ll a,b;
		a=read();
		b=read();
		ll ans=1;
		for(int i=1;i<=b;i++)
		{
			ans*=a;
			ans%=mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}