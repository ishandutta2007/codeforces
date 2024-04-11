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
const int N=1005;
int n,m;
int a[N][N],r[N][N],c[N][N];
int rc[N],cc[N];
int main(){
	n=read(),m=read();
	For(i,1,n)
		For(j,1,m)
			a[i][j]=r[i][j]=c[j][i]=read();
	For(i,1,n){
		sort(r[i]+1,r[i]+m+1);
		rc[i]=unique(r[i]+1,r[i]+m+1)-r[i]-1;
	}
	For(i,1,m){
		sort(c[i]+1,c[i]+n+1);
		cc[i]=unique(c[i]+1,c[i]+n+1)-c[i]-1;
	}
	For(i,1,n){
		For(j,1,m){
			int k1=lower_bound(r[i]+1,r[i]+rc[i]+1,a[i][j])-r[i];
			int k2=lower_bound(c[j]+1,c[j]+cc[j]+1,a[i][j])-c[j];
			int mx=max(k1,k2)+max(rc[i]-k1,cc[j]-k2);
			printf("%d ",mx);
		}
		puts("");
	}
	return 0;
}