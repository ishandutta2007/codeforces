#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pll pair<ll,ll>
#define mmp map<int,pll >
#define mo 1000000007
#define fi first
#define se second
void read(mmp &mp){
	int x,y;
	scanf("%d%d",&x,&y);
	for (int i=2;i*i<=x;i++)
		if (x%i==0){
			int cnt=0;
			for (;x%i==0;x/=i,cnt++);
			mp[i].fi+=cnt;
		}
	if (x>1)
		mp[x].fi++;
	for (int i=2;i*i<=y;i++)
		if (y%i==0){
			int cnt=0;
			for (;y%i==0;y/=i,cnt++);
			mp[i].se+=cnt;
		}
	if (y>1)
		mp[y].se++;
}
ll gcd(ll x,ll y){
	if (x<0) x=-x;
	if (y<0) y=-y;
	for (;y;){
		ll r=x%y;
		x=y; y=r;
	}
	return x;
}
ll mul(ll a,ll b,ll c){
	ll s=0;
	for (;b;b>>=1){
		if (b&1) (s+=a)>=c?s-=c:233;
		(a+=a)>=c?a-=c:233;
	}
	return s;
}
ll power(ll a,ll b,ll c){
	ll s=1;
	for (;b;b/=2,a=mul(a,a,c))
		if (b&1) s=mul(s,a,c);
	return s;
}
ll phi(ll x){
	ll ans=x;
	for (ll i=2;i*i<=x;i++)
		if (x%i==0){
			for (;x%i==0;x/=i);
			ans-=ans/i;
		}
	if (x!=1) ans-=ans/x;
	return ans;
}
ll solve(ll a,ll b,ll c){
	if (a==0) return 0;
	if (b==0) return c/a;
	ll ta=mul(power(a,phi(-b)-1,-b),(c%(-b)+(-b))%(-b),-b);
	ll tb=(c-ta*a)/b;
	if (tb<0){
		ll d=(-tb+a-1)/a;
		ta+=-b*d;
		tb+=a*d;
	}
	return ta;
}
void GG(){
	puts("-1");
	exit(0);
}
mmp merge(mmp a,mmp b){
	ll l=0,la=0,lb=0,lc=0;
	ll p=0,px=0,py=0;
	mmp::iterator it;
	for (it=b.begin();it!=b.end();it++) a[it->fi];
	for (it=a.begin();it!=a.end();it++){
		pll &pa=it->se,&pb=b[it->fi];
		ll A=pa.se,B=-pb.se,C=pb.fi-pa.fi,G=gcd(A,B);
		if (A==0&&B==0){
			if (C) GG();
			continue;
		}
		if (C%G) GG();
		A/=G; B/=G; C/=G;
		if (A<0||(A==0&&B<0))
			A=-A,B=-B,C=-C;
		if (p){
			if (px*A+py*B!=C) GG();
		}
		else if (l){
			if (la==A&&lb==B){
				if (lc!=C) GG();
			}
			else{
				ll X0=A*lb-B*la,X1=C*lb-B*lc;
				ll Y0=B*la-A*lb,Y1=C*la-A*lc;
				if (X1%X0||Y1%Y0) GG();
				l=0; p=1; px=X1/X0; py=Y1/Y0;
				if (px<0||py<0) GG();
			}
		}
		else{
			l=1;
			la=A; lb=B; lc=C;
		}
	}
	if (l){
		mmp ans;
		for (it=a.begin();it!=a.end();it++)
			ans[it->fi]=pll(it->se.fi+it->se.se*solve(la,lb,lc),it->se.se*(-lb));
		return ans;
	}
	else if (p){
		mmp ans;
		for (it=a.begin();it!=a.end();it++)
			ans[it->fi]=pll(px*it->se.se+it->se.fi,0);
		return ans;
	}
	else
		return a;
}
mmp a[105];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		read(a[i]);
		if (i!=1)
			a[i]=merge(a[i],a[i-1]);
	}
	ll ans=1;
	mmp::iterator it;
	for (it=a[n].begin();it!=a[n].end();it++)
		ans=1ll*ans*power(it->fi,it->se.fi,mo)%mo;
	printf("%lld\n",ans);
}