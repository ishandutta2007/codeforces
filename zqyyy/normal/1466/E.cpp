#include<cstdio>
#include<cctype>
#include<algorithm>

#define mod 1000000007

template<class T>

inline T read(){
    T r=0,f=0;
    char c;
    while(!isdigit(c=getchar()))f|=(c=='-');
    while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
    return f?-r:r;
}

inline long long qpow(long long a,int b){
	long long ans=1;
	for(;b;b>>=1){
		if(b&1)(ans*=a)%=mod;
		(a*=a)%=mod;
	}
	return ans;
}

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

#define maxn 505505

int n,cnt[66];

long long ans,a[maxn];

inline void work(){
	n=read<int>();
	for(int i=0;i<60;i++)cnt[i]=0;
	for(int i=1;i<=n;i++){
		a[i]=read<long long>();
		int len=0;
		long long x=a[i];
		while(x){
			cnt[len]+=x&1;
			len++,x>>=1;
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		long long x=a[i];
		long long f=0,g=0;
		for(int len=0;len<60;len++){
			bool v=x&1;
			int tot=cnt[len];
			if(v){
				(f+=(1ll<<len)%mod*tot)%=mod;
				(g+=(1ll<<len)%mod*n)%=mod;
			}
			else (g+=(1ll<<len)%mod*tot)%=mod;
			x>>=1;
		}
		(ans+=f*g)%=mod;
	}
	printf("%lld\n",ans);
}

int main(){
    int t=read<int>();
	while(t--)work();
    return 0;
}