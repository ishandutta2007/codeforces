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
const int N=105;
int a[N];
int dp[N][N*N];
void prework(){
	int n=N-5;
	dp[1][0]=1;
	For(i,1,n)
		For(j,0,i*(i-1)/2)
			if (dp[i][j]){
				For(k,1,n-i){
					dp[i+k][j+(k+1)*k/2]=i;
					if (k>=3)
						dp[i+k][j+1]=-i;
				}
			}
}
void Solve(){
	int n=read(),k=read();
	k-=n;
	if (k<0||!dp[n][k])
		return (void)puts("NO");
	For(i,1,n)
		a[i]=i;
	for (int i=n,j;i>1;i=j){
		j=dp[i][k];
		if (j>0){
			reverse(a+i,a+n+1);
			k-=(i-j)*(i-j+1)/2;
		}
		else {
			k--;
			j=abs(j);
			int len=n-i+1;
			int m=i-j+1;
			int Lp=j+m/2,Rp=Lp+len-1;
			For(p,Lp,Rp)
				a[p]=a[p-Lp+i];
			For(v,1,m-1)
				if (v&1)
					a[--Lp]=v+j-1;
				else
					a[++Rp]=v+j-1;
		}
	}
	puts("YES");
	For(i,1,n)
		printf("%d ",a[i]);
	puts("");
}
int main(){
	prework();
	int T=read();
	while (T--)
		Solve();
	return 0;
}