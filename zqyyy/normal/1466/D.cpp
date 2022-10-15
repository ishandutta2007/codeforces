#include<cstdio>
#include<cctype>
#include<algorithm>

#define mod 19260817

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

#define maxn 101101

int n,a[maxn],d[maxn],val[maxn];

long long ans[maxn];

inline void work(){
	n=read<int>();
	ans[1]=0;
	for(int i=1;i<=n;i++)
		a[i]=read<int>(),ans[1]+=a[i];
	for(int i=1;i<n;i++){
		int u=read<int>();
		int v=read<int>();
		d[u]++,d[v]++;
	}
	int s=0;
	for(int i=1;i<=n;i++)
		while(--d[i])val[++s]=a[i];
	std::sort(val+1,val+1+s);
	for(int i=2;i<n;i++)
		ans[i]=ans[i-1]+val[s-i+2];
	for(int i=1;i<n;i++)
		printf("%lld ",ans[i]);
	puts("");
}

int main(){
    int t=read<int>();
	while(t--)work();
    return 0;
}