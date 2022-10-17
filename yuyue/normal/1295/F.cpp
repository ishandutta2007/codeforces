#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
using namespace std;
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=210,mod=998244353;
int n;
LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL fac[M],inv[M];
LL C(int n,int m){
	LL ret=1;
	F(i,1,m) ret=ret*(n-i+1)%mod;
	return ret*inv[m]%mod;
}
LL prob[M][M],pr[M][M],f[M][M];
int l[M],r[M],t[M],ct;
int main(){
	n=read();
	fac[0]=1; 
	F(i,1,n*2) fac[i]=fac[i-1]*i%mod,inv[i]=fast(fac[i],mod-2);
	DF(i,n,1){
		l[i]=read(); r[i]=read();
		t[++ct]=l[i]; t[++ct]=r[i]; t[++ct]=r[i]+1;
	}
	
	sort(t+1,t+ct+1);
	int N=unique(t+1,t+ct+1)-t-1;
	F(i,1,N){
		int len;
		if (i==N) len=0;
		else len=t[i+1]-1-t[i];
		int l0=t[i],r0=t[i]+len; 
//		cout<<l0<<" "<<r0<<"    okk\n";
		F(j,1,n){
			prob[i][j]=C(len+j,j)*fast(fast(len+1,j),mod-2)%mod;
//			cout<<prob[i][j]<<"\n";
		}			

		F(j,1,n){
			if (l[j]<=l0 && r[j]>=r0) {
				pr[i][j]=1ll*(len+1)*fast(r[j]-l[j]+1,mod-2)%mod;
			}	

		}
	}
	F(i,0,N) f[0][i]=1;
	F(i,1,n){
		F(j,1,N){
			LL tmp=1;
			DF(k,i,1){
				if (pr[j][k]){
					tmp=tmp*pr[j][k]%mod;
					f[i][j]=(f[i][j]+f[k-1][j-1]*tmp%mod*prob[j][i-k+1])%mod;
				}
				else break;
			}
//			cout<<i<<" "<<j<<" "<<f[i][j]*8%mod<<"    mdzz\n";
		}	

		F(j,1,N) f[i][j]=(f[i][j]+f[i][j-1])%mod;
//		assert(f[i][N]==1);
	}
	cout<<f[n][N]<<"\n";
	return 0;
}