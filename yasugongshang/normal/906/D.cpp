#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
using namespace std;
typedef long long  LL;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define F first
#define S second
inline long long read(){
    long long x = 0; char ch = getchar(); bool positive = 1;
    for (; !isdigit(ch); ch = getchar())    if (ch == '-')    positive = 0;
    for (; isdigit(ch); ch = getchar())    x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(long long a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(long long a){
    if(a<0){
        a=-a; putchar('-');
    }
    write(a); puts("");
}
const long long N=500005,p=2000000009;
long long r,k,n,c[N],m,a[N];
map<long long,long long> phi;
inline long long ksm(long long a,long long b,long long mod){
    a%=mod;
    long long t=1,y=a;
    while (b){
        if (b&1) t=(long long)t*y%mod;
        y=(long long)y*y%mod;
        b>>=1;
    }
    return t;
}
inline long long check(long long l,long long r){
    if(l>r)return 1;
    if(l==r)return a[l];
    long long zs=a[r];
    for(int i=l;i<=r;i++)if(a[i]==1)return check(l,i-1);
    for(long long i=r-1;i>=l;i--)if(a[i]>1){
        if(log(p)/log(a[i])<zs-1)return p+1; else zs=ksm(a[i],zs,1e18);
    }else zs=1;
    return zs;
}
long long solve(long long l,long long r,long long mod){
    if(a[l]%mod==0)return 0;
    else if(l+1==r)return ksm(a[l],a[r],mod);
    else if(l==r)return a[l]%mod;
    long long t=check(l+1,min(l+5,r)); //writeln(t);
    if(t>phi[mod])return ksm(a[l],solve(l+1,r,phi[mod])%phi[mod]+phi[mod],mod);
    else return ksm(a[l],t,mod);
}
inline long long calc(long long x){
	long long zs=x,ans=x;
	for(long long i=2;i*i<=x;i++)if(zs%i==0){
		ans=ans/i*(i-1); while(zs%i==0)zs/=i;
	}
	if(zs>1)ans=ans/zs*(zs-1);
	return ans;
}
int main(){
    n=read(); long long mod=read();
    for(long long i=mod;i>1;i=phi[i])phi[i]=calc(i); phi[1]=1;
    for(long long i=1;i<=n;i++)a[i]=read();
    m=read();
    for(long long i=1;i<=m;i++){
        long long s2=read(),s3=read();
        long long ans=solve(s2,s3,mod)%mod;
        writeln(ans);
    }
}