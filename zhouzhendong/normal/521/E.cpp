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
const int N=200005*2;
int n,m;
struct Edge{
	int x,y;
}edge[N];
struct Graph{
	static const int M=N*2;
	int cnt,y[M],nxt[M],fst[N];
	void clear(){
		cnt=1,clr(fst);
	}
	void add(int a,int b){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;
	}
}g,t;
int dfn[N],low[N],st[N],vise[N],Time=0,top=0,cnt;
vector <int> id[N],e[N];
vector <pair <int,int> > eid[N];
void Tarjan(int x){
	dfn[x]=low[x]=++Time;
	st[++top]=x;
	for (int i=g.fst[x];i;i=g.nxt[i]){
		if (vise[i>>1])
			continue;
		vise[i>>1]=1;
		int y=g.y[i];
		if (!dfn[y]){
			Tarjan(y);
			low[x]=min(low[x],low[y]);
			if (low[y]==dfn[x]){
				++cnt;
				t.add(x,cnt),t.add(cnt,x);
//				printf("(%d,%d)\n",cnt,x);
				do {
					t.add(st[top],cnt);
					t.add(cnt,st[top]);
//					printf("(%d,%d)\n",cnt,st[top]);
				} while (st[top--]!=y);
			}
			else if (low[y]>dfn[x]){
				assert(st[top]==y);
				t.add(x,y),t.add(y,x);
//				printf("(%d,%d)\n",x,y);
				top--;
			}
		}
		else
			low[x]=min(low[x],dfn[y]);
	}
}
int vis[N],fa[N],depth[N];
void dfs(int x,int d=0){
	vis[x]=1,depth[x]=d;
	for (int i=t.fst[x];i;i=t.nxt[i]){
		int y=t.y[i];
		if (!vis[y])
			fa[y]=x,dfs(y,d+1);
	}
}
int pre[N],pos[N];
int Solve(int c){
//	outval(id[c].size());outval(eid[c].size());
	if (id[c].size()>=eid[c].size())
		return 0;
	for (auto x : id[c])
		e[x].clear(),vis[x]=0,pre[x]=0;
	for (auto E : eid[c])
		e[E.fi].pb(E.se),e[E.se].pb(E.fi);
	int x=id[c][0],f;
	while (1){
		int flag=0;
		vis[x]=1;
		for (auto y : e[x])
			if (y!=pre[x]){
				if (!vis[y])
					pre[y]=x,x=y;
				else
					f=y,flag=1;
				break;
			}
		if (flag)
			break;
	}
	deque <int> s;
	for (int i=x;i!=f;i=pre[i])
		s.pb(i);
	s.pb(f);
	while (e[s[0]].size()<3)
		s.pb(s.front()),s.pop_front();
//	outarr(s,0,(int)s.size()-1);
	For(i,0,(int)s.size()-1)
		pos[s[i]]=i,vis[s[i]]=2;
	x=s[0],f=0;
	queue <int> q;
	q.push(x);
	while (!q.empty()){
		int flag=0;
		x=q.front();
		q.pop();
		vis[x]=3;
		for (auto y : e[x])
			if (y!=pre[x]){
				if (vis[y]<2)
					pre[y]=x,q.push(y);
				else if (vis[y]<=2&&(x!=s[0]||(x==s[0]&&y!=s[1]&&y!=s.back()))){
					f=y,flag=1;
					break;
				}
			}
		if (flag)
			break;
	}
	puts("YES");
	vector <int> v1,v2,v3;
	v1.pb(f);
	for (int i=x;i!=s[0];i=pre[i])
		v1.pb(i);
	v1.pb(s[0]);
	Fod(i,pos[f],0)
		v2.pb(s[i]);
	For(i,pos[f],(int)s.size()-1)
		v3.pb(s[i]);
	v3.pb(s[0]);
	printf("%d ",(int)v1.size());
	for (auto i : v1)
		printf("%d ",i);
	puts("");
	printf("%d ",(int)v2.size());
	for (auto i : v2)
		printf("%d ",i);
	puts("");
	printf("%d ",(int)v3.size());
	for (auto i : v3)
		printf("%d ",i);
	puts("");
	return 1;
}
int main(){
	n=read(),m=read();
	g.clear();
	For(i,1,m){
		int x=edge[i].x=read(),y=edge[i].y=read();
		g.add(x,y),g.add(y,x);
	}
	t.clear();
	cnt=n;
	For(i,1,n)
		if (!dfn[i])
			Tarjan(i);
	For(i,1,cnt)
		if (!vis[i])
			dfs(i);
	For(x,n+1,cnt)
		for (int i=t.fst[x];i;i=t.nxt[i]){
			int y=t.y[i];
			id[x].pb(y);
		}
	For(i,1,m){
		int x=edge[i].x,y=edge[i].y;
		if (depth[x]>depth[y])
			swap(x,y);
		if (fa[y]==x)
			continue;
		eid[fa[y]].pb(mp(x,y));
	}
	For(i,n+1,cnt)
		if (Solve(i))
			return 0;
	puts("NO");
	return 0;
}