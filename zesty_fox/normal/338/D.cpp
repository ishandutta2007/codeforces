#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m,k,b[N];
inline ll gcd(ll x,ll y){return !x?y:gcd(y%x,x);}
inline ll lcm(ll x,ll y){
	if(x==INF||y==INF) return INF;
	ll gc=gcd(x,y);
	if(x/gc>INF/y) return INF;
	return x/gc*y;
}

inline bool check(ll x,ll y){
	if(y+k-1>m) return false;
	for(ll i=y;i<=y+k-1;i++){
		if(gcd(x,i)!=b[i-y+1]) return false;
	}
	return true;
}

inline ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){x=1,y=0;return a;}
	ll d=exgcd(b,a%b,x,y);
	ll z=x;x=y;y=z-(a/b)*y;
	return d;
}

inline ll mul(ll x,ll y,ll MOD){
	if(y<0) x=-x,y=-y;
	ll res=0;
	while(y){
		if(y&1) (res+=x)%=MOD;
		(x+=x)%=MOD;y>>=1;
	}
	return res;
}

ll exCRT(const vector<pair<ll,ll> > &eqn){
	ll rmd=0,mod=1;
	for(auto tmp:eqn){
		ll b1,b2,d=exgcd(mod,tmp.se,b1,b2),c=tmp.fi-rmd;
		if(c%d) return -1;
		
		ll nxtmod=lcm(mod,tmp.se);
		b1=mul(b1,c/d,nxtmod);
		rmd=rmd+mul(b1,mod,nxtmod);
		mod=nxtmod;
		rmd=(rmd%mod+mod)%mod;
	}
	return rmd;
}

void solve(){
	n=rdll(),m=rdll(),k=rdi();
	for(int i=1;i<=k;i++) b[i]=rdll();
	
	ll x=1;
	for(int i=1;i<=k;i++) x=lcm(x,b[i]);
	if(x>n) return (void)puts("NO");
	else{
		vector<pair<ll,ll> > eqn;
		for(int i=1;i<=k;i++) eqn.pb(mp(((b[i]-(i-1))%b[i]+b[i])%b[i],b[i]));
		ll y=exCRT(eqn);
		if(!y) y+=x;
		if(y==-1) puts("NO");
		else puts(check(x,y)?"YES":"NO");
	}
}

int T;
int main(){
    solve();
    return 0;
}