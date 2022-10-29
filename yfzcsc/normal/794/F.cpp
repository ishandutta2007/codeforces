#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
struct data{
	ll cnt[10],sum;
	int dy[10];
	void calc(){
		sum=0;
		for(int i=0;i<10;++i)
			sum+=cnt[i]*i;
	}
}s[maxn<<2];
int a[maxn],q,n;
void build(int o,int l,int r){
	for(int i=0;i<10;++i)
		s[o].dy[i]=i;
	if(l==r){
		s[o].sum=a[l];
		if(!a[l])s[o].cnt[0]++;
		for(int x=1;a[l];x*=10)s[o].cnt[a[l]%10]+=x,a[l]/=10;
		return ;
	}
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
	s[o].sum=s[o<<1].sum+s[o<<1|1].sum;
	for(int i=0;i<10;++i)
		s[o].cnt[i]=s[o<<1].cnt[i]+s[o<<1|1].cnt[i];
}
void pushdown(int o){
	int lc=o<<1,rc=o<<1|1;
	ll lscnt[10]={0};
	for(int i=0;i<10;++i)lscnt[s[o].dy[i]]+=s[lc].cnt[i];
	for(int i=0;i<10;++i)s[lc].dy[i]=s[o].dy[s[lc].dy[i]];
	for(int i=0;i<10;++i)s[lc].cnt[i]=lscnt[i],lscnt[i]=0;
	for(int i=0;i<10;++i)lscnt[s[o].dy[i]]+=s[rc].cnt[i];
	for(int i=0;i<10;++i)s[rc].dy[i]=s[o].dy[s[rc].dy[i]];
	for(int i=0;i<10;++i)s[rc].cnt[i]=lscnt[i],lscnt[i]=0;
	s[lc].calc(),s[rc].calc();
	for(int i=0;i<10;++i)s[o].dy[i]=i;
}
void modify(int o,int l,int r,int ql,int qr,int x,int y){
	if(ql<=l&&r<=qr){
		s[o].sum+=(y-x)*s[o].cnt[x];
		s[o].cnt[y]+=s[o].cnt[x],s[o].cnt[x]=0;
		for(int i=0;i<10;++i)if(s[o].dy[i]==x)
			s[o].dy[i]=y;
		return ;
	}
	int mid=l+r>>1;
	pushdown(o);
	if(ql<=mid)modify(o<<1,l,mid,ql,qr,x,y);
	if(qr>mid)modify(o<<1|1,mid+1,r,ql,qr,x,y);
	s[o].sum=s[o<<1].sum+s[o<<1|1].sum;
	for(int i=0;i<10;++i)
		s[o].cnt[i]=s[o<<1].cnt[i]+s[o<<1|1].cnt[i];
}
ll query(int o,int l,int r,int ql,int qr){
	if(ql<=l&&r<=qr)return s[o].sum;
	int mid=l+r>>1;
	pushdown(o);
	ll ans=0;
	if(ql<=mid)ans+=query(o<<1,l,mid,ql,qr);
	if(qr>mid)ans+=query(o<<1|1,mid+1,r,ql,qr);
	return ans;
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	build(1,1,n);
	for(int i=1;i<=q;++i){
		int op,l,r,x,y;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){
			scanf("%d%d",&x,&y);
			if(x==y)continue;
			modify(1,1,n,l,r,x,y);
		} else printf("%lld\n",query(1,1,n,l,r));
	}
}