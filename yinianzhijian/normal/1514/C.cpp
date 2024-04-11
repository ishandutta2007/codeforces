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
int gcd(int x,int y)
{
	return  !y?x:gcd(y,x%y);
}
signed main(){
	int n;n=read();
	ll s=1,tot=0;
	int mod=n;
	for(int i=1;i<=n;i++)
	{
		if(gcd(i,n)==1)s*=i,s%=mod,tot++;
	}
	if(s==1)
	{
		cout<<tot<<"\n";
		for(int i=1;i<=n;i++)
		{
			if(gcd(i,n)==1)cout<<i<<" ";
		}
		puts("");
	}
	else 
	{
		cout<<tot-1<<"\n";
		for(int i=1;i<=n;i++)
		{
			if(gcd(i,n)==1&&i!=s)cout<<i<<" ";
		}
		puts("");
	}
	return 0;
}