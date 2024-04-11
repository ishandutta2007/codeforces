#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int threshold=15;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
ll multi(ll a, ll b, ll base){///make sure 0<=a<base
    ll rbase=(4e18/base);
    if(b<rbase) return (a*b)%base;
    return (multi(a, b/rbase, base)*rbase+multi(a, b%rbase, base))%base;
}
ll random(ll l, ll r){
    ll t=rng();
    t%=(r-l+1);
    if(t<0) t+=r-l+1;
    return t+l;
}
bool is_prime(ll x){///rabin miller
    if(x<=1) return 0;
    if(x==2) return 1;
    if(x==3) return 1;
    if(x%2==0) return 0;
    int s=__builtin_ctz(x-1);
    ll d=(x-1)>>s;
    for(int time=0; time<threshold; time++){
        ll a=random(2, x-2);
        ll p=1;
        for(int i=__lg(d); i>=0; i--){
            p=multi(p, p, x);
            if((d>>i)&1) p=multi(p, a, x);
        }
        if(p==1) continue;
        if(p+1==x) continue;
        for(int j=1; j<s; j++){
            p=multi(p, p, x);
            if(p+1==x) goto line0;
        }
        return 0;
        line0:;
    }
    return 1;
}
int prev_prime(int n){
	while(!is_prime(n)) n--;
	return n;
}
int next_prime(int n){
	n++;
	while(!is_prime(n)) n++;
	return n;
}
int main(){
	int t, n;
	cin>>t;
	while(t--){
		cin>>n;
		int l=prev_prime(n);
		int r=next_prime(n);
		/// (1/2-1/l)+(n-l+1)*1/r*l
		// cerr<<l<<' '<<r<<'\n';
		ll bot=l;
		bot*=r;
		bot*=2;
		ll top=bot/2-bot/l+bot/r/l*(n-l+1);
		ll d=__gcd(top, bot);
		top/=d;
		bot/=d;
		cout<<top<<'/'<<bot<<'\n';
		// cout<<(n-2)/x<<'/'<<n*2/x<<'\n';
	}
}