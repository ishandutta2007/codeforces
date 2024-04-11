#include<bits/stdc++.h>
#define LL long long
#define SZ(x) (int)x.size()-1
#define F(i,a,b) for (int i=a;i<=b;++i)
#define DF(i,a,b) for (int i=a;i>=b;--i)
#define pb push_back
#define ms(a,b) memset(a,b,sizeof a)
using namespace std;
int read(){
    char ch=getchar(); int w=1,c=0;
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
    for (;isdigit(ch);ch=getchar()) c=(c<<3)+(c<<1)+(ch^48);
    return w*c;
}
const int M=4040,mod=998244353;
int n,m,k;
bool fc[M],fr[M];
int dpc[M][M],dpr[M][M];
LL f[M],inv[M];
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL A(int x,int y){
	return f[x]*inv[x-y]%mod;
} 
int main(){
	n=read(); m=read(); k=read();
	inv[0]=f[0]=1; 
	F(i,1,max(n,m)) f[i]=f[i-1]*i%mod,inv[i]=fast(f[i],mod-2);
	F(i,1,k){
		int x=read(),y=read(); 
		fr[x]=1; fc[y]=1;
		x=read(),y=read(); 
		fr[x]=1; fc[y]=1;
	}
	int R0=0,C0=0;
	F(i,1,n) R0+=(!fr[i]);
	F(i,1,m) C0+=(!fc[i]);
	dpc[0][0]=dpr[0][0]=1;
	F(i,1,n){
		F(j,0,i) dpr[i][j]=dpr[i-1][j];
		if (!fr[i] && !fr[i-1]) {
			DF(j,i,0) if (i>=2) dpr[i][j+1]=(dpr[i][j+1]+dpr[i-2][j])%mod;
		}
	}
	F(i,1,m){
		F(j,0,i) dpc[i][j]=dpc[i-1][j];
		if (!fc[i] && !fc[i-1]) {
			DF(j,i,0) if (i>=2) dpc[i][j+1]=(dpc[i][j+1]+dpc[i-2][j])%mod;
		}
	}
	LL ans=0;
	F(i,0,n){//1*2
		F(j,0,m){//2*1
			if (R0-i-2*j<0 || C0-2*i-j<0) continue;
			ans=(ans+1ll*dpc[m][i]*dpr[n][j]%mod*A(R0-2*j,i)%mod*A(C0-2*i,j))%mod;
		}
	}
	cout<<ans<<"\n";
    return 0;
}