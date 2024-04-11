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
const int N=100005;
int n,m;
vector <pii> e[N];
LL dep[N];
void dfs(int x,LL d){
	dep[x]=d;
	for (auto E : e[x])
		dfs(E.fi,d+E.se);
}
vector <pair <LL,LL> > v;
namespace lct{
	int fa[N],son[N][2];
	LL val[N],tag[N];
	int isroot(int x){
		return son[fa[x]][0]!=x&&son[fa[x]][1]!=x;
	}
	int wson(int x){
		return son[fa[x]][1]==x;
	}
	void rotate(int x){
		int y=fa[x],z=fa[y],L=wson(x),R=L^1;
		if (!isroot(y))
			son[z][wson(y)]=x;
		fa[x]=z,fa[y]=x,fa[son[x][R]]=y;
		son[y][L]=son[x][R],son[x][R]=y;
	}
	void pushson(int x,LL v){
		val[x]=max(val[x],v);
		tag[x]=max(tag[x],v);
	}
	void pushdown(int x){
		if (tag[x]){
			pushson(son[x][0],tag[x]);
			pushson(son[x][1],tag[x]);
			tag[x]=0;
		}
	}
	void pushadd(int x){
		if (!isroot(x))
			pushadd(fa[x]);
		pushdown(x);
	}
	void splay(int x){
		pushadd(x);
		for (int y=fa[x];!isroot(x);rotate(x),y=fa[x])
			if (!isroot(y))
				rotate(wson(x)==wson(y)?y:x);
	}
	void access(int x,LL start_time){
		int _x=x;
		int t=0;
		while (x){
			splay(x);
			if (x!=_x){
				v.pb(mp(val[x]==0?1:val[x]+dep[x]+1,start_time+dep[x]));
				son[x][1]=t;
			}
			t=x;
			x=fa[x];
		}
		x=_x;
		splay(x);
		if (son[x][0])
			pushson(son[x][0],start_time);
	}
}
void gao(LL res){
	printf("%lld ",res);
	if (res==-1)
		res=1e18;
	int cnt=0;
	for (auto i : v)
		cnt+=i.se<res;
	printf("%d\n",cnt);
	exit(0);
}
int main(){
	n=read(),m=read();
	For(i,1,n-1){
		int x=read(),y=read(),z=read();
		e[x].pb(mp(y,z));
		lct::fa[y]=x,lct::son[x][1]=y;
	}
	dfs(1,0);
	For(i,1,m){
		int s=read(),t=read();
		lct::access(s,t);
	}
	sort(v.begin(),v.end());
	priority_queue <LL,vector <LL>,greater <LL> > q;
	LL t=1;
	int i=0;
	for (auto p : v){
		while (!q.empty()&&t<p.fi){
			if (q.top()<t){
				For(j,i+1,(int)v.size()-1)
					if (v[j].se<q.top())
						assert(0);
				gao(q.top());
			}
			q.pop();
			t++;
		}
		t=max(t,p.fi);
		q.push(p.se);
		i++;
	}
	while (!q.empty()){
		if (q.top()<t)
			gao(q.top());
		q.pop();
		t++;
	}
	gao(-1);
	return 0;
}