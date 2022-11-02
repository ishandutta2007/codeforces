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
#define uint unsigned
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
const int N=300000,G=3,mod=998244353;
int wn[N],WN[N];
int rev[N];
ll ppow(ll x,ll k){if(k>=mod)k%=mod-1; else if(x==-1)return k%2?-1:1; ll ans=1;for(;k;k>>=1,x=x*x%mod)if (k&1)ans=ans*x%mod;return ans;}
#define ksm ppow
#define pow ppow
struct fft{
    int n,L;
    void init(int len){
        n=1; L=0; while(n<len)n<<=1,L++;
        ll w=ppow(G,(mod-1)/n);
        for(register int i=0;i<n;i++)wn[i]=i?wn[i-1]*w%mod:1,rev[i]=rev[i>>1]>>1|((i&1)<<L-1);
    }
    void dft(int *a){
        for(register int i=0;i<n;i++)if (rev[i]<i)swap(a[i],a[rev[i]]);
        for(register int d=1,len=L-1;d<n;d<<=1,--len){
            for(register int i=0;i<=d;i++)    WN[i]=wn[i<<len];int t;
            if (d<=4)
            for(register int i=0;i<n;i+=d<<1){
                for(register int k=0,x=i;k<d;++k,++x){
                    t=(ll)WN[k]*a[x+d]%mod;
                    a[x+d]=(a[x]-t)%mod,a[x]=(a[x]+t)%mod;
                }
            }else{
                for(register int i=0;i<n;i+=d<<1){
                    for(register int k=0,x=i;k<d;){
                        t=(ll)WN[k]*a[x+d]%mod;
                        a[x+d]=(a[x]-t)%mod,a[x]=(a[x]+t)%mod;
                        t=(ll)WN[k+1]*a[x+d+1]%mod;
                        a[x+d+1]=(a[x+1]-t)%mod,a[x+1]=(a[x+1]+t)%mod;
                        t=(ll)WN[k+2]*a[x+d+2]%mod;
                        a[x+d+2]=(a[x+2]-t)%mod,a[x+2]=(a[x+2]+t)%mod;
                        t=(ll)WN[k+3]*a[x+d+3]%mod;
                        a[x+d+3]=(a[x+3]-t)%mod,a[x+3]=(a[x+3]+t)%mod;
                        k+=4;x+=4;
                    }
                }
            }
        }
        reverse(a+1,a+n);ll inv=ppow(n,mod-2);
        for(register int i=0;i<n;i++)a[i]=a[i]*inv%mod;
    }
    void ddft(int *a){
        for(register int i=0;i<n;i++)if (rev[i]<i)swap(a[i],a[rev[i]]);
        for(register int d=1,len=L-1;d<n;d<<=1,--len){
            for(register int i=0;i<=d;i++)    WN[i]=wn[i<<len];int t;
            if (d<=4)
            for(register int i=0;i<n;i+=d<<1){
                for(register int k=0,x=i;k<d;++k,++x){
                    t=(ll)WN[k]*a[x+d]%mod;
                    a[x+d]=(a[x]-t)%mod,a[x]=(a[x]+t)%mod;
                }
            }else{
                for(register int i=0;i<n;i+=d<<1){
                    for(register int k=0,x=i;k<d;){
                        t=(ll)WN[k]*a[x+d]%mod;
                        a[x+d]=(a[x]-t)%mod,a[x]=(a[x]+t)%mod;
                        t=(ll)WN[k+1]*a[x+d+1]%mod;
                        a[x+d+1]=(a[x+1]-t)%mod,a[x+1]=(a[x+1]+t)%mod;
                        t=(ll)WN[k+2]*a[x+d+2]%mod;
                        a[x+d+2]=(a[x+2]-t)%mod,a[x+2]=(a[x+2]+t)%mod;
                        t=(ll)WN[k+3]*a[x+d+3]%mod;
                        a[x+d+3]=(a[x+3]-t)%mod,a[x+3]=(a[x+3]+t)%mod;
                        k+=4;x+=4;
                    }
                }
            }
        }
    }
    void Dft(int *a,int *b){
        for(register int i=0;i<n;i++)if (rev[i]<i)swap(a[i],a[rev[i]]),swap(b[i],b[rev[i]]);
        for(register int d=1,len=L-1;d<n;d<<=1,--len){
            for(register int i=0;i<=d;i++)    WN[i]=wn[i<<len];    int t;
            if (d<=2)
            for(register int i=0;i<n;i+=d<<1){
                for(register int k=0,x=i;k<d;++k,++x){
                    t=(ll)WN[k]*a[x+d]%mod;
                    a[x+d]=(a[x]-t)%mod,a[x]=(a[x]+t)%mod;
                    t=(ll)WN[k]*b[x+d]%mod;
                    b[x+d]=(b[x]-t)%mod,b[x]=(b[x]+t)%mod;
                }
            }else{
                for(register int i=0;i<n;i+=d<<1){
                    for(register int k=0,x=i;k<d;){
                        t=(ll)WN[k]*a[x+d]%mod;
                        a[x+d]=(a[x]-t)%mod,a[x]=(a[x]+t)%mod;
                        t=(ll)WN[k]*b[x+d]%mod;
                        b[x+d]=(b[x]-t)%mod,b[x]=(b[x]+t)%mod;
                        t=(ll)WN[k+1]*a[x+d+1]%mod;
                        a[x+d+1]=(a[x+1]-t)%mod,a[x+1]=(a[x+1]+t)%mod;
                        t=(ll)WN[k+1]*b[x+d+1]%mod;
                        b[x+d+1]=(b[x+1]-t)%mod,b[x+1]=(b[x+1]+t)%mod;
                        t=(ll)WN[k+2]*a[x+d+2]%mod;
                        a[x+d+2]=(a[x+2]-t)%mod,a[x+2]=(a[x+2]+t)%mod;
                        t=(ll)WN[k+2]*b[x+d+2]%mod;
                        b[x+d+2]=(b[x+2]-t)%mod,b[x+2]=(b[x+2]+t)%mod;
                        t=(ll)WN[k+3]*a[x+d+3]%mod;
                        a[x+d+3]=(a[x+3]-t)%mod,a[x+3]=(a[x+3]+t)%mod;
                        t=(ll)WN[k+3]*b[x+d+3]%mod;
                        b[x+d+3]=(b[x+3]-t)%mod,b[x+3]=(b[x+3]+t)%mod;
                        k+=4,x+=4;
                    }
                }
            }
        }
    }
}lbc;
void FFT(int *a,int *b,int n){
    lbc.init(n*2);
    for(int i=n;i<lbc.n;i++)a[i]=b[i]=0;
    lbc.Dft(a,b);
    for(int i=0;i<lbc.n;i++)a[i]=(ll)a[i]*b[i]%mod;
    lbc.dft(a);
}
int f1[N],f2[N],fac[N],n,a[N],ni[N]; ll m;
int main(){
	n=read(); cin>>m;
	for(int i=0;i<=n;i++)a[i]=read(); fac[0]=ni[0]=1;
	for(int i=1;i<=n+1;i++){fac[i]=(ll)fac[i-1]*i%mod,mod-2; ni[i]=ksm(fac[i],mod-2);} //cout<<ni[1]<<endl;
	for(int i=0;i<=n;i++){f1[i]=(ll)fac[i]*a[i]%mod; f2[i]=ni[i];}
	reverse(&f1[0],&f1[n+1]);
	FFT(f1,f2,n+1);
	reverse(&f1[0],&f1[n+1]);
	for(int i=0;i<=n;i++){
		f1[i]=(ll)f1[i]*ni[i]%mod*ksm((ll)ni[i+1]*fac[i]%mod,m)%mod;
	}
	for(int i=0;i<=n;i++){f1[i]=(ll)ksm(-1,i)*fac[i]%mod*f1[i]%mod; f2[i]=ni[i];}
	reverse(&f1[0],&f1[n+1]);
	FFT(f1,f2,n+1);
	reverse(&f1[0],&f1[n+1]);
	for(int i=0;i<=n;i++){
		f1[i]=(ll)f1[i]*ksm(-1,i)%mod*ni[i]%mod;
	}
	for(int i=0;i<=n;i++){
		write((f1[i]+mod)%mod); putchar(' ');
	}
}