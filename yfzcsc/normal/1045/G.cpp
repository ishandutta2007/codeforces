#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
const ll inf=2e9+10;
struct data{
	int x,r,q;
	data(){}
	void scan(){
		scanf("%d%d%d",&x,&r,&q);
	}
	int operator<(const data& d)const{
		return r<d.r;
	}
}d[maxn];
struct seg{
	int lc,rc,sum;
}s[maxn*50];
long long ans=0;
int n,K,ptr;
map<int,int> st; 
int qry(int rt,ll l,ll r,ll ql,ll qr){
	if(!rt)return 0;
	if(ql<=l&&r<=qr)return s[rt].sum;
	ll mid=l+(r-l)/2,ans=0;
	if(ql<=mid)ans+=qry(s[rt].lc,l,mid,ql,qr);
	if(qr>mid)ans+=qry(s[rt].rc,mid+1,r,ql,qr);
	return ans;
}
void mdy(int&rt,ll l,ll r,ll x,ll a){
	if(!rt)rt=++ptr;
	s[rt].sum+=a;
	if(l==r)return ;
	ll mid=l+(r-l)/2;
	if(x<=mid)mdy(s[rt].lc,l,mid,x,a);
	else mdy(s[rt].rc,mid+1,r,x,a);
}
int main(){
//	n=1000,K=5;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;++i)
//		d[i].x=rand(),d[i].r=rand(),d[i].q=rand()%100;
		d[i].scan();
	int rt=0;
	sort(d+1,d+n+1);
//	ll sum=0;
//	for(int i=1;i<=n;++i)
//		for(int j=i+1;j<=n;++j)
//			if(abs(d[i].q-d[j].q)<=K&&abs(d[i].x-d[j].x)<=min(d[i].r,d[j].r))
//				sum++;
//	printf("[%lld]",sum);
	for(int i=n;i>=1;--i){
		for(int j=d[i].q-K;j<=d[i].q+K;++j)
			ans+=qry(st[j],-inf,inf,d[i].x-d[i].r,d[i].x+d[i].r);
		mdy(st[d[i].q],-inf,inf,d[i].x,1);
	}
	printf("%lld",ans);
}