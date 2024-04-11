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
const int N=2005;
int n,m;
char s[N],p[N];
int dp[N][N],ans[N];
int main(){
	scanf("%s",s+1);
	scanf("%s",p+1);
	n=strlen(s+1),m=strlen(p+1);
	For(i,0,n)
		For(j,0,n)
			dp[i][j]=N;
	dp[0][0]=0;
	For(i,1,n)
		For(j,0,n){
			dp[i][j]=min(dp[i][j],dp[i-1][j]+(j%m==0?0:1));
			if (s[i]==p[j%m+1])
				dp[i][j+1]=min(dp[i][j+1],dp[i-1][j]);
		}
	int Mx=0;
	For(i,0,n)
		if (dp[n][i]<N){
			Mx=max(Mx,i);
			ans[dp[n][i]]=i/m;
		}
	For(i,1,n-Mx-1)
		ans[i]=max(ans[i],ans[i-1]);
	for (int i=n-Mx;i<=n;i++)
		ans[i]=Mx/m,Mx--;
	For(i,0,n)
		printf("%d ",ans[i]);
	puts("");
	return 0;
}