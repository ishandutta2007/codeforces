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

#define maxn 333

int n;

char s[maxn][maxn],map[maxn][maxn];

inline bool solve(int o){
	int S=0,cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			map[i][j]=s[i][j];
			cnt+=s[i][j]!='.';
			if((i+j)%3==o){
				if(map[i][j]=='O')
					map[i][j]='X',S++;
			}
			if((i+j)%3==(o+1)%3){
				if(map[i][j]=='X')
					map[i][j]='O',S++;
			}
		}
	if(S>cnt/3)return false;
	for(int i=1;i<=n;i++,puts(""))
		for(int j=1;j<=n;j++)
			putchar(map[i][j]);
	return true;
}

inline void work(){
	n=read<int>();
	for(int i=1;i<=n;i++)
		scanf("%s\n",s[i]+1);
    if(solve(0))return;
	if(solve(1))return;
	solve(2);
}

int main(){
	int t=read<int>();
	while(t--)work();
    return 0;
}