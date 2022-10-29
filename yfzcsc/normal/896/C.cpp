#include<bits/stdc++.h>
#define maxn 100100
using namespace std;
typedef long long ll;
typedef pair<ll,int> par;
struct data{
	int l,r;
	long long t;
	data(){}
	data(int l,int r,ll t):l(l),r(r),t(t){}
	int operator<(const data& d)const{return r<d.r;}
}q[maxn];
set<data>st;
par d[maxn];
int n,m,seed,tp2,a[maxn],vmax,tp;
int rnd(){
    int ret=seed;
    seed=(1ll*seed*7+13)%1000000007;
    return ret;
}
void ins(int l,int r,ll t){
	if(l>r)return ;
	st.insert(data(l,r,t));
}
int qpow(ll a,int b,int mod){
	int ans=1,tmp=a%mod;
	for(;b;b>>=1,tmp=1ll*tmp*tmp%mod)
		if(b&1)ans=1ll*ans*tmp%mod;
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for(int i=1;i<=n;++i)
		a[i]=rnd()%vmax+1,st.insert(data(i,i,a[i]));
	int cnt=0;
	for(int i=1;i<=m;++i){
		tp=0;
		int op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x,y;
	    if(l>r)swap(l,r);
	    if(op==3)x=rnd()%(r-l+1)+1;
	    else x=rnd()%vmax+1;
	    if(op==4)y=rnd()%vmax+1;
	   // printf("[(%d)%d,%d,%d,%d]\n",op,l,r,x,y);
		set<data>::iterator it=st.lower_bound(data(0,l,0)),xt=st.lower_bound(data(0,r,0));
		while(true){q[++tp]=*it;if(it==xt)break;else it++;}
		if(op==1||op==2)for(int i=1;i<=tp;++i)st.erase(q[i]);
		else cnt++;
		if(tp==1){
			if(op==1||op==2){
				ins(q[1].l,l-1,q[1].t);
				ins(r+1,q[1].r,q[1].t);
				if(op==1)ins(l,r,q[1].t+x);
				else ins(l,r,x);
			} else if(op==3)printf("%lld\n",q[1].t);
			else printf("%d\n",1ll*qpow(q[1].t,x,y)*(r-l+1)%y);
		} else {
			if(op==1||op==2){
				for(int i=1;i<=tp;++i){
					ins(q[i].l,l-1,q[i].t);
					ins(r+1,q[i].r,q[i].t);
					if(op==1)ins(max(l,q[i].l),min(r,q[i].r),q[i].t+x);
					else if(op==2&&i==1)i=tp-1;
				}
				if(op==2)ins(l,r,x);
			} else if(op==3){
				tp2=0;
				for(int i=1;i<=tp;++i)
					d[++tp2]=par(q[i].t,min(r,q[i].r)-max(l,q[i].l)+1);
				sort(d+1,d+tp2+1);
				tp2=1;
				while(x>d[tp2].second)x-=d[tp2].second,tp2++;
				printf("%lld\n",d[tp2].first);
			} else {
				int ans=0;
				for(int i=1;i<=tp;++i)
					ans=(ans+1ll*qpow(q[i].t,x,y)*(min(r,q[i].r)-max(l,q[i].l)+1))%y;
				printf("%d\n",ans);
			}
		}
	}

   
}