#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
#define fi first
#define se second
#define mk make_pair
const int N=87;
int n;
ll fib[N];
pair<ll,ll>dp(int i,ll x,ll e){
	if(!i)return mk(0,0);
	if(i==1)return mk(x-1,2-x);
	if(x<=fib[i-1]){
		pair<ll,ll>A=dp(i-1,x,2);
		return mk(A.fi,min(A.fi+e,min(A.fi,A.se)+1+((i-1)>>1)));
	}else{
		pair<ll,ll>A=dp(i-2,x-fib[i-1],e+1);
		return mk(min(A.fi+1,A.se+e),A.se);
	}
}
ll solve(ll i,ll x,ll y,ll e){
	if(i<=1)return y-x;
	if(y<=fib[i-1])return solve(i-1,x,y,2);
	else if(x>fib[i-1])return solve(i-2,x-fib[i-1],y-fib[i-1],e+1);
	else{
		pair<ll,ll>A=dp(i-1,x,2),B=dp(i-2,y-fib[i-1],e+1);
		return min(min(A.fi,A.se)+B.fi+1,A.fi+B.se+e);
	}
}
int main(){
	int T=read();n=min((int)read(),80);
	fib[0]=1,fib[1]=2;
	for(int i=2;i<=80;i++)fib[i]=fib[i-1]+fib[i-2];
	while(T--){
		ll x=read(),y=read();
		if(x>y)swap(x,y);
		printf("%lld\n",solve(n,x,y,1e18));
	}
	return 0;
}