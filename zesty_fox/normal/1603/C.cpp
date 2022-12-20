//Author: wyzwyz

#include<cstdio>
#include<cctype>

#include<map> 
#include<queue>
#include<vector>
#include<cstring>
#include<algorithm>
#include<unordered_map>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

#define swap std::swap
#define mp std::make_pair

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

#define maxn 101101

int n,a[maxn];

//inline long long f(int r){
//	int MOD=a[r];
//	long long s=0,ans=0;
//	for(int i=r-1;i;i--){
//		if(MOD==1){
//			ans+=Sum[i]+s*i;
//			return ans%mod;
//		}
//		if(a[i]<=MOD){
//			ans+=sum[i]+s*i;
//			return ans%mod;
//		}
//		int cnt=(a[i]-1)/MOD;
//		MOD=a[i]/(cnt+1);
//		(s+=cnt)%=mod,ans+=s;
//	}
//	return ans%mod;
//}

__gnu_pbds::gp_hash_table<int,int> f[2];

inline void work(){
	n=read<int>();
	for(int i=1;i<=n;i++)
		a[i]=read<int>();
	f[0].clear();
	f[1].clear();
	long long ans=0;
	f[n&1][a[n]]++;
	for(int i=n-1,o=(n&1)^1;i;i--,o^=1){
		for(auto x:f[o^1]){
			int MOD=x.first;
			int s=(a[i]-1)/MOD;
			int now=a[i]/(s+1);
			int cnt=x.second;
			(f[o][now]+=cnt)%=mod;
			(ans+=1ll*cnt*s%mod*i)%=mod;
		}
		f[o][a[i]]++;
		f[o^1].clear();
	}
	printf("%lld\n",ans);
}

int main(){
	int t=read<int>();
	while(t--)work();
    return 0;
}