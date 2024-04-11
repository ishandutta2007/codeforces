#include<cstdio>
#include<cctype>

#include<set>
#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<bitset>
#include<random>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<unordered_map>

#define mp std::make_pair
#define swap std::swap

#define lowbit(k) (k&(-k))

#define mod 998244353

template<class T>

inline T read(){
    T r=0,f=0;
    char c;
    while(!isdigit(c=getchar()))f|=(c=='-');
    while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
    return f?-r:r;
}

template<class T>

inline T abs(T a){
	return a<0?-a:a;
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

#define maxn 555

int n,m,a[maxn][maxn],ans[maxn][maxn];

std::vector<int> num;

int main(){
    num.push_back(0);
    for(int i=1;i<=31;i++)
	num.push_back(i*i*i*i);
    long long Lcm=1;
    for(int i=2;i<=16;i++)
	Lcm=lcm(Lcm,i);
    n=read<int>();
    m=read<int>();
    for(int i=1;i<=n;i++)
	for(int j=1;j<=m;j++)
	    a[i][j]=read<int>();
    for(int i=1;i<=n;i++,puts(""))
	for(int j=1;j<=m;j++){
	    if(!((i+j)&1))ans[i][j]=Lcm;
	    else ans[i][j]=Lcm-num[a[i][j]];
	    printf("%d ",ans[i][j]);
	}
    return 0;
}