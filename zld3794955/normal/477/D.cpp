#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int L=5050,Inf=0x3fffffff,mod=1000000007;
int n,a[L]={},f[L][L]={},g[L][L]={},gn[L]={},dd[L]={};
int r[L]={},height[L]={},h[L][15]={};
char ch[L]={};
void init()
{
	gets(ch+1);
	n=strlen(ch+1);
	for(int i=1;i<=n;++i)
		a[i]=ch[i]-'0';
	a[0]=a[n+1]=-1;
	for(int i=1;i<=n;++i)
		dd[i]=dd[i-1]+((2<<dd[i-1])<=i);
}
inline bool equal(int *a,int s1,int s2,int j)
{
	return a[s1]==a[s2] && a[s1+j]==a[s2+j];
}
void get_sa()
{
	int sa[L]={},m=2;
	int u[L]={},v[L]={},*x=u,*y=v,t[L]={},s[L]={};
	for(int i=1;i<=n;++i)
		++t[x[i]=a[i]];
	for(int i=1;i<=m;++i)
		t[i]+=t[i-1];
	for(int i=n;i>=1;--i)
		sa[t[a[i]]--]=i;
	for(int j=1,p=0;j<=n && p!=n;j*=2,m=p,p=0)
	{
		for(int i=n-j+1;i<=n;++i)
			y[++p]=i;
		for(int i=1;i<=n;++i)
			if(sa[i]>j)
				y[++p]=sa[i]-j;
		for(int i=1;i<=n;++i)
			s[i]=x[y[i]];
		for(int i=0;i<=m;++i)
			t[i]=0;
		for(int i=1;i<=n;++i)
			++t[s[i]];
		for(int i=1;i<=m;++i)
			t[i]+=t[i-1];
		for(int i=n;i>=1;--i)
			sa[t[s[i]]--]=y[i];
		swap(x,y);
		x[sa[1]]=p=1;
		for(int i=2;i<=n;++i)
			x[sa[i]]=equal(y,sa[i],sa[i-1],j) ? p : ++p;
	}
	for(int i=1;i<=n;++i)
		r[sa[i]]=i;
	for(int i=1,k=0;i<=n;height[i++]=k)
		for(k ? --k : k ; a[i+k]==a[sa[r[i]-1]+k] ; ++k)
			;
	for(int i=1;i<=n;++i)
		h[r[i]][0]=height[i];
	for(int s=2,d=0;s<=n;s*=2,++d)
		for(int i=1;i<=n-s+1;++i)
			h[i][d+1]=min(h[i][d],h[i+(1<<d)][d]);
}
inline int compare(int a,int ra,int b,int rb)
{
	if(ra-a<rb-b)
		return -1;
	if(ra-a>rb-b)
		return 1;
	if(a==b)
		return 0;
	int v=-1,len=ra-a+1;
	if(r[a]>r[b])
		v=-v,swap(a,b);
	int d=dd[r[b]-r[a]-1],comh=min(h[r[a]+1][d],h[r[b]-(1<<d)+1][d]);
	return (comh<len)*v;
}
void work1()
{
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		f[i][1]=1;
		g[i][1]=1;
		for(int j=2;j<=i;++j)
			g[i][j]=Inf;
		for(int j=2;j<=i;++j)
			if(a[j])
			{
				int nextp=max(1,j+j-i-1);
				if(a[nextp]==0 || compare(nextp,j-1,j,i)>0)
				{
					f[i][j]=(f[j-1][j-1]-f[j-1][nextp]+mod)%mod;
					if(f[i][j])
						g[i][j]=g[j-1][nextp+1]+1;
				}
				else
				{
					f[i][j]=(f[j-1][j-1]-f[j-1][nextp-1]+mod)%mod;
					if(f[i][j])
						g[i][j]=g[j-1][nextp]+1;
				}
			}
		for(int j=1;j<=i;++j)
			(f[i][j]+=f[i][j-1])%=mod;
		if(i==n)
			copy(g[i]+1,g[i]+n+1,gn+1);
		for(int j=i-1;j>=1;--j)
			g[i][j]=min(g[i][j],g[i][j+1]);
	}
	cout<<f[n][n]<<endl;
}
void work2()
{
	int ans=Inf;
	for(int i=max(1,n-20);i<=n;++i)
		if(f[n][i]-f[n][i-1])
		{
			int s=0;
			for(int j=i;j<=n;++j)
				s=(s<<1)+a[j];
			ans=min(s+gn[i],ans);
		}
	if(ans==Inf)
	{
		for(int i=n-21;i>=1;--i)
			if(f[n][i]-f[n][i-1])
			{
				int s=0;
				for(int j=i;j<=n;++j)
					s=((s<<1)+a[j])%mod;
				(s+=gn[i])%=mod;
				ans=s;
				break;
			}
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	get_sa();
	work1();
	work2();
	return 0;
}