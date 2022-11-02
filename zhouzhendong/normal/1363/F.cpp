#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof (x))
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define fi first
#define se second
#define kill _z_kill
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define outval(x) cerr<<#x" = "<<x<<endl
#define outv(x) cerr<<#x" = "<<x<<"  "
#define outtag(x) cerr<<"--------------"#x"---------------"<<endl
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
	For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
#define User_Time ((double)clock()/CLOCKS_PER_SEC)
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
/*
int Pow(int x,int y){
	int ans=1;
	for (;y;y>>=1,x=(LL)x*x%mod)
		if (y&1)
			ans=(LL)ans*x%mod;
	return ans;
}
void Add(int &x,int y){
	if ((x+=y)>=mod)
		x-=mod;
}
void Del(int &x,int y){
	if ((x-=y)<0)
		x+=mod;
}
int Add(int x){
	return x>=mod?x-mod:x;
}
int Del(int x){
	return x<0?x+mod:x;
}
*/
void ckmax(int &x,int y){
	if (x<y)
		x=y;
}
void ckmin(int &x,int y){
	if (x>y)
		x=y;
}
const int N=2005,INF=1e9;
int n;
char s[N],t[N];
int cs[N][26],ct[N][26];
int dp[N][N];
void Solve(){
	n=read();
	scanf("%s%s",s+1,t+1);
	clr(cs[n+1]),clr(ct[n+1]);
	Fod(i,n,1){
		For(c,0,25)
			cs[i][c]=cs[i+1][c],ct[i][c]=ct[i+1][c];
		cs[i][s[i]-'a']++;
		ct[i][t[i]-'a']++;
	}
	For(i,0,25)
		if (cs[1][i]!=ct[1][i]){
			puts("-1");
			return;
		}
	For(i,0,n+1)
		For(j,0,n+1)
			dp[i][j]=INF;
	dp[n+1][n+1]=0;
	Fod(i,n+1,1)
		Fod(j,n+1,1){
			int v=dp[i][j];
			if (v==INF)
				continue;
			if (i>1&&j>1&&s[i-1]==t[j-1])
				ckmin(dp[i-1][j-1],v);
			if (j>1&&cs[i][t[j-1]-'a']>ct[j][t[j-1]-'a'])
				ckmin(dp[i][j-1],v);
			if (i>1)
				ckmin(dp[i-1][j],v+1);
		}
	printf("%d\n",dp[1][1]);
}
int main(){
	int T=read();
	while (T--)
		Solve();
	return 0;
}