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
const int N=100005;
int n,m;
vi e[N];
int fa[N];
int sz[N],ce[N];
int getf(int x){
	return fa[x]==x?x:fa[x]=getf(fa[x]);
}
vi id;
int main(){
	n=read(),m=read();
	For(i,1,m){
		int x=read(),y=read();
		e[x].pb(y),e[y].pb(x);
	}
	For(i,1,n){
		fa[i]=i,sz[i]=1;
		id.pb(i);
	}
	For(x,1,n){
		for (auto y : id)
			ce[y]=0;
		for (auto y : e[x])
			ce[getf(y)]++;
		vi nid;
		nid.pb(getf(x));
		for (auto y : id){
			if (y==getf(x))
				continue;
			if (ce[y]<sz[y]){
				sz[getf(x)]+=sz[y];
				fa[y]=x;
			}
			else {
				nid.pb(y);
			}
		}
		swap(id,nid);
	}
	cout<<(int)id.size()-1<<endl;
	return 0;
}