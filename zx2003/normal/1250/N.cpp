#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,l,i,j;
struct P{
	ll p,x,y;int q;
	inline void in(){ll t,xx,yy;cin>>t>>xx>>yy;y=yy-xx;x=yy+xx;p=t/l;q=t%l;}
	inline bool operator<(const P&rhs)const{return q<rhs.q;}
}a[N];
char ans[2000005],mp[9]="DRLU";
inline void E(){puts("NO");exit(0);}
struct xint{
	ll l,r;int s;
	inline void operator&=(const xint&rhs){l=max(l,rhs.l);r=min(r,rhs.r);s&=rhs.s;}
	inline bool empty(){
		if(!s)return 1;
		if(s==1){if(l&1)++l;if(r&1)--r;}if(s==2){if(!(l&1))++l;if(!(r&1))--r;}
		return l>r;
	}
};
inline ll ceiL(ll a,ll b){return a<0?a/b:(a+b-1)/b;}
inline ll flooR(ll a,ll b){return a<0?(a-b+1)/b:a/b;}
inline void solve(int tp){
	xint z=(xint){-l,l,3};
	int i;ll u,v,w,a1,a2;
	for(i=1;i<n;++i){
		a1=tp==1?a[i].x:a[i].y;a2=tp==1?a[i+1].x:a[i+1].y;
		w=a[i+1].q-a[i].q;u=a1-a2;v=a[i].p-a[i+1].p;
		if(!v){if(((u+w)&1) || abs(u)>w)E();continue;}
		if(v<0)v=-v,u=-u;
		if(!(v&1) && ((u+w)&1))E();
		z&=(xint){ceiL(u-w,v),flooR(u+w,v),v&1?1<<int((u+w)&1):3};
	}
	if(z.empty())E();
	for(i=1;i<n;++i){
		a1=tp==1?a[i].x:a[i].y;a2=tp==1?a[i+1].x:a[i+1].y;
		u=a1-a[i].p*z.l;v=a2-a[i+1].p*z.l;v-=u;
		for(j=1;j<=abs(v);++j)ans[a[i].q+j]|=v>0?tp:0;for(;j<=a[i+1].q-a[i].q;++j)ans[a[i].q+j]|=(j&1)*tp;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>l;for(i=1;i<=n;++i)a[i].in();a[++n]=(P){0,0,0,0};a[++n]=(P){-1,0,0,l};
	sort(a+1,a+n+1);solve(1);solve(2);
	for(i=1;i<=l;++i)ans[i]=mp[ans[i]];puts(ans+1);
	return 0;
}