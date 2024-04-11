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
const int N=105,M=100005;
const LL INF=1LL<<60;
LL n,k;
LL a[N];
LL ans=0;
LL v[M][N];
void solve(LL n,LL c,LL t){
	if (!n)
		return;
	if (c>k){
		ans+=t*n;
		return;
	}
	if (n<=100000){
		if (v[n][c]!=-INF)
			ans+=v[n][c]*t;
		else {
			LL ap=ans;
			solve(n,c+1,t);
			solve(n/a[c],c+1,-t);
			v[n][c]=(ans-ap)*t;
		}
	}
	else {
		solve(n,c+1,t);
		solve(n/a[c],c+1,-t);
	}
}
int main(){
	n=read(),k=read();
	For(i,1,k)
		a[i]=read();
	sort(a+1,a+k+1);
	reverse(a+1,a+k+1);
	For(i,0,M-1)
		For(j,0,N-1)
			v[i][j]=-INF;
	solve(n,1,1);
	cout<<ans<<endl;
	return 0;
}