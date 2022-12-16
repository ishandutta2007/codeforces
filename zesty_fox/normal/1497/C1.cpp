#include<cstdio>
#include<cctype>

#include<set>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<bitset>
#include<cstring>
#include<cstdlib>
#include<algorithm>

#define mp std::make_pair
#define swap std::swap

#define lowbit(k) (k&(-k))
 
#define mod 31607
 
template<class T>
 
inline T read(){
    T r=0,f=0;
    char c;
    while(!isdigit(c=getchar()))f|=(c=='-');
    while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
    return f?-r:r;
}
 
template<class T>
 
inline T min(T a,T b){
	return a<b?a:b;
}
 
template<class T>
 
inline T max(T a,T b){
	return a>b?a:b;
}
 
#define ll long long
 
inline ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}

inline ll lcm(ll a,ll b){
	return a/gcd(a,b)*b;
}
 
inline ll qpow(ll a,int b){
	ll ans=1;
	for(;b;b>>=1){
		if(b&1)(ans*=a)%=mod;
		(a*=a)%=mod;
	}
	return ans;
}
 
#undef ll
 
struct Z{
 
#define add(x) (x>=mod?x-mod:x)
#define sub(x) (x<0?x+mod:x)
 
	int x;
	inline int val() const{
		return x;
	}
	inline int inv() const{
		return qpow(x,mod-2);
	}
 
	Z(int x=0):x(x) {}
	Z operator -() const{
		return Z(add(mod-x));
	}
	Z &operator +=(const Z &z){
		x=add(x+z.x);
		return *this;
	}
	Z &operator -=(const Z &z){
		x=sub(x-z.x);
		return *this;
	}
	Z &operator *=(const Z &z){
		x=1ll*x*z.x%mod;
		return *this;
	}
	Z &operator /=(const Z &z){
		x=1ll*x*z.inv()%mod;
		return *this;
	}
	Z operator +(const Z &z) const{
		return Z(add(x+z.x));
	}
	Z operator -(const Z &z) const{
		return Z(sub(x-z.x));
	}
	Z operator *(const Z &z) const{
		return Z(1ll*x*z.x%mod);
	}
	Z operator /(const Z &z) const{
		return Z(1ll*x*z.inv()%mod);
	}
 
#undef add
#undef sub

};
 
#define maxn 202202

int n,k;
 
inline void work(){
	n=read<int>();
	k=read<int>();
	if(!(n%3))
		return (void)printf("%d %d %d\n",n/3,n/3,n/3);
	if(n&1)return (void)printf("%d %d %d\n",1,n/2,n/2);
	int x=n/2;
	if(x&1)printf("%d %d %d\n",2,x-1,x-1);
	else printf("%d %d %d\n",x/2,x/2,x);
}
 
int main(){
	int t=read<int>();
	while(t--)work();
    return 0;
}