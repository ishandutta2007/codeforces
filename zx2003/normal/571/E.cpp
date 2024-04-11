#include<bits/stdc++.h>
using namespace std;
inline void O(){puts("-1");exit(0);}
typedef long long ll;
ll exgcd(ll a,ll b,ll&x,ll&y){
	if(!b)return x=1,y=0,a;
		else{ll d=exgcd(b,a%b,y,x);y-=a/b*x;return d;}
}
struct seq{
	ll a,b;
	seq(ll _a=1,ll _b=0):a(_a),b(_b){}
	inline seq operator&(const seq&rhs){//
		if(!a && !rhs.a){if(b!=rhs.b)O();return seq(1,0);}
		if(!a){if(b<rhs.b || (b-rhs.b)%rhs.a)O();return seq(0,(b-rhs.b)/rhs.a);}
		if(!rhs.a){if(rhs.b<b || (rhs.b-b)%a)O();return seq(1,0);}
		ll c=rhs.a,d=rhs.b,v=((b-d)%a+a)%a,x,y,dd,aa=a,t2;
		dd=exgcd(a,c,x,y);
		if(v%dd)O();
		c/=dd;v/=dd;aa/=dd;
		t2=(y*v%aa+aa)%aa;
		if(c*t2+d-b<0)t2+=(b-d-c*t2+c*aa-1)/(c*aa)*aa;
		return seq(aa,t2);
	}
	inline seq operator&&(const seq&rhs){
		ll c=rhs.a,d=rhs.b;
		if(a!=c){
			if((d-b)%(a-c))O();
			return seq(0,(d-b)/(a-c)*a+b);
		}else{
			if(!a){if(b!=d)O();return rhs;}
			if((b-d)%a)O();
			return seq(a,max(b,d));
		}
	}
	inline void operator*=(const seq&rhs){
		b+=rhs.b*a;
		a*=rhs.a;
	}
};
typedef unordered_map<int,seq>H;
const int M=35e3,mo=1e9+7;
inline int poww(int x,ll y){
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%mo)if(y&1)ans=1ll*ans*x%mo;
	return ans;
}
bool b[M];int pr[M/5],pcnt;
int n,i,j,ass=1;
H ans;
inline H geth(){
	int a,b;scanf("%d%d",&b,&a);
	H ret;
	for(j=1;j<=pcnt;++j)if(a%pr[j]==0 || b%pr[j]==0){
		int ca=0,cb=0;
		for(;a%pr[j]==0;a/=pr[j],++ca);
		for(;b%pr[j]==0;b/=pr[j],++cb);
		ret[pr[j]]=seq(ca,cb);
	}
	if(a>1 && b>1){if(a==b)ret[a]=seq(1,1);else ret[a]=seq(1,0),ret[b]=seq(0,1);}
	if(a>1 && b==1)ret[a]=seq(1,0);if(a==1 && b>1)ret[b]=seq(0,1);
	return ret;
}
ll calc(seq a,seq b,seq c,seq d){
	ll A=(b.a*a.b-a.a*b.b)-(b.a*c.b-a.a*d.b),B=(b.a*c.a-a.a*d.a),x2;
	if(A && !B)O();
	if(B && A%B)O();
	if(!A && !B)return -1;
	if(A/B<0)O();return A/B;
}
inline void work(seq a,seq b,seq c,seq d,seq&e,seq&f){
	ll x1=calc(c,d,a,b),x2=calc(a,b,c,d);
	if(x1==-1)return;
	e=seq(0,c.a*x2+c.b);f=seq(0,d.a*x2+d.b);
}
inline void jiao(H&a,H b){	
	seq aa,bb,na,nb;
	bool fl=0;
	for(auto u:b){
		if(!a.count(u.first))a[u.first]=seq(0,0);
		na=a[u.first];nb=u.second;
		ll x1,x2;
		if(!fl)fl=1,aa=nb&na,bb=na&nb;
			else work(aa,bb,nb&na,na&nb,aa,bb);
	}
	for(auto&u:a)u.second*=aa;
}
int main(){
	for(i=2;i<M;++i)if(!b[i])for(pr[++pcnt]=j=i;j+=i,j<M;b[j]=1);
	scanf("%d",&n);
	ans=geth();for(i=2;i<=n;++i)jiao(ans,geth());
	for(auto u:ans)ass=1ll*ass*poww(u.first,u.second.b)%mo;
	printf("%d\n",ass);		
	return 0;
}