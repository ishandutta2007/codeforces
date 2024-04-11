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
const int N=200005;
int n,m;
vi e[N],r[N];
int in[N];
int vis1[N],vis2[N];
char res[N];
void dfs1(int x){
	if (vis1[x])
		return;
	vis1[x]=1;
	for (auto y : e[x])
		dfs1(y);
}
void dfs2(int x){
	if (vis2[x])
		return;
	vis2[x]=1;
	for (auto y : r[x])
		dfs2(y);
}
int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y);
		r[y].pb(x);
	}
	For(i,1,n)
		in[i]=r[i].size();
	queue <int> q;
	For(i,1,n)
		if (!in[i])
			q.push(i);
	while (!q.empty()){
		int x=q.front();
		q.pop();
		for (auto y : e[x])
			if (!--in[y])
				q.push(y);
	}
	For(i,1,n)
		if (in[i])
			return puts("-1"),0;
	int ans=0;
	For(i,1,n){
		if (!vis1[i]&&!vis2[i])
			res[i]='A',ans++;
		else
			res[i]='E';
		dfs1(i);
		dfs2(i);
	}
	printf("%d\n",ans);
	For(i,1,n)
		putchar(res[i]);
	puts("");
	return 0;
}