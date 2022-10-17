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
const int M=5050;
int n,a[M],pre[M][M],suf[M][M];
void work(){
	n=read();
	F(i,1,n) a[i]=read();
	F(i,1,n){
		F(j,1,n) pre[i][j]=pre[i-1][j]+(j>=a[i]);
	}
	F(i,1,n) suf[n+1][i]=0;
	DF(i,n,1) F(j,1,n) suf[i][j]=suf[i+1][j]+(j>=a[i]);
	LL ans=0;
	F(i,1,n){
		F(j,i+1,n){
			ans=(ans+pre[i-1][a[j]]*suf[j+1][a[i]]);
		}
	}
	cout<<ans<<"\n";
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	int T=read();
	while (T--) work();
	return 0;
}
/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/