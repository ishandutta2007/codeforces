#include<bits/stdc++.h>
#define maxn 60100
using namespace std;
typedef long long ll;
// h(i,j) : 1...i do by <=j prime,rest.
// g(i,j) : \sum f(i),i not include <=j prime
// ans=g(i,0)
ll pri[maxn],vis[maxn],psz;
ll h[4][maxn<<1],A,B,C,D,h2[maxn<<1],cnt;
ll b[maxn],n,sqn;
ll& get(ll h[],ll x){
	if(x<=sqn)return h[x];
	else return h[n/x+sqn];
}
void upd(ll& x,ll y){
	x=(x+y);
}
ll sqr(ll x){
	ll y=sqrt(x);
	while(y*y>x)y--;
	while((y+1)*(y+1)<=x)y++;
	return y;
}
void getblk(){
	for(ll i=1,pos;i<=n;i=pos+1)
		pos=n/(n/i),b[++cnt]=pos;
}
ll get3(ll n){
	if(n%3==1)return n*(n+1)/2*((2*n+1)/3);
	else return n*(n+1)/6*(2*n+1);
}
ll get4(ll n){
	ll x=n*(n+1)/2;
	return x*x;
}
void getH(){
	for(int i=1;i<=cnt;++i){
		get(h[0],b[i])=(ll)b[i];
		get(h[1],b[i])=(ll)b[i]*(b[i]+1)/2;
		get(h[2],b[i])=get3(b[i]);
		get(h[3],b[i])=get4(b[i]);
	}
	for(int i=1;i<=psz;++i){
		ll tmp=pri[i],j=cnt,tmp2=tmp*tmp,tmp3=tmp2*tmp;
		for(;b[j]>=(ll)tmp*tmp;j--){
			upd(get(h[0],b[j]),get(h[0],tmp-1)-get(h[0],b[j]/tmp));
			upd(get(h[1],b[j]),tmp*(get(h[1],tmp-1)-get(h[1],b[j]/tmp)));
			upd(get(h[2],b[j]),tmp2*(get(h[2],tmp-1)-get(h[2],b[j]/tmp)));
			upd(get(h[3],b[j]),tmp3*(get(h[3],tmp-1)-get(h[3],b[j]/tmp)));
		}
	}
//	printf("[%lld]",get(h[2],n));
	for(int i=1;i<=cnt;++i)
		get(h2,b[i])=get(h[0],b[i])*D+get(h[1],b[i])*C+get(h[2],b[i])*B+get(h[3],b[i])*A;
}
#define h(x) get(h2,x)
int main(){
	scanf("%lld%lld%lld%lld%lld",&n,&A,&B,&C,&D);
	sqn=sqr(n);
//	printf("[%lld]",sqn);
	int sz=0;
	for(int i=2;i<=30000;++i){
		if(!vis[i])pri[++sz]=i;
		for(int j=1;j<=sz&&i*pri[j]<=30000;++j){
			vis[i*pri[j]]=1;
			if(i%pri[j]==0)break;
		}
	}
	while(pri[psz+1]<=sqn)psz++;
	getblk();
	getH();
	ll ans=0;
//	printf("[%lld]",h(1));
	for(int i=2,pos;i<=n;i=pos+1){
		pos=n/(n/i);
		ans+=n/i*(h(pos)-h(i-1));
//		printf("[%lld,%lld(%lld)]\n",n/i,h(pos)-h(i-1),pos);
	}
//	ans=0;
//	printf("[%lld]",ans);
	for(int i=1;i<=sz;++i){
		ll xp=pri[i];
		if(xp*xp>n)break;
		ll val=D+xp*C+xp*xp*B+xp*xp*xp*A;
		xp=xp*pri[i];
		for(int j=2;xp<=n;xp*=pri[i],j++){
			ll rest=n/xp;
			ans-=rest*(j-1)*val;
			ans+=rest*j*val;
		}
	}
//	printf("[%lld]",ans);
	unsigned int ret=ans&(~0u);
	printf("%u",ret);
}