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
typedef unsigned long long ull;
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
template <class T> void ckmax(T &x,const T y){
	if (x<y)
		x=y;
}
template <class T> void ckmin(T &x,const T y){
	if (x>y)
		x=y;
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
//int md(LL x){
//	return (x%mod+mod)%mod;
//}
const int N=500005*2;
int n,m;
vi v[N];
int a[N],id[N];
int res[N];
int now;
void gao(int x){
	now=(now+a[x])%m;
	swap(res[v[x][0]],res[v[x][1]]);
}
vi e[N];
int c[N];
void dfs(int x,int cc){
	c[x]=cc;
	for (auto y : e[x])
		if (!c[y])
			dfs(y,cc^1);
		else
			assert(c[y]==cc^1);
}
int main(){
	n=read();
	if (n%2==0){
		puts("First");
		For(i,1,n)
			printf("%d ",i);
		For(i,1,n)
			printf("%d ",i);
		puts("");
		fflush(stdout);
		return 0;
	}
	else {
		puts("Second");
		fflush(stdout);
		srand(time(NULL));
		iota(id+1,id+n+1,1);
		iota(id+n+1,id+n+n+1,1);
		random_shuffle(id+1,id+n*2+1);
		For(i,1,n*2){
//			v[id[i]].pb(i);
			v[read()].pb(i);
		}
		For(i,1,n){
			e[i].pb(n+i);
			e[n+i].pb(i);
			e[v[i][0]].pb(v[i][1]);
			e[v[i][1]].pb(v[i][0]);
		}
		m=n*2;
		For(i,1,n*2)
			if (!c[i])
				dfs(i,0);
		now=0;
		For(i,1,n*2)
			if (!c[i])
				now=(now+i)%m,res[i]=1;
		if (now){
			For(i,1,n*2)
				if (!c[i]){
					res[i]=0;
					now=(now-i+m)%m;
				}
				else {
					res[i]=1;
					now=(now+i)%m;
				}
		}
		assert(now==0);
		For(i,1,n*2)
			if (res[i])
				printf("%d ",i);
		puts("");
		fflush(stdout);
		return 0;
	}
	return 0;
}