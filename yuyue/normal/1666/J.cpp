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
const int M=222;
int n,c[M][M];
LL dp[M][M],s[M][M];
int opt[M][M];
LL con(int l,int r,int ll,int rr){
	return s[r][rr]-s[r][ll-1]-s[l-1][rr]+s[l-1][ll-1];
}
int f[M];
void solve(int l,int r,int fa){
	if (l>r) return ;
	int x=opt[l][r];
//	cerr<<l<<" "<<r<<" "<<x<<"\n";
	f[x]=fa;
	if (l<r){
		solve(l,x-1,x);
		solve(x+1,r,x);
	}
	
}

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	n=read();
	F(i,1,n) F(j,1,n){
		c[i][j]=read();
		s[i][j]=(s[i][j-1]+s[i-1][j]-s[i-1][j-1]+c[i][j]);
	}
	F(le,1,n){
		F(l,1,n-le+1){
			int r=l+le-1;
			dp[l][r]=1e18;
			F(k,l,r){
				LL tmp=dp[l][k-1]+dp[k+1][r]+con(l,k-1,k,n)+con(1,l-1,l,k-1)+con(1,k,k+1,r)+con(k+1,r,r+1,n);
				if (tmp<dp[l][r]){
					dp[l][r]=tmp;
					opt[l][r]=k;
				}
			}
		}
	}
//	cout<<dp[1][n]<<" "<<opt[1][n]<<"\n";
	solve(1,n,0);
	F(i,1,n) cout<<f[i]<<" ";
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/