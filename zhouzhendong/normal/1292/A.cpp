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
template <class T> void ckmax(T &x,T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,T y){
	if (y<x)
		x=y;
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
const int N=100005;
int n,q;
int val[2][N];
int cnt=0;
int get(int x){
	return (val[0][x]&&val[0][x+1])||(val[1][x]&&val[1][x+1]);
}
int main(){
	n=read(),q=read();
	val[0][0]=1;
	For(i,1,n)
		val[0][i]=val[1][i]=1;
	val[1][n+1]=1;
	For(i,0,n)
		cnt+=get(i);
	For(i,1,q){
		int x=read()-1,y=read();
		cnt-=get(y-1);
		cnt-=get(y);
		val[x][y]^=1;
		cnt+=get(y-1);
		cnt+=get(y);
		puts(cnt==n+1?"Yes":"No");
	}
	return 0;
}