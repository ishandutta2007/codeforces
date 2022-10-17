#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define SZ(x) ((int)x.size()-1)
#define ms(a,b) memset(a,b,sizeof a)
#define F(i,a,b) for (int i=(a);i<=(b);++i)
#define DF(i,a,b) for (int i=(a);i>=(b);--i)
//#define mp make_pair
//#define OO(x) fixed<<setprecision(x)
using namespace std;
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
inline int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=2020;
int n,mod;
vector<int> v[M];
LL dp[M][M],g[M][M],pre[M][M],suf[M][M],t[M];
void dfs(int x,int fa){
	for (int y:v[x]){
		if (y^fa){
			dfs(y,x);
		}
	}
	F(i,1,n) pre[0][i]=suf[v[x].size()+1][i]=1;
	F(i,1,v[x].size()){
		int y=v[x][i-1];
		F(j,1,n) pre[i][j]=pre[i-1][j];
		if (y==fa){
			continue;
		}
		F(j,1,n) pre[i][j]=pre[i][j]*g[y][j]%mod;
	}
	DF(i,v[x].size(),1){
		int y=v[x][i-1];
		F(j,1,n) suf[i][j]=suf[i+1][j];
		if (y==fa){
			continue;
		}
//		t[0]=1;
		F(j,1,n){
			t[j]=pre[i-1][j]*suf[i][j]%mod;
			t[j]=(t[j-1]+t[j])%mod;
			dp[x][j]=(dp[x][j]+t[j-1]*dp[y][j])%mod;
		}
		
		F(j,1,n) suf[i][j]=suf[i][j]*g[y][j]%mod;
	}
	F(i,1,n){
		dp[x][i]=(dp[x][i]+pre[v[x].size()][i])%mod;
//		cerr<<dp[x][i]<<" "<<x<<" "<<i<<" "<<pre[v[x].size()][i]<<" !!!\n";
	}
	F(i,1,n) g[x][i]=(g[x][i-1]+dp[x][i])%mod;
}

LL fast(LL x,LL p){
	LL ret=1;
	for (;p;p>>=1,x=x*x%mod) if (p&1) ret=ret*x%mod;
	return ret;
}
LL fac[M],inv[M],iv[M];
void init(int n){
	fac[0]=1;
	F(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=fast(fac[n],mod-2);
	DF(i,n,1) inv[i-1]=inv[i]*i%mod;
	iv[1]=1;
	F(i,2,n) iv[i]=(mod-mod/i)*iv[mod%i]%mod;
}
LL C(int x,int y){
	if (y<0 || x<y) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
LL G[M],H[M]; 
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read(); mod=read(); init(n);
	F(i,1,n-1){
		int x=read(),y=read();	
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,0);
	F(i,1,n) G[i]=pre[v[1].size()][i];
	DF(i,n,1) G[i]=G[i]+mod-G[i-1],G[i]%=mod;
	H[1]=G[1];
	F(i,2,n){
		LL tmp=G[i];
		F(j,1,i-1){
			tmp=(tmp+(mod-H[j])*C(i-1,j-1))%mod;
		}
		H[i]=tmp;
	}
	F(i,1,n-1){
		cout<<H[i]<<" ";
	}
//	cerr<<'\n';
//	F(i,1,n) cerr<<G[i]<<" ";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/