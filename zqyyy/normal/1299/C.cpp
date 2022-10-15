#include<cstdio>
#include<cctype>

#include<set>
#include<map>
#include<ctime>
#include<cmath>
#include<queue>
#include<random>
#include<vector>
#include<bitset>
#include<random>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using std::swap;
using std::cout;
using std::cerr;
using std::endl;

#define mp std::make_pair

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

template<int T>
 
struct Hash{

    struct E{
	int v,w,nxt;
	E() {}
	E(int v,int w,int nxt):v(v),w(w),nxt(nxt) {}
    }e[T+100];

    int s_e,head[T+100];

    std::vector<int> d;

    inline void a_e(int u,int v,int w){
	e[++s_e]=E(v,w,head[u]);
	head[u]=s_e;
    }

    inline int H(int x){
	return (1ll*x*x+(x&T)+(x^T))%T+1;
    }

    int& operator [](const int x){
	int u=H(x);
	for(int i=head[u];i;i=e[i].nxt)
	    if(e[i].v==x)return e[i].w;
	a_e(u,x,0);
	d.push_back(x);
	return e[head[u]].w;
    }

    inline void clear(){
	s_e=0;
	for(auto u:d)
	    head[H(u)]=0;
	d.clear();
    }

};

#define maxn 1001001

int n,top,pos[maxn];

double ans[maxn],sta[maxn];

int main(){
    n=read<int>();
    for(int i=1;i<=n;i++)
	ans[i]=read<int>();
    for(int i=1;i<=n;i++){
	double val=ans[i];
	while(top&&sta[top]>val/(i-pos[top])){
	    val+=sta[top]*(pos[top]-pos[top-1]);
	    top--;
	}
	top++;
	pos[top]=i;
	sta[top]=val/(i-pos[top-1]);
    }
    for(int i=1;i<=top;i++)
	for(int j=pos[i-1]+1;j<=pos[i];j++)
	    printf("%.9lf\n",sta[i]);
    return 0;
}