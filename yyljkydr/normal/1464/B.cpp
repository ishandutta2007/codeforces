#include<bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
const int N=1e5+1e3+7;
 
int n;
 
char s[N];
 
int x,y;

ll pv[N],sv[N],c[2],p0[N];
 
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d%d",&x,&y);
	if(x>y)
	{
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='1')
				s[i]='0';
			else if(s[i]=='0')
				s[i]='1';
		}
		swap(x,y);
	}
	ll ans=1e18;
	c[0]=c[1]=0;
	for(int i=1;i<=n;i++)
	{
		ll dv=0;
		if(s[i]=='1')
		{
			dv+=1ll*c[0]*x;
			c[1]++;
		}
		else
		{
			dv+=1ll*c[1]*y;
			c[0]++;
		}
		pv[i]=pv[i-1]+dv;
	}
	c[0]=c[1]=0;
	for(int i=n;i>=1;i--)
	{
		p0[i]=p0[i+1]+(s[i]=='0');
		ll dv=0;
		if(s[i]=='0')
		{
			dv+=1ll*c[1]*x;
			c[0]++;
		}
		else
		{
			dv+=1ll*c[0]*y;
			c[1]++;
		}
		sv[i]=sv[i+1]+dv;
	}
	ans=pv[n];
	c[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?')
			ans=min(ans,pv[i-1]+sv[i]+1ll*c[0]*(n-i+1-p0[i+1])*x+1ll*(i-1-c[0])*p0[i]*y);
		c[0]+=s[i]=='0'||s[i]=='?';
	}
	printf("%lld\n",(long long)ans);
}