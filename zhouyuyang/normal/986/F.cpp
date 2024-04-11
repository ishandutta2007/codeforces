#include<bits/stdc++.h>
#define ll long long
const int N=31623000;
using namespace std;
bool fl[N];
int pri[2000000],tot;
void init(){
	for (int i=2;i<N;i++){
		if (!fl[i]) pri[++tot]=i;
		for (int j=1;i*pri[j]<N;j++){
			fl[i*pri[j]]=1;
			if (i%pri[j]==0) break;
		}
	}
}
ll mul(ll x,ll y,ll mo){
	ll s=0; x%=mo; y%=mo;
	for (;y;y/=2,x=(x+x)%mo)
		if (y&1) s=(s+x)%mo;
	return s;
}
ll power(ll x,ll y,ll mo){
	ll s=1; 
	for (;y;y/=2,x=mul(x,x,mo))
		if (y&1) s=mul(s,x,mo);
	return s;
}
struct que{
	ll n,x;
	int id;
}q[10005];
bool cmp(que a,que b){
	return a.x<b.x;
}
bool pd[100005];
bool ans[10005];
ll f[100005];
ll p[55];
void upd(ll x,int w){
	for (int i=0;i<w;i++) pd[i]=0;
	for (int i=0;i<w;i++)
		if (!pd[i]){
			int k=i,j=(i+x)%w;
			for (;j!=i;){
				if (f[j]<f[k]) k=j;
				j=(j+x)%w;
			}
			j=k;
			for (;;){
				pd[k]=1;
				f[(k+x)%w]=min(f[(k+x)%w],f[k]+x);
				k=(k+x)%w;
				if (k==j) break;
			}
		}
}
void solve(int l,int r,ll k){
	ll n,m=k; int cnt=0;
	for (int i=1;i<=tot;i++){
		if (1ll*pri[i]*pri[i]>m) break;
		if (m%pri[i]==0){
			p[++cnt]=pri[i];
			for (;m%pri[i]==0;m/=pri[i]);
		}
	}
	if (m>1) p[++cnt]=m;
	if (cnt==0){
		for (int i=l;i<=r;i++)
			ans[q[i].id]=(q[i].n==0);
	}
	else if (cnt==1){
		for (int i=l;i<=r;i++)
			ans[q[i].id]=(q[i].n%k==0);
	}
	else if (cnt==2){
		ll a=p[1],b=p[2],c,d;
		c=power(b,a-2,a);
		for (int i=l;i<=r;i++){
			ll n=q[i].n;
			d=mul(n,c,a);
			d=(d+a)%a;
			if (d<=n/b)
				ans[q[i].id]=1;
		}
	}
	else{
		ll w=p[1];
		for (int i=1;i<p[1];i++) f[i]=(1ll<<60);
		f[0]=0;
		for (int i=2;i<=cnt;i++)
			upd(p[i],w);
		for (int i=l;i<=r;i++)
			if (f[q[i].n%w]<=q[i].n) ans[q[i].id]=1;
	}
}
int T;
int main(){
	init();
	scanf("%d",&T);
	for (int i=1;i<=T;i++){
		scanf("%lld%lld",&q[i].n,&q[i].x);
		q[i].id=i;
	}
	sort(q+1,q+T+1,cmp);
	for (int i=1,j;i<=T;i=j+1){
		for (j=i;j!=T&&q[j+1].x==q[i].x;j++);
		solve(i,j,q[i].x);
	}
	for (int i=1;i<=T;i++)
		puts(ans[i]?"YES":"NO");
}