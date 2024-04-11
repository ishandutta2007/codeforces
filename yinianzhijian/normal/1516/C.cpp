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
int a[2005];
int gcd(int x,int y){return !y?x:gcd(y,x%y);}
void clear()
{
	int now=a[1];
	for(int i=1;i<=n;i++)now=gcd(now,a[i]);
	for(int i=1;i<=n;i++)a[i]/=now;
}
bitset<2000005>bit;
signed main(){
	n=read();
	int sum=0;
	for(int i=1;i<=n;i++)a[i]=read();
	clear();
	for(int i=1;i<=n;i++)sum+=a[i];
	bit[0]=1;
	for(int i=1;i<=n;i++)bit|=(bit<<a[i]);
	if(sum&1||!bit[sum/2])
	{
		puts("0");
		return 0;
	}
	else 
	{
		puts("1");
		for(int i=1;i<=n;i++)
		if(a[i]&1)
		{
			cout<<i<<"\n";
			return 0;
		}
	}
	return 0;
}