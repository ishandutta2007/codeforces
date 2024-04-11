// ctrnmslsgsjjgyddbxx
#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,lg[N],rid[N],a[N],b[N],st[N<<2],tg[N<<2],f[N][25];
#define lx (x<<1)
#define rx (x<<1|1)
void build(int x, int l, int r)
{
	if(l==r)
	{
		st[x]=b[l];
		return ;
	}
	int mid=l+r>>1;
	build(lx,l,mid),build(rx,mid+1,r);
	st[x]=max(st[lx],st[rx]);
}
void pushdown(int x)
{
	if(!tg[x]) return ;
	tg[lx]+=tg[x],tg[rx]+=tg[x];
	st[lx]+=tg[x],st[rx]+=tg[x];
	tg[x]=0;
}
void update(int x, int l, int r, int sl, int sr, int w)
{
	if(sl>sr) return ;
	if(sl<=l&&r<=sr)
	{
		st[x]+=w,tg[x]+=w;
		return ;
	}
	pushdown(x);
	int mid=l+r>>1;
	if(sl<=mid) update(lx,l,mid,sl,sr,w);
	if(sr>mid) update(rx,mid+1,r,sl,sr,w);
	st[x]=max(st[lx],st[rx]);
}
int qq(int x, int l, int r, int s)
{
	if(!s) return 0;
	if(l==r) return st[x];
	pushdown(x);
	int mid=l+r>>1;
	return (s<=mid?qq(lx,l,mid,s):qq(rx,mid+1,r,s));
}
int query(int x, int l, int r, int sl, int sr)
{
	if(sl<=l&&r<=sr) return st[x];
	pushdown(x);
	int mid=l+r>>1,ans=0;
	if(sl<=mid) ans=query(lx,l,mid,sl,sr);
	if(sr>mid) ans=max(ans,query(rx,mid+1,r,sl,sr));
	return ans;
}
int qmin(int l, int r)
{
	int t=lg[r-l+1];
	return min(f[l][t],f[r-(1<<t)+1][t]);
}
int findl(int l, int r, int w)
{
	while(l<=r)
	{
		int mid=l+r>>1;
		if(qmin(l,mid)<w) r=mid-1;
		else l=mid+1;
	}
	return r+1;
}
int findr(int l, int r, int w)
{
	while(l<=r)
	{
		int mid=l+r>>1;
		if(qmin(mid,r)<w) l=mid+1;
		else r=mid-1;
	}
	return l-1;
}
void init(int l, int r, int d)
{
	if(l>r) return ;
	int x=rid[qmin(l,r)];
	b[x]=d;
	init(l,x-1,d+1),init(x+1,r,d+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;++i) scanf("%d",&a[i]),rid[a[i]]=i,a[i+n]=a[i];
	for(int i=1;i<=(n<<1);++i) f[i][0]=a[i];
	for(int j=1;(1<<j)<=(n<<1);++j)
		for(int i=1;i+(1<<j-1)<=(n<<1);++i)
			f[i][j]=min(f[i][j-1],f[i+(1<<j-1)][j-1]);
	init(1,n,1);
	build(1,1,(n<<1));
	int del=0,ans=query(1,1,(n<<1),1,n);
	for(int i=1;i<n;++i)
	{
		int lp=findl(i+1,i+n-1,a[i]),rp=findr(i+1,i+n-1,a[i]);
		update(1,1,(n<<1),i+1,lp-1,-1);
		update(1,1,(n<<1),rp+1,i+n-1,1);
		if(a[i]==1) update(1,1,(n<<1),i+n,i+n,1);
		else update(1,1,(n<<1),i+n,i+n,qq(1,1,(n<<1),rp)+1);
		int tmp=query(1,1,(n<<1),i+1,i+n);
		if(tmp<ans) ans=tmp,del=i;
	}
	printf("%d %d\n",ans,del);
}