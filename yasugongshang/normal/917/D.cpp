#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<ctime>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define PI pair<int,int>
#define rg register
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline int read(){
    int x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
    if(a<0){
    	a=-a; putchar('-');
    }
    write(a); puts("");
}
const int N=105,mod=1000000007;
inline int ksm(int a,int b){
	int t=1,y=a;
	while (b){
		if (b&1) t=(ll)t*y%mod;
		y=(ll)y*y%mod;
		b>>=1;
	}
	return t;
}
struct matrix{
	int n;
	int a[N][N];
	inline int* operator [] (int x){
        return a[x];
    }
    void clear(int n){
    	memset(a,0,sizeof(a));
    	for(int i=0;i<n;i++)a[i][i]=1;
	}
	void clear(){
    	memset(a,0,sizeof(a));
	}
 	int det(){
		ll ans=1;
		static int b[N][N];
		memcpy(b,a,sizeof(b));
		//for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<b[i][j]<<" "; puts("");}
  		for(int i=0;i<n;i++){
			if(!b[i][i])for(int j=i+1;j<n;j++)if(b[j][i]){
				swap(b[j],b[i]); ans=-ans; break;
			}
			if(!b[i][i])return 0;
			ll inv=ksm(b[i][i],mod-2);
			ans=ans*b[i][i]%mod;
			for(rg int j=i+1;j<n;j++)if(b[j][i]){
				ll t=inv*b[j][i]%mod;
				for(rg int k=i+1;k<n;k++)b[j][k]=(b[j][k]-t*b[i][k])%mod;;
			}
		}
		return ans;
	}
	matrix mul(ll x){
		matrix c; c.n=n;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
			c[i][j]=a[i][j]*x%mod;
		}
		return c;
	}

}a,b,sum;
matrix operator +(matrix a,matrix b){
	matrix tmp; tmp.n=a.n;
	for(int i=0;i<a.n;i++)for(int j=0;j<a.n;j++)tmp[i][j]=(a[i][j]+b[i][j])%mod;
	return tmp;
}
matrix operator *(matrix a,matrix b){
	matrix tmp; tmp.clear(); tmp.n=a.n;
	for(int i=0;i<a.n;i++){
		for(int j=0;j<a.n;j++){
			for(int k=0;k<a.n;k++){
				tmp[i][j]=(tmp[i][j]+(ll)a[i][k]*b[k][j])%mod;
			}
		}
	}
	return tmp;
}
int n;
struct poly{
    int a[N<<1];
    poly(int x){
        memset(a,0,sizeof a);
        a[0]=x;
    }
    inline int& operator [] (int x){
        return a[x];
    }
};
poly plu(poly x,poly y,int n){
    poly z(0);
    for(int i=0;i<n;i++)
        z[i]=(x[i]+y[i])%mod;
    return z;
}
poly mul(poly x,poly y,int n){
    poly z(0);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            z[i+j]=(z[i+j]+(ll)x[i]*y[j])%mod;
    return z;
}
poly mul(poly a,ll x,int n){
    poly re(0);
    for(int i=0;i<n;i++)
        re[i]=(a[i]*x)%mod;
    return re;
}
poly times(poly a,ll x,ll y,int n){
    poly re(a[0]*y%mod);
    for(int i=1;i<n;i++)
        re[i]=(a[i-1]*x+a[i]*y)%mod;
    return re;
}
poly mo(poly a,poly b,int n,int m){
    for(int i=n-1;i>=m-1;i--){
        ll temp=(ll)a[i]*ksm(b[m-1],mod-2)%mod; int t=i-m+1;
        for(int j=0;j<m;j++)a[t+j]=(a[t+j]-b[j]*temp)%mod;
    }
    return a;
}
poly cha(int f[],int n){
	poly ans(0);
	for(int i=1;i<=n;i++){
		poly tmp(1);
		for(int j=1;j<=n;j++)if(j!=i){
			tmp=mul(times(tmp,1,-j,n+1),ksm(i-j,mod-2),n+1);
		}
		tmp=mul(tmp,f[i],n+1);
		ans=plu(ans,tmp,n+1);
	}
	return ans;
}
/*poly mo(poly a,poly b,int n){
    for(int i=n;~i;i--){
        ll temp=(mod-(ll)a[i+n]*ksm(b[n],mod-2)%mod)%mod;
        for(int j=0;j<=n;j++)
            (a[i+j]+=b[j]*temp%mod)%=mod;
    }
    return a;
}*/
int u[N],v[N],f[N];
signed main(){
	a.n=n=read();
	for(int i=1;i<n;i++){
		u[i]=read()-1; v[i]=read()-1;
	}
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)a[i][j]=i==j?n-1:-1;
	a.n--;
	for(int i=1;i<=n;i++){
		f[i]=a.det(); //writeln(f[i]);
		for(int j=1;j<n;j++){
			a[u[j]][u[j]]++; a[v[j]][v[j]]++; a[u[j]][v[j]]--; a[v[j]][u[j]]--;
		}
	}
	poly t=cha(f,n);
	for(int i=0;i<n;i++){
		write((t[i]+mod)%mod); putchar(' ');
	}
}