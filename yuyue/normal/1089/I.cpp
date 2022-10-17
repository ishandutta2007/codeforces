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
const int M=444;
int mod;
LL ans[M],f[M],g[M][M],fac[M];
//f[n] for any [p_1~p_i]!=[1~i] 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read(); mod=read();
	int n=400;
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	F(i,1,n){
		f[i]=fac[i];
		F(j,1,i-1){
			f[i]=(f[i]+mod-f[j]*fac[i-j]%mod)%mod;
		}
	}
	g[0][0]=1;
	F(i,1,n){
		F(j,1,n){
			F(k,1,j){
				g[i][j]=(g[i][j]+g[i-1][j-k]*fac[k])%mod;
			}
		}
	}
	ans[1]=1; ans[2]=2;
	F(i,3,n){
		ans[i]=fac[i];
		F(j,1,i-1){
			ans[i]=(ans[i]+mod-2ll*f[j]*fac[i-j]%mod)%mod;
		}
		F(j,3,i-1){
			ans[i]=(ans[i]+mod-g[j][i]*ans[j]%mod)%mod;
		}
	}
	while (T--){
		int x=read();
		cout<<ans[x]<<"\n";
	}
	return 0;
}