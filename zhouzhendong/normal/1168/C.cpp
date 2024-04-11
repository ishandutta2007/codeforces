#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"---------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
						For(_x,L,R)cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f|=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=300005,B=20;
int n,q;
int a[N];
int last[B+1];
int dp[N][B+1];
int main(){
	n=read(),q=read();
	For(i,1,n)
		a[i]=read();
	For(i,0,B)
		last[i]=dp[n+1][i]=n+1;
	Fod(i,n,1){
		For(j,0,B)
			if (a[i]>>j&1)
				dp[i][j]=i;
			else
				dp[i][j]=n+1;
		For(j,0,B)
			if (a[i]>>j&1)
				For(k,0,B)
					dp[i][k]=min(dp[i][k],dp[last[j]][k]);
		For(j,0,B)
			if (a[i]>>j&1)
				last[j]=i;
	}
	while (q--){
		int L=read(),R=read();
		int mi=n+1;
		For(i,0,B)
			if (a[R]>>i&1)
				mi=min(mi,dp[L][i]);
		puts(mi<=R?"Shi":"Fou");
	}
	return 0;
}