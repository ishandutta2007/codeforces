#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=a;i<=b;i++)
#define Fod(i,b,a) for (int i=b;i>=a;i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define _SEED_ ('C'+'L'+'Y'+'A'+'K'+'I'+'O'+'I')
#define outval(x) printf(#x" = %d\n",x)
#define outvec(x) printf("vec "#x" = ");for (auto _v : x)printf("%d ",_v);puts("")
#define outtag(x) puts("----------"#x"----------")
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
const int N=155,INF=1e8;
int n;
int a[N];
char s[N];
int dp[N][N][N];
void ckmax(int &x,int y){
	x=x>y?x:y;
}
int f[N];
int main(){
	n=read();
	For(i,1,n){
		a[i]=read();
		if (a[i]==-1)
			a[i]=-INF;
	}
	scanf("%s",s+1);
	s[0]='$',s[n+1]='%';
	clr(dp);
	For(i,0,n)
		For(k,0,n)
			dp[i+1][i][k]=a[k];
	For(i,1,n)
		For(j,i,n)
			For(k,0,n)
				dp[i][j][k]=-INF;
	For(d,0,n-1)
		For(i,1,n-d){
			int j=i+d;
			For(k,0,n){
				if (k>0)
					ckmax(dp[i][j][k],dp[i][j][0]+a[k]);
				if (k&1){
					Fod(R,j,i)
						if (s[i-1]==s[R])
							ckmax(dp[i][j][k],dp[i][R-1][k+1]+dp[R+1][j][0]);
				}
				else {
					For(L,i,j)
						ckmax(dp[i][j][k],dp[L+1][j][k+1]+dp[i][L-1][0]);
				}
			}
		}
/*	For(k,0,n){
		For(i,1,n){
			For(j,1,n)
				printf("%10d ",dp[i][j][k]);
			puts("");
		}
		puts("");
	}*/
	For(i,1,n){
		ckmax(f[i],f[i-1]);
		For(j,i,n)
			ckmax(f[j],f[i-1]+dp[i][j][0]);
	}
	cout<<f[n]<<endl;
	return 0;
}