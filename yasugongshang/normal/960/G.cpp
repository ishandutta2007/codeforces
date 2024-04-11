#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
#define ll long long
const int N=(1<<19)|111,G=3,mod=998244353;
int wn[N],WN[N];
int rev[N];
inline char gc(){;
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define getchar gc

inline int read(){
    int x=0; char ch=gc(); bool positive=1;
    for (;!isdigit(ch);ch=gc())if(ch=='-')positive=0;
    for (;isdigit(ch);ch=gc())x=x*10+ch-'0';
    return positive?x:-x;
}
inline void write(int a){
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void writeln(int a){
	write(a); puts("");
}
ll ppow(ll x,ll k){ll ans=1;for(;k;k>>=1,x=x*x%mod)if (k&1)ans=ans*x%mod;return ans;}
#define ksm ppow
#define pow ppow
struct fft{
    int n,L;
    void zheng(int *a,int n){
    	for(int i=0;i<n;i++)a[i]=(a[i]+mod)%mod;
	}
    void init(int len){
        n=1; L=0; while(n<len)n<<=1,L++;
        ll w=ppow(G,(mod-1)/n);
        for(register int i=0;i<n;i++)wn[i]=i?wn[i-1]*w%mod:1,rev[i]=rev[i>>1]>>1|((i&1)<<L-1);
    }
    void dft(int *a){
        for(register int i=0;i<n;i++)if (rev[i]<i)swap(a[i],a[rev[i]]);
        zheng(a,n); 
        for(register int d=1,len=L-1;d<n;d<<=1,--len){
            for(register int i=0;i<=d;i++)    WN[i]=wn[i<<len];int t;
            for(register int i=0;i<n;i+=d<<1){
                for(register int k=0,x=i;k<d;++k,++x){
                    t=(ll)WN[k]*a[x+d]%mod;
                    a[x+d]=a[x]-t<0?a[x]-t+mod:a[x]-t,a[x]=a[x]+t>=mod?a[x]+t-mod:a[x]+t;
                }
            }
        }
        reverse(a+1,a+n);ll inv=ppow(n,mod-2);
        for(register int i=0;i<n;i++)a[i]=a[i]*inv%mod;
    }
    void ddft(int *a){
        for(register int i=0;i<n;i++)if (rev[i]<i)swap(a[i],a[rev[i]]);
        zheng(a,n); 
        for(register int d=1,len=L-1;d<n;d<<=1,--len){
            for(register int i=0;i<=d;i++)    WN[i]=wn[i<<len];int t;
            for(register int i=0;i<n;i+=d<<1){
                for(register int k=0,x=i;k<d;++k,++x){
                    t=(ll)WN[k]*a[x+d]%mod;
                    a[x+d]=a[x]-t<0?a[x]-t+mod:a[x]-t,a[x]=a[x]+t>=mod?a[x]+t-mod:a[x]+t;
                }
            }
        }
    }
    void Dft(int *a,int *b){
        for(register int i=0;i<n;i++)if (rev[i]<i)swap(a[i],a[rev[i]]),swap(b[i],b[rev[i]]);
        zheng(a,n); zheng(b,n);
        for(register int d=1,len=L-1;d<n;d<<=1,--len){
            for(register int i=0;i<=d;i++)    WN[i]=wn[i<<len];    int t;
            for(register int i=0;i<n;i+=d<<1){
                for(register int k=0,x=i;k<d;++k,++x){
                    t=(ll)WN[k]*a[x+d]%mod;
                    a[x+d]=a[x]-t<0?a[x]-t+mod:a[x]-t,a[x]=a[x]+t>=mod?a[x]+t-mod:a[x]+t;
                    t=(ll)WN[k]*b[x+d]%mod;
                    b[x+d]=b[x]-t<0?b[x]-t+mod:b[x]-t,b[x]=b[x]+t>=mod?b[x]+t-mod:b[x]+t;
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
int n,A,B,a[N],b[N],f1[N],f2[N],ans[N];
ll fac[N],ni[N];
#include<cstring>
void solve(int *ans,int len){
	if(len==1){
		ans[1]=1; return;
	}else if(len&1){//ans=ans*(x+len-1)
		solve(ans,len-1);
		for(int i=len;i;i--)ans[i]=(ans[i-1]+(ll)ans[i]*(len-1))%mod; ans[0]=0;
	}else{
		int mid=len>>1;
		solve(ans,mid);
		ll k1=mid,k2=ksm(k1,mod-2); 
		for(int i=0;i<=mid;i++){
			f1[i]=i?f1[i-1]*k1%mod:1; f2[i]=i?f2[i-1]*k2%mod:1;
			a[i]=fac[i]*ans[i]%mod*f1[i]%mod; b[i]=ni[i];
		}
		//cout<fac[mid]<<" "<<b[0]<<endl;
		reverse(&a[0],&a[mid+1]);
		FFT(a,b,mid+1);
		reverse(&a[0],&a[mid+1]);
		for(int i=0;i<=mid;i++)a[i]=a[i]*ni[i]%mod*f2[i]%mod;
		FFT(ans,a,mid+1);
		//for(int i=1;i<=len;i++)cout<<(ans[i]+mod)%mod<<" "; puts("");
	}
}
inline ll c(int a,int b){
	return fac[a]*ni[b]%mod*ni[a-b]%mod;
}
signed main(){
	n=read(); A=read(); B=read(); fac[0]=1;
	if(n<A+B-1||A==0||B==0){
		puts("0"); return 0;
	}
	if(n==1){
		puts("1"); return 0;
	}
	for(int i=1;i<200000;i++)fac[i]=fac[i-1]*i%mod; ni[200000-1]=ksm(fac[200000-1],mod-2);
	for(int i=200000-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	solve(ans,n-1); //cout<<ans[A+B-2]<<endl;
	cout<<(ans[A+B-2]*c(A+B-2,A-1)%mod+mod)%mod<<endl;
}