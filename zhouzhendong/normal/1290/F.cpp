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
const int N=5,mod=998244353;
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
int n,m;
int x[N],y[N];
int dp[32][20][20][20][20][2][2];
int Px[1<<N],Py[1<<N],Nx[1<<N],Ny[1<<N];
int main(){
	n=read(),m=read();
	For(i,0,n-1)
		x[i]=read(),y[i]=read();
	For(s,0,(1<<n)-1)
		For(i,0,n-1)
			if (s>>i&1){
				(x[i]>0?Px:Nx)[s]+=abs(x[i]);
				(y[i]>0?Py:Ny)[s]+=abs(y[i]);
			}
	clr(dp);
	dp[0][0][0][0][0][0][0]=1;
	For(i,0,29){
		int bit=m>>i&1;
		For(px,0,19) For(py,0,19)
		For(nx,0,19) For(ny,0,19)
		For(kx,0,1) For(ky,0,1){
			int v=dp[i][px][py][nx][ny][kx][ky];
			if (!v)
				continue;
			For(s,0,(1<<n)-1){
				int a=px+Px[s],b=py+Py[s],c=nx+Nx[s],d=ny+Ny[s];
				if ((a&1)==(c&1)&&(b&1)==(d&1))
					Add(dp[i+1][a>>1][b>>1][c>>1][d>>1]
						[(a&1)>bit||(a&1)==bit&&kx]
						[(b&1)>bit||(b&1)==bit&&ky],v);
			}
		}
	}
	cout<<(dp[30][0][0][0][0][0][0]-1+mod)%mod<<endl;
	return 0;
}