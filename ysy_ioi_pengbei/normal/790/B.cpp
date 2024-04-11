#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define SZ 666666
int M=0,fst[SZ],nxt[SZ],vb[SZ],vc[SZ];
void ad_de(int a,int b,int c) {++M; nxt[M]=fst[a]; fst[a]=M; vb[M]=b; vc[M]=c;}
void adde(int a,int b,int c) {ad_de(a,b,c); ad_de(b,a,c);}
int sz[SZ],ms[SZ],n,k,root,sum;
bool vis[SZ];
int groot(int x,int f)
{
	sz[x]=1; ms[x]=0;
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e];
		if(b==f||vis[b]) continue;
		groot(b,x); sz[x]+=sz[b];
		ms[x]=max(ms[x],sz[b]);
	}
	ms[x]=max(ms[x],sum-sz[x]);
	if(ms[x]<ms[root]||!root) root=x;
}
typedef long long ll;
ll dep[SZ],ds=0,d[SZ];
void gdeep(int x,int f)
{
	dep[++ds]=d[x];
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e];
		if(b==f||vis[b]) continue;
		d[b]=d[x]+vc[e]; gdeep(b,x);
	}
}
ll qzh[SZ],cn[5];
ll calc(int x,int fv)
{
	d[x]=fv; ds=0; gdeep(x,0);
	sort(dep+1,dep+1+ds);
	memset(cn,0,sizeof(cn));
	for(int l=1;l<=ds;l++)
		cn[dep[l]%k]++;
	for(int l=1;l<=ds;l++)
		qzh[l]=qzh[l-1]+dep[l];
	int r=ds; ll ans=0;
	for(int i=0;i<k;i++)
	{
		for(int j=i;j<k;j++)
		{
			ll c=cn[i]*cn[j];
			if(i==j) c-=cn[i], c/=2;
			int tg=(i+j+k-1)/k*k-i-j;
			ans+=tg*c;
		}
	}
	ll p=0;
	for(int l=1;l<=ds;l++)
		p+=qzh[ds]-dep[l]+(ll)(ds-1)*dep[l];
	return ans+p/2;
}
long long ans=0;
void dfz(int x)
{
	ans+=calc(x,0); vis[x]=1;
	for(int e=fst[x];e;e=nxt[e])
	{
		int b=vb[e]; if(vis[b]) continue;
		ans-=calc(b,vc[e]); sum=sz[b];
		root=0; groot(b,0); dfz(root);
	}
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		adde(a,b,1);
	}
	sum=n; groot(1,0); dfz(root);
	if(ans%k!=0) throw "WTF";
	cout<<ans/k<<"\n";
}