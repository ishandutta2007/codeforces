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
template <class T> void ckmax(T &x,const T &y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T &y){
	if (x>y)
		x=y;
}
LL absl(LL x){
	return x<0?-x:x;
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
const int N=255;
int n,m;
int a[N][N];
int b[N][N];
int main(){
	n=read(),m=read();
	vi r(n),c(m);
	For(i,0,n-1)
		For(j,0,m-1){
			a[i][j]=read();
			ckmax(r[i],a[i][j]);
			ckmax(c[j],a[i][j]);
		}
	sort(r.begin(),r.end(),greater <int>());
	sort(c.begin(),c.end(),greater <int>());
	struct cmp{
		bool operator () (pii a,pii b){
			if (a.fi-a.se!=b.fi-b.se)
				return a.fi-a.se>b.fi-b.se;
			return a.fi<b.fi;
		}
	};
	set <pii,cmp> s0,s1;
	int pr=0,pc=0;
	r.pb(0),c.pb(0);
	Fod(i,n*m,1){
		if (r[pr]==i&&c[pc]==i){
			pr++,pc++;
			b[pr][pc]=i;
			For(j,1,pr-1)
				s0.insert(mp(j,pc));
			For(j,1,pc-1)
				s1.insert(mp(pr,j));
		}
		else if (r[pr]==i){
			pr++;
			b[pr][pc]=i;
			For(j,1,pc-1)
				s1.insert(mp(pr,j));
		}
		else if (c[pc]==i){
			pc++;
			b[pr][pc]=i;
			For(j,1,pr-1)
				s0.insert(mp(j,pc));
		}
		else {
			pii now;
			if (!s0.empty()){
				now=*s0.begin();
				s0.erase(s0.begin());
			}
			else {
				now=*prev(s1.end());
				s1.erase(prev(s1.end()));
			}
			b[now.fi][now.se]=i;
		}
	}
	For(i,1,n){
		For(j,1,m)
			printf("%d ",b[i][j]);
		puts("");
	}
	return 0;
}