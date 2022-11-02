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
//int Pow(int x,int y){
//	int ans=1;
//	for (;y;y>>=1,x=(LL)x*x%mod)
//		if (y&1)
//			ans=(LL)ans*x%mod;
//	return ans;
//}
//void Add(int &x,int y){
//	if ((x+=y)>=mod)
//		x-=mod;
//}
//void Del(int &x,int y){
//	if ((x-=y)<0)
//		x+=mod;
//}
//int Add(int x){
//	return x>=mod?x-mod:x;
//}
//int Del(int x){
//	return x<0?x+mod:x;
//}
//void ckmax(int &x,int y){
//	if (x<y)
//		x=y;
//}
//void ckmin(int &x,int y){
//	if (x>y)
//		x=y;
//}
const int N=1005;
int n,m;
char s[N][N];
int f0[N],f1[N];
int vis[N][N];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y){
	if (s[x][y]!='#'||vis[x][y])
		return;
	vis[x][y]=1;
	For(k,0,3)
		dfs(x+dx[k],y+dy[k]);
}
int main(){
	n=read(),m=read();
	For(i,1,n)
		scanf("%s",s[i]+1);
	For(i,1,n)
		For(j,1,m)
			if (s[i][j]=='#')
				f0[i]=f1[j]=1;
	{
		int v0=1,v1=1;
		For(i,1,n)
			v0&=f0[i];
		For(i,1,m)
			v1&=f1[i];
		if (v0^v1)
			return puts("-1"),0;
	}
	For(i,1,n){
		int L=1,R=m;
		while (L<=R&&s[i][L]!='#')
			L++;
		while (L<=R&&s[i][R]!='#')
			R--;
		For(j,L,R)
			if (s[i][j]!='#')
				return puts("-1"),0;
	}
	For(i,1,m){
		int L=1,R=n;
		while (L<=R&&s[L][i]!='#')
			L++;
		while (L<=R&&s[R][i]!='#')
			R--;
		For(j,L,R)
			if (s[j][i]!='#')
				return puts("-1"),0;
	}
	int cnt=0;
	For(i,1,n)
		For(j,1,m)
			if (s[i][j]=='#'&&!vis[i][j]){
				cnt++;
				dfs(i,j);
			}
	cout<<cnt<<endl;
	return 0;
}