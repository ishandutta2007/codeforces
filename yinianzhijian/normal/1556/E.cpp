#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=1e5+5;
int n,m,a[xx],b[xx];
struct node
{
	int l,r,id;
	bool operator<(const node&w)const{return l<w.l;}
}e[xx];
ll sum[xx],ans[xx];
ll mn[xx<<2],mx[xx<<2];
void build(int k,int l,int r)
{
	if(l==r)
	{
		mn[k]=sum[l];
		mx[k]=sum[l];
		return;
	}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	mn[k]=min(mn[k<<1],mn[k<<1|1]);
	mx[k]=max(mx[k<<1],mx[k<<1|1]);
}
ll askmx(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return mx[k];
	int mid=l+r>>1;
	ll ans=-1e18;
	if(x<=mid)ans=max(ans,askmx(k<<1,l,mid,x,y));
	if(mid<y)ans=max(ans,askmx(k<<1|1,mid+1,r,x,y));
	return ans;
}
ll askmn(int k,int l,int r,int x,int y)
{
	if(x<=l&&r<=y)return mn[k];
	int mid=l+r>>1;
	ll ans=1e18;
	if(x<=mid)ans=min(ans,askmn(k<<1,l,mid,x,y));
	if(mid<y)ans=min(ans,askmn(k<<1|1,mid+1,r,x,y));
	return ans;
}

signed main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++)b[i]=read();
	for(int i=1;i<=n;i++)a[i]=b[i]-a[i];
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
	build(1,1,n);
	for(int i=1;i<=m;i++)e[i].l=read(),e[i].r=read(),e[i].id=i;
	for(int i=1;i<=m;i++)
	{
		if(sum[e[i].r]-sum[e[i].l-1]!=0)
		{
			ans[e[i].id]=-1;
			continue;
		}
		ll maxx=askmx(1,1,n,e[i].l,e[i].r);
		ll minn=askmn(1,1,n,e[i].l,e[i].r);
		if(minn-sum[e[i].l-1]<0)
		{
			ans[e[i].id]=-1;
			continue;
		}
		else 
		{
			ans[e[i].id]=maxx-sum[e[i].l-1];
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	return 0;
}