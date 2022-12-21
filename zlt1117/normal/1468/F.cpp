#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int N=1e5+5;
map<P,int> mp;
P a[N];
int read()
{
	int res=0,fl=0; char a=getchar();
	while(a<'0'||a>'9') fl|=a=='-',a=getchar();
	while(a>='0'&&a<='9') res=res*10+a-'0',a=getchar();
	return fl? -res:res; 
}
int gcd(int a,int b) {return b? gcd(b,a%b):a;}
int main()
{
	int i,j,t=read();
	while(t--)
	{
		int n=read();
		long long ans=0;
		for(i=1;i<=n;i++)
		{
			int x=read(),y=read(),u=read(),v=read(),lp;
			x-=u,y-=v,lp=gcd(abs(x),abs(y));
			if(x&&y) x/=lp,y/=lp;
			else x? x/=abs(x):y/=abs(y);
			a[i]=P(x,y),mp[a[i]]=mp[P(-x,-y)]=0;
		}
		sort(a+1,a+n+1);
		for(i=1;i<=n;i=j)
		{
			for(j=i;a[j]==a[i]&&j<=n;j++);
			mp[a[i]]=j-i;
		}
		for(i=1;i<=n;i++)
			if(i==1||a[i]!=a[i-1])
				if(a[i].first>0||a[i].first==0&&a[i].second>0) ans+=1ll*mp[a[i]]*mp[P(-a[i].first,-a[i].second)];
		cout<<ans<<'\n';
	}
	return 0;
}