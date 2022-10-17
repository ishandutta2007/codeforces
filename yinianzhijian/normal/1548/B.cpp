#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc()
{
	static char buf[1<<16],*s,*t;
	if(s==t)
	{
		t=(s=buf)+fread(buf,1,1<<16,stdin);
		if(s==t)return EOF;
	}
	return *s++;
}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
ll gcd(ll a,ll b){return !b?a:gcd(b,a%b);}
int T;
const int xx=2e5+5;
ll a[xx],f[xx][21];
int lg[xx];
ll get(int l,int r)
{
	int k=lg[(r-l+1)];
//	cout<<k<<"\n";
	return gcd(f[l][k],f[r-(1<<k)+1][k]);
}
signed main(){
//	freopen("a.in","r",stdin);
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==(i&-i));
	T=read();
	while(T--)
	{
		int n=read();
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=n;i>=2;i--)a[i]-=a[i-1],a[i]=abs(a[i]);
		for(int i=2;i<=n;i++)f[i][0]=a[i];
		for(int j=1;j<=20;j++)
		{
			for(int i=2;i<=n;i++)
			{
				if(i+(1<<j-1)>n)f[i][j]=f[i][j-1];
				else f[i][j]=gcd(f[i][j-1],f[i+(1<<j-1)][j-1]);
			}
		}
//		return 0;
		int ans=0;
		for(int i=2;i<=n;i++)
		{
			if(a[i]==1)continue;
			int l=i,r=n,res=0;
			while(l<=r)
			{
				int mid=l+r>>1;
				if(get(i,mid)>=2)res=mid,l=mid+1;
				else r=mid-1;
			}
//			cout<<i<<" "<<res<<" "<<get(i,i)<<" "<<get(i,i+1)<<"qweqwe \n";
			ans=max(ans,res-i+1);
		}
		cout<<ans+1<<"\n";
	}
	return 0;
}