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
ll get(ll l,ll r)
{
	if(l>r)return 0;
	long long ans=0;
	if(l&1)ans^=l,l++;
	if(!(r&1))ans^=r,r--;
	long long www=(r-l+1)/2;
	if(www&1)ans^=1;
	return ans;
}
int main(){
	int T=read();
	while(T--)
	{
		int a=read(),b=read();
		ll now=get(1,a-1);
//		cout<<(b^now)<<"\n";
		if(now==b)cout<<a<<"\n";
		else if((b^now)!=a)
		{
			cout<<a+1<<"\n";
		}
		else cout<<a+2<<"\n";
	}
	return 0;
}