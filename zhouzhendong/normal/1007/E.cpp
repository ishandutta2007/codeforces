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
const int N=205;
const LL INF=1e15;
int n,t;
LL k;
LL a[N],b[N],c[N];
LL sa[N],sb[N],sc[N];
LL f[N][N][2],g[N][N][2];
void ckmin(LL &a,LL b){
	if (a>b)
		a=b;
}
int main(){
	n=read(),t=read(),k=read();
	For(i,1,n)
		a[i]=read(),b[i]=read(),c[i]=read();
	++n,a[n]=INF,b[n]=0,c[n]=INF;
	For(i,1,n)
		sa[i]=sa[i-1]+a[i],sb[i]=sb[i-1]+b[i],sc[i]=sc[i-1]+c[i];
	For(i,0,N-1)
		For(j,0,N-1)
			For(k,0,1)
				f[i][j][k]=g[i][j][k]=INF;
	clr(f[0]),clr(g[0]);
	For(i,1,n)
		For(j,0,t)
			For(z,0,1){
				if (f[i-1][j][z]<INF&&a[i]*z+b[i]*j<=c[i]){
					ckmin(f[i][j][z],f[i-1][j][z]);
					LL val=(sa[i-1]*z+sb[i]*j+k-1)/k;
					if (val*k<=sa[i]*z+sb[i]*j)
						ckmin(g[i][j][z],val);
				}
				For(r,0,j-1){
					if (g[i][r][z]>=INF)
						continue;
					LL rem=sa[i]*z+sb[i]*r-g[i][r][z]*k;
					LL x=(max(rem+(j-r)*b[i]-c[i],0LL)+k-1)/k;
					if (x*k>rem||f[i-1][j-r][0]>=INF)
						continue;
					ckmin(f[i][j][z],g[i][r][z]+x+f[i-1][j-r][0]);
					LL val=(sb[i-1]*(j-r)+k-1)/k;
					if (val*k<=sb[i]*(j-r)+rem-x*k)
						ckmin(g[i][j][z],g[i][r][z]+x+val);
				}
			}
	cout<<f[n][t][1]<<endl;
	return 0;
}