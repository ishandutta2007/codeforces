#include<bits/stdc++.h>
#define ll long long
#define ld long double
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
const int xx=4e6+5;
ll f[xx],sum[xx];
int mod,zz[xx],n;
int prim[xx/4],in[xx];
bitset<xx>vis;
void pre()
{
	int cnt=0;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])in[i]=i,prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>n)break;
			vis[i*prim[j]]=1;
			in[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}
ll nsum;
int tt,p[50005],ss[50005];
void dfs(int x,int sm)
{
	if(x==tt+1)
	{
		if(sm==1)return;
		nsum-=f[zz[sm]];
		zz[sm]++;
		nsum+=f[zz[sm]];
//		cout<<sm<<"sss \n";
		return;
	}
	int o=1;
	for(int j=0;j<=ss[x];j++)
	{
//		cout<<j<<" sss "<<o<<"\n";
		dfs(x+1,sm*o);
		o*=p[x];
	}
}
//vector<short>v[xx];
int main(){
//	ll ans=0;
//	for(int i=1;i<=2000;i++)
//	{
//		ans+=4000000/i;
//	}
//	cout<<ans<<"\n";
//	for(short i=2;i<=2000;i++)
//		for(int j=i;j<=4000000;j+=i)v[j].push_back(i);
	n=read();mod=read();
	pre();
	f[1]=1,sum[1]=1;
	ll nss=0,last=0;
	for(int i=2;i<=n;i++)//*2+1 
	{
		f[i]=sum[i-1];
		
		int now=i;
		tt=0;
//		cout<<in[now]<<"qwewqe \n";
		while(now!=1)
		{
			p[++tt]=in[now];ss[tt]=0;
			while(now%p[tt]==0)now/=p[tt],ss[tt]++;
		}
		dfs(1,1);
		ll o=0;
//		for(int j=2;j<=i;j++)o+=f[i/j];
//		cout<<o<<" "<<nsum<<"\n";
//		last+=f[1];
//		for(int j=0;j<v[i].size();j++)
//		{
//			last-=f[v[i][j]-1];
//			last+=f[v[i][j]];
//		}
		
//		last%=mod,last+=mod,last%=mod;
//		int last=i;
//		for(int j=1;j<i/sq[i];j++)
//		{
//			int now=i/(j+1);
//			f[i]+=(last-now)*f[j]%mod;
//			f[i]%=mod;
//			last=now;
//		}
//		f[i]+=last;
		f[i]+=nsum;
		f[i]%=mod;
		sum[i]=sum[i-1]+f[i],sum[i]%=mod;
//		nss+=sq[i];
//		nss+=i/sq[i];
//		cout<<sq[i]<<" "<<i<<"\n";
//		if(i%1000==0)cout<<i<<" "<<nss<<"\n";
	}
//	for(int i=2;i<=n;i++)cout<<i<<" "<<f[i]<<"\n";
//	for(int i=2;i<=n;i++)cout<<i<<" "<<f[i]<<" "<<f[i]-f[i-1]*2<<"\n";
	cout<<f[n]<<"\n";
	return 0;
}