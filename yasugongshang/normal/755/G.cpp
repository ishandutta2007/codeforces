#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
#define ll long long
const int N=(1<<16)|111,G=3,mod=998244353;
int wn[N],WN[N];
int rev[N];
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
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
void FFT(int *a,int *b,int *c,int n){
    lbc.init(n*2);
    for(int i=n;i<lbc.n;i++)a[i]=b[i]=c[i]=0;
    lbc.Dft(a,b);
    for(int i=0;i<lbc.n;i++)c[i]=(ll)a[i]*b[i]%mod;
    lbc.dft(c);
}
int n,k,ans[2][N],f[3][N],z0[N],z1[N],z2[N],zs[3][N],z3[N],z4[N],g[3][N];
void solve(int *a,int *b,int *c,int *d,int *ans){
	memcpy(z3,a,sizeof(z3)); memcpy(z4,c,sizeof(z4));
	FFT(z3,z4,z0,k);
	memcpy(z3,b,sizeof(z3)); memcpy(z4,d,sizeof(z4));
	//for(int i=0;i<k;i++)cout<<z3[i]<<" "<<z4[i]<<endl;
	FFT(z3,z4,z1,k);
	ans[0]=z0[0];
	for(int i=1;i<k;i++)ans[i]=(z0[i]+z1[i-1])%mod;
}
signed main(){
	n=read(); k=read()+1;
	if(n%4==1){
		ans[0][0]=ans[0][1]=ans[1][0]=1;
	}else if(n%4==2){
		ans[0][0]=ans[0][2]=ans[1][0]=ans[1][1]=1; ans[0][1]=3;
	}else if(n%4==3){
		ans[0][0]=ans[1][0]=ans[1][2]=ans[0][3]=1; ans[1][1]=3; ans[0][1]=ans[0][2]=5;
	}else ans[0][0]=1;
	n>>=2;
	f[0][0]=f[0][4]=f[1][0]=f[2][0]=f[2][2]=f[1][3]=1; f[2][1]=3; f[1][1]=f[1][2]=5;
	f[0][1]=f[0][3]=7; f[0][2]=13;
	for(;n;n>>=1){
		if(n&1){
			memcpy(g,f,sizeof(g)); memcpy(zs,ans,sizeof(zs));
			lbc.init(k*2);
			for(int i=k;i<lbc.n;i++)g[0][i]=g[1][i]=g[2][i]=zs[0][i]=zs[1][i]=0;
			//for(int i=1;i<k;i++)cout<<g[0][i]<<" "<<zs[0][i]<<endl;
			lbc.Dft(g[0],g[1]); lbc.Dft(zs[1],zs[0]); lbc.ddft(g[2]);
			for(int i=0;i<lbc.n;i++){z1[i]=(ll)g[0][i]*zs[0][i]%mod; z2[i]=(ll)g[1][i]*zs[1][i]%mod;}
			lbc.dft(z1); lbc.dft(z2);
			ans[0][0]=z1[0];
			for(int i=1;i<k;i++)ans[0][i]=(z1[i]+z2[i-1])%mod;
			for(int i=0;i<lbc.n;i++){z1[i]=(ll)g[1][i]*zs[0][i]%mod; z2[i]=(ll)g[2][i]*zs[1][i]%mod;}
			lbc.dft(z1); lbc.dft(z2);
			ans[1][0]=z1[0];
			for(int i=1;i<k;i++)ans[1][i]=(z1[i]+z2[i-1])%mod;
			//for(int i=0;i<k;i++)cout<<(f[1][i]+mod)%mod<<" "<<(f[2][i]+mod)%mod<<" "<<(z2[i]+mod)%mod<<" "<<(ans[1][i]+mod)%mod<<endl;
			//puts("zhu");
		}
		memcpy(g,f,sizeof(g));
		lbc.init(k*2);
		for(int i=k;i<lbc.n;i++)g[0][i]=g[1][i]=g[2][i]=0;
		lbc.Dft(g[0],g[1]); lbc.ddft(g[2]);
		for(int i=0;i<lbc.n;i++){
			z1[i]=(ll)g[0][i]*g[0][i]%mod; z2[i]=(ll)g[1][i]*g[1][i]%mod;
		}
		lbc.dft(z1); lbc.dft(z2);
		f[0][0]=z1[0];
		for(int i=1;i<k;i++)f[0][i]=(z1[i]+z2[i-1])%mod;
		for(int i=0;i<lbc.n;i++){
			z1[i]=(ll)g[1][i]*g[0][i]%mod; z2[i]=(ll)g[2][i]*g[1][i]%mod;
		}
		lbc.dft(z1); lbc.dft(z2);
		f[1][0]=z1[0];
		for(int i=1;i<k;i++)f[1][i]=(z1[i]+z2[i-1])%mod;
		for(int i=0;i<lbc.n;i++){
			z1[i]=(ll)g[1][i]*g[1][i]%mod; z2[i]=(ll)g[2][i]*g[2][i]%mod;
		}
		lbc.dft(z1); lbc.dft(z2);
		f[2][0]=z1[0];
		for(int i=1;i<k;i++)f[2][i]=(z1[i]+z2[i-1])%mod;
		//for(int i=0;i<10;i++)cout<<(f[2][i]+mod)%mod<<" "; puts("");
	}
	for(int i=1;i<k;i++){
		write((ans[0][i]+mod)%mod); putchar(' ');
	}
}