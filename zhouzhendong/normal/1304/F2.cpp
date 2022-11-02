#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned uint;
typedef long double LD;
typedef vector <int> vi;
typedef pair <int,int> pii;
LL read(){
	LL x=0,f=0;
	char ch=getchar();
	while (!isdigit(ch))
		f=ch=='-',ch=getchar();
	while (isdigit(ch))
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return f?-x:x;
}
const int N=55,M=20005,INF=2e9;
int n,m,k;
int a[N][M],s[N][M],dp[N][M];
int f(int i,int l,int r){
	return s[i][r]-s[i][l-1];
}
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
int p[M],v[M];
int main(){
	n=read(),m=read(),k=read();
	For(i,1,n)
		For(j,1,m)
			a[i][j]=read(),s[i][j]=s[i][j-1]+a[i][j];
	For(i,1,m-k+1)
		dp[1][i]=f(1,i,i+k-1);
	For(i,2,n){
		For(j,1,m-k+1)
			dp[i][j]=-INF;
		{
			int v=-INF;
			For(j,k+1,m-k+1){
				v=max(v,dp[i-1][j-k]+f(i,j-k,j-1));
				ckmax(dp[i][j],v+f(i,j,j+k-1));
			}
			v=-INF;
			Fod(j,m-k+1,k+1){
				v=max(v,dp[i-1][j]+f(i,j,j+k-1));
				ckmax(dp[i][j-k],v+f(i,j-k,j-1));
			}
		}
		int l=1,r=0;
		For(j,1,m-k+1){
			while (l<=r&&p[l]<=j-k)
				l++;
			int tmp=dp[i-1][j]-s[i][j-1];
			while (l<=r&&v[r]<=tmp)
				r--;
			++r,p[r]=j,v[r]=tmp;
			ckmax(dp[i][j],v[l]+s[i][j+k-1]);
		}
		l=1,r=0;
		Fod(j,m-k+1,1){
			while (l<=r&&p[l]>=j+k)
				l++;
			int tmp=dp[i-1][j]+s[i][j+k-1];
			while (l<=r&&v[r]<=tmp)
				r--;
			++r,p[r]=j,v[r]=tmp;
			ckmax(dp[i][j],v[l]-s[i][j-1]);
		}
	}
	int ans=0;
	For(i,1,m-k+1)
		ckmax(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}