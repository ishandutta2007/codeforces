#include<bits/stdc++.h>
using namespace std;
mt19937_64 R(19260817^time(0));
typedef long long ll;
ll n;
int k;
bool ask(ll l,ll r){
	printf("%lld %lld\n",l,r);fflush(stdout);
	char c[9];scanf("%s",c);return *c=='Y';
}
void solve(ll l,ll r){
	l=max(1ll,l-k),r=min(n,r+k);
	if(r-l+1<=45){
		ll x=l+R()%(r-l+1);
		if(ask(x,x))exit(0);
		return solve(l,r);
	}else{
		ll m=l+r>>1;
		if(ask(l,m))solve(l,m);else solve(m+1,r);
	}
}
int main(){
	scanf("%lld%d",&n,&k);
	solve(1,n);
}