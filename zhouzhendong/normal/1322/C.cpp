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
#define outtime() cerr<<"User Time = "\
	<<(double)clock()/CLOCKS_PER_SEC<<endl
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
const int N=500005;
int n,m;
int id[N];
LL a[N],s[N];
vi e[N];
int st[N],top=0;
LL gcd(LL x,LL y){
	return x?gcd(y%x,x):y;
}
void Solve(){
	n=read(),m=read();
	For(i,1,n)
		e[i].clear();
	For(i,1,n)
		a[i]=read(),id[i]=0;
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y);
	}
	int cnt=0;
	s[0]=0;
	For(i,1,m)
		s[i]=0;
	For(x,1,n)
		if (!e[x].empty()){
			for (auto y : e[x]){
				int v=id[y];
				if (s[v]==0)
					s[v]=++cnt,st[++top]=v;
				id[y]=s[v];
			}
			while (top)
				s[st[top--]]=0;
		}
	For(i,1,cnt)
		s[i]=0;
	For(i,1,n)
		s[id[i]]+=a[i];
	LL ans=0;
	For(i,1,cnt)
		if (s[i]!=0)
			ans=gcd(ans,s[i]);
	printf("%lld\n",ans);
}
int main(){
	int T=read();
	while (T--)
		Solve();
	return 0;
}