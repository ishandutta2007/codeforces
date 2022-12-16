#include<cstdio>
#include<cctype>
#include<cstring>

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

template<class T>

inline void swap(T &a,T &b){
	T c=a;
	a=b;
	b=c;
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

#define maxn 303303

int n,a[maxn],cnt[maxn];

bool ans[maxn];

inline void work(){
	n=read<int>();
	for(int i=1;i<=n;i++){
		a[i]=read<int>();
		cnt[a[i]]++;
		ans[i]=0;
	}
	ans[1]=1;
	for(int i=1;i<=n;i++)
		ans[1]&=cnt[i]==1;
	int l=1,r=n;
	for(int i=1;i<n&&l<=r;i++){
		bool o=cnt[i]>1;
		if(!cnt[i])break;
		while(l<=r&&a[l]==i)l++,cnt[i]--;
		while(l<=r&&a[r]==i)r--,cnt[i]--;
		ans[n-i+1]=1;
		if(cnt[i])break;
		if(o)break;
	}
	for(int i=1;i<=n;i++)
		putchar(ans[i]+'0');
	puts("");
	for(int i=1;i<=n;i++)
		cnt[a[i]]=0;
}

int main(){
	int t=read<int>();
	while(t--)work();
    return 0;
}