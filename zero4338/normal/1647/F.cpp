#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=5e5+5;
int n,a[maxn],num[maxn];
int ans;
int pre[maxn],suf[maxn],f[maxn],g[maxn],smx[maxn];
void solve()
{
	int mxpos=max_element(a+1,a+n+1)-a;
	int v0=0,v1=0;
	for(int i=1;i<=mxpos;i++)
	{
		if(a[i]>v1)v1=a[i];
		else if(a[i]>v0)v0=a[i];
		else {for(int j=i;j<=mxpos;j++)pre[j]=n+1;break;}
		pre[i]=v0;
	}
	v0=0;v1=0;
	for(int i=n;i>=mxpos;i--)
	{
		if(a[i]>v1)v1=a[i];
		else if(a[i]>v0)v0=a[i];
		else {for(int j=i;j>=mxpos;j--)suf[j]=n+1;break;}
		suf[i]=v0;		
	}
	memset(f,0x3f,sizeof f);
	memset(g,0,sizeof g);
	f[mxpos]=pre[mxpos];g[mxpos]=n+1;
	for(int i=mxpos;i<n;i++)
	{
		if(f[i]<a[i+1])g[i+1]=max(g[i+1],a[i]);
		if(a[i]<a[i+1])g[i+1]=max(g[i+1],g[i]);
		if(g[i]>a[i+1])f[i+1]=min(f[i+1],a[i]);
		if(a[i]>a[i+1])f[i+1]=min(f[i+1],f[i]);
	}
	for(int i=n;i>=mxpos;i--)smx[i]=max(smx[i+1],a[i]);
	for(int i=mxpos+1;i<=n;i++)if(max(g[i],a[i])>smx[i+1]&&min(g[i],a[i])>suf[i+1])ans++;
}
int main()
{
	generate_n(a+1,n=read(),read);
	memcpy(num,a,sizeof(int)*(n+1));
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++)a[i]=lower_bound(num+1,num+n+1,a[i])-num;
	solve();reverse(a+1,a+n+1);solve();
	printf("%d\n",ans);
	return 0;
	
}