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
const int N=100005;
int n,g;
LL k;
set <int> e[N];
int sz[N],mx[N];
void dfs1(int x,int pre){
	sz[x]=1,mx[x]=0;
	for (auto y : e[x])
		if (y!=pre){
			dfs1(y,x);
			sz[x]+=sz[y];
			ckmax(mx[x],sz[y]);
		}
	ckmax(mx[x],n-sz[x]);
	if (!g||mx[x]<mx[g])
		g=x;
}
int fa[N],dep[N];
void dfs2(int x,int pre,int d){
	fa[x]=pre,dep[x]=d;
	sz[x]=1;
	e[x].erase(pre);
	for (auto y : e[x])
		dfs2(y,x,d+1),sz[x]+=sz[y];
}
vi id[N];
int rmv_tag[N];
void dfs3(int x,int subt){
	if (!rmv_tag[x])
		id[subt].pb(x);
	for (auto y : e[x])
		dfs3(y,subt);
}
void remove(int x,int f=1){
	rmv_tag[x]=1;
	if (f)
		e[fa[x]].erase(x);
}
vector <pii> res;
int main(){
	n=read(),k=read();
	For(i,1,n-1){
		int x=read(),y=read();
		e[x].insert(y),e[y].insert(x);
	}
	dfs1(1,0);
	dfs2(g,0,0);
	LL s=0;
	For(i,1,n)
		s+=dep[i];
	if (k>s||(s-k)%2)
		return puts("NO"),0;
	k=(s-k)/2;
	priority_queue <pii> q1;
	for (auto i : e[g]){
		q1.push(mp(sz[i],i));
		id[i].clear();
		dfs3(i,i);
		sort(id[i].begin(),id[i].end(),[&](int a,int b){
			return dep[a]<dep[b];
		});
	}
//	outtag(before: stage 1);
	while (k>0){
		int x=q1.top().se;
		q1.pop();
		if (sz[x]<=1)
			break;
		while (rmv_tag[id[x].back()])
			id[x].pop_back();
		int y=id[x].back();
		id[x].pop_back();
		int f=fa[y];
		assert(dep[f]>0);
		remove(y);
		if (dep[f]>k){
			while (dep[f]>k)
				f=fa[f];
			assert(dep[f]>0);
			remove(f,0);
			res.pb(mp(y,f));
			k-=dep[f];
			break;
		}
		k-=dep[f];
		int z=e[f].size()>0?*e[f].begin():f;
		assert(e[z].size()==0);
		remove(z);
		res.pb(mp(y,z));
		sz[x]-=2;
		q1.push(mp(sz[x],x));
	}
	if (k>0)
		return puts("NO"),0;
	priority_queue <pii> q2;
	id[g]={g};
	q2.push(mp(id[g].size(),g));
	for (auto i : e[g]){
		id[i].clear();
		dfs3(i,i);
		q2.push(mp(id[i].size(),i));
	}
//	outtag(before: stage 2);
	while (!q2.empty()){
		int x=q2.top().se;
		q2.pop();
		assert(!q2.empty());
		int y=q2.top().se;
		q2.pop();
		assert(id[x].size()>0&&id[y].size()>0);
		res.pb(mp(id[x].back(),id[y].back()));
		id[x].pop_back();
		id[y].pop_back();
		if (!id[x].empty())
			q2.push(mp(id[x].size(),x));
		if (!id[y].empty())
			q2.push(mp(id[y].size(),y));
	}
	puts("YES");
	assert(res.size()==n/2);
	for (auto i : res)
		printf("%d %d\n",i.fi,i.se);
	return 0;
}