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
const int xx=1e5+5;
char ans[xx];
signed main(){
//	int last=3;
//	for(int i=1;i<=12;i++)
//	{
//		cout<<last<<'\n';
//		last*=3,last+=2;
//	}
	int T=read();
	while(T--)
	{
		int n=read();
		int now=1,tt=0;
		ans[1]='a';
		while(now*3+2<=n)
		{
			for(int j=1;j<=now;j++)ans[now+1+j]=ans[j];
			ans[now+1]='a'+(++tt);
			for(int j=1;j<=now;j++)ans[now+1+now+1+j]=ans[j];
			ans[now+1+now+1]='a'+(++tt);
			now*=3,now+=2;
		}
		ans[n+1]=0;
		if(n==now)
		{
			cout<<ans+1<<'\n';
			continue;
		}
		int rem=n-now;
		if(rem<=3)
		{
			for(int j=now+1;j<=n;j++)ans[j]='a'+(++tt);
			cout<<ans+1<<'\n';
			continue;
		}
		rem-=2;
		if(rem&1)ans[n]='a'+(++tt);
		rem/=2;
		ans[++now]='a'+(++tt);
		for(int j=1;j<=rem;j++)ans[now+j]=ans[j];
		now+=rem;
		ans[++now]='a'+(++tt);
		for(int j=1;j<=rem;j++)ans[now+j]=ans[j];
		cout<<ans+1<<'\n';
	}
	return 0;
}