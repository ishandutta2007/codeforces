#include <bits/stdc++.h>
#define clr(x) memset(x,0,sizeof x)
#define For(i,a,b) for (int i=(a);i<=(b);i++)
#define Fod(i,b,a) for (int i=(b);i>=(a);i--)
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define fi first
#define se second
#define outval(x) cerr<<#x" = "<<x<<endl
#define outtag(x) cerr<<"-----------------"#x"-----------------\n"
#define outarr(a,L,R) cerr<<#a"["<<L<<".."<<R<<"] = ";\
                    For(_x,L,R) cerr<<a[_x]<<" ";cerr<<endl;
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
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
const int N=300005;
int n,m,q,k;
int bh[N],bel[N];
struct Graph{
	static const int M=N*2;
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=1,clr(fst);
	}
	void clear(vector <int> &id){
		cnt=1;
		for (auto i : id)
			fst[i]=0;
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g,g2;
map <int,int> Map[N];
namespace TJ{
	int dfn[N],low[N],st[N],inst[N];
	int vise[N];
	int Time=0,top=0,cnt=0;
	void init(vector <int> &id,int ec){
		Time=top=cnt=0;
		for (auto i : id)
			dfn[i]=low[i]=inst[i]=bh[i]=0;
		For(i,1,ec>>1)
			vise[i]=0;
	}
	void Tarjan(int x){
		dfn[x]=low[x]=++Time;
		inst[x]=1;
		st[++top]=x;
		for (int i=g.fst[x];i;i=g.nxt[i]){
			if (vise[i>>1])
				continue;
			vise[i>>1]=1;
			int y=g.y[i];
			if (!dfn[y]){
				Tarjan(y);
				low[x]=min(low[x],low[y]);
			}
			else if (inst[y])
				low[x]=min(low[x],low[y]);
		}
		if (dfn[x]==low[x]){
			bh[st[top]]=++cnt;
			inst[st[top]]=0;
			while (st[top--]!=x){
				bh[st[top]]=cnt;
				inst[st[top]]=0;
			}
		}
	}
	void Main(){
		g.clear();
		For(i,1,m){
			int x=read(),y=read();
			g.add(x,y),g.add(y,x);
		}
		For(i,1,n)
			if (!dfn[i])
				Tarjan(i);
		k=cnt;
	}
}
int fa[N][20],depth[N],I[N],CI=0,ct[N],cntt=0,root[N];
void dfs(int x,int pre,int d){
	depth[x]=d,fa[x][0]=pre,I[x]=++CI,ct[x]=cntt;
	For(i,1,19)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int i=g2.fst[x];i;i=g2.nxt[i]){
		int y=g2.y[i];
		if (y!=pre)
			dfs(y,x,d+1);
	}
}
int LCA(int x,int y){
	if (depth[x]<depth[y])
		swap(x,y);
	Fod(i,19,0)
		if (depth[x]-(1<<i)>=depth[y])
			x=fa[x][i];
	if (x==y)
		return x;
	Fod(i,19,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int lastans=0;
int getv(){
	int v=read();
	v=(v+lastans)%n;
	if (v==0)
		v=n;
	return v;
}
bool cmpI(int a,int b){
	return I[a]<I[b];
}
int visrt[N];
int st[N],top;
int main(){
	n=read(),m=read(),q=read();
	TJ::Main();
	g2.clear();
	For(i,2,g.cnt){
		int x=bh[g.y[i^1]],y=bh[g.y[i]];
		if (x!=y&&!Map[x][y]){
			Map[x][y]=1;
			g2.add(x,y);
		}
	}
	For(i,1,k)
		if (!I[i])
			root[++cntt]=i,dfs(i,0,0);
	swap(bh,bel);
	For(T,1,q){
		int ni=read(),mi=read();
		vector <int> id,x,vid,tmp;
		vector <pair <int,int> > p;
		For(i,1,ni){
			int v=bel[getv()];
			x.pb(v),id.pb(v);
		}
		For(i,1,mi){
			int x=bel[getv()],y=bel[getv()];
			p.pb(mp(x,y));
			id.pb(x),id.pb(y);
		}
		sort(id.begin(),id.end(),cmpI);
		id.resize(unique(id.begin(),id.end())-id.begin());
		for (auto i : id)
			if (i==root[ct[i]])
				visrt[i]=T;
		for (auto i : id)
			if (visrt[root[ct[i]]]!=T)
				visrt[i]=T,tmp.pb(root[ct[i]]);
		for (auto i : tmp)
			id.pb(i);
		sort(id.begin(),id.end(),cmpI);
		vid=id;
		top=0;
		For(_,0,(int)id.size()-1){
			int x=id[_];
			if (top>0){
				int y=LCA(x,st[top]);
				while (top>1&&depth[st[top-1]]>=depth[y]){
					p.pb(mp(st[top],st[top-1]));
					top--;
				}
				if (y!=st[top]){
					vid.pb(y);
					p.pb(mp(st[top],y));
					st[top]=y;
				}
			}
			st[++top]=x;
			if (_==(int)id.size()-1||ct[x]!=ct[id[_+1]]){
				while (top>1){
					p.pb(mp(st[top],st[top-1]));
					top--;
				}
				top=0;
			}
		}
		g.clear(vid);
		for (auto e : p){
			g.add(e.fi,e.se);
			g.add(e.se,e.fi);
		}
		TJ::init(vid,g.cnt);
		for (auto i : vid)
			if (!TJ::dfn[i])
				TJ::Tarjan(i);
		int flag=0;
		for (auto i : x)
			if (bh[i]!=bh[x.back()]){
				flag=1;
				break;
			}
		if (flag)
			puts("NO");
		else
			puts("YES"),lastans=(lastans+T)%n;
	}
	return 0;
}