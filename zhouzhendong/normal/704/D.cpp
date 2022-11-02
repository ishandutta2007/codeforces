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
namespace flows{
	const int N=100005*8,M=N*3*2;
	struct Edge{
		int x,y,nxt,cap;
		Edge(){}
		Edge(int _x,int _y,int _nxt,int _cap){
			x=_x,y=_y,nxt=_nxt,cap=_cap;
		}
	}e[M];
	int n,S,T,cnt;
	int fst[N],cur[N],vis[N];
	int dis[N];
	void clear(int _n,int _S,int _T){
		n=_n,S=_S,T=_T;
		clr(fst),cnt=1;
	}
	void Add(int x,int y,int cap){
		e[++cnt]=Edge(x,y,fst[x],cap),fst[x]=cnt;
		e[++cnt]=Edge(y,x,fst[y],0),fst[y]=cnt;
	}
	int bfs(){
		static queue <int> q;
		while (!q.empty())
			q.pop();
		For(i,1,n)
			dis[i]=0;
		dis[S]=1,q.push(S);
		while (!q.empty()){
			int x=q.front();
			q.pop();
			for (int i=fst[x];i;i=e[i].nxt){
				int y=e[i].y;
				if (e[i].cap&&!dis[y]){
					dis[y]=dis[x]+1;
					q.push(y);
				}
			}
		}
		return (bool)dis[T];
	}
	int dfs(int x,int Lim){
		if (x==T||!Lim)
			return Lim;
		int rem=Lim;
		for (int &i=cur[x];i;i=e[i].nxt){
			int y=e[i].y;
			if (e[i].cap&&dis[x]+1==dis[y]){
				int d=dfs(y,min(rem,e[i].cap));
				rem-=d,e[i].cap-=d,e[i^1].cap+=d;
				if (!rem)
					break;
			}
		}
		return Lim-rem;
	}
	int Dinic(){
		int res=0;
		while (bfs()){
			clr(vis);
			For(i,1,n)
				cur[i]=fst[i];
			int d=dfs(S,1e9);
//			assert(d);
			res+=d;
		}
		return res;
	}
}
const int N=100005*8,INF=1e9;
int n,m,a,b;
vector <int> px,py;
pair <int,int> p[N];
int id[N];
vector <pair <int,int> > lr,lc;
int cx[N],cy[N];
pair <int,int> dx[N],dy[N];
void ckmin(int &a,int b){
	if (a>b)
		a=b;
}
void ckmax(int &a,int b){
	if (a<b)
		a=b;
}
int main(){
	n=read(),m=read(),a=read(),b=read();
	char ca='r',cb='b';
	if (a>b)
		swap(a,b),swap(ca,cb);
	For(i,1,n){
		p[i].fi=read(),p[i].se=read();
		px.pb(p[i].fi);
		py.pb(p[i].se);
	}
	For(i,1,m){
		int t=read(),l=read(),d=read();
		if (t==1)
			lr.pb(mp(l,d));
		else 
			lc.pb(mp(l,d));
	}
	sort(px.begin(),px.end());
	sort(py.begin(),py.end());
	px.resize(unique(px.begin(),px.end())-px.begin());
	py.resize(unique(py.begin(),py.end())-py.begin());
	For(i,1,n){
		p[i].fi=lower_bound(px.begin(),px.end(),p[i].fi)-px.begin();
		p[i].se=lower_bound(py.begin(),py.end(),p[i].se)-py.begin();
		cx[p[i].fi]++;
		cy[p[i].se]++;
//		printf("%d %d\n",p[i].fi,p[i].se);
	}
	For(i,0,(int)px.size()-1)
		dx[i].se=cx[i];
	For(i,0,(int)py.size()-1)
		dy[i].se=cy[i];
	for (auto &i : lr){
		int y=i.fi;
		i.fi=lower_bound(px.begin(),px.end(),i.fi)-px.begin();
		if (i.fi>=px.size()||px[i.fi]!=y)
			continue;
		// x - (cx[i.fi] - x) <= i.se
		// 2x <= i.se + cx[i.fi]
		// (cx[i.fi] - x) - x <= i.se
		// 2x >= cx[i.fi] - i.se
		ckmax(dx[i.fi].fi,(cx[i.fi]-i.se+1)/2);
		ckmin(dx[i.fi].se,(cx[i.fi]+i.se)/2);
		if (dx[i.fi].fi>dx[i.fi].se)
			return puts("-1"),0;
//		printf("1 %d %d\n",i.fi,i.se);
	}
	for (auto &i : lc){
		int y=i.fi;
		i.fi=lower_bound(py.begin(),py.end(),i.fi)-py.begin();
		if (i.fi>=py.size()||py[i.fi]!=y)
			continue;
		ckmax(dy[i.fi].fi,(cy[i.fi]-i.se+1)/2);
		ckmin(dy[i.fi].se,(cy[i.fi]+i.se)/2);
		if (dy[i.fi].fi>dy[i.fi].se)
			return puts("-1"),0;
//		printf("2 %d %d\n",i.fi,i.se);
	}
	int s=px.size()+py.size()+1,t=s+1,S=t+1,T=S+1;
	flows::clear(T,S,T);
	flows::Add(t,s,INF);
	For(i,1,n)
		flows::Add(p[i].fi+1,p[i].se+1+px.size(),1),id[i]=flows::cnt;
	int sx=0;
	For(i,0,(int)px.size()-1){
		flows::Add(S,i+1,dx[i].fi);
		flows::Add(s,i+1,dx[i].se-dx[i].fi);
		sx+=dx[i].fi;
	}
	flows::Add(s,T,sx);
	int sy=0;
	For(i,0,(int)py.size()-1){
		flows::Add(i+1+px.size(),T,dy[i].fi);
		flows::Add(i+1+px.size(),t,dy[i].se-dy[i].fi);
		sy+=dy[i].fi;
	}
	flows::Add(S,t,sy);
	int res=flows::Dinic();
	if (res<sx+sy)
		return puts("-1"),0;
	flows::S=s,flows::T=t;
	res=flows::Dinic();
//	outval(res);
	cout<<(LL)res*a+(LL)(n-res)*b<<endl;
	For(i,1,n)
		putchar(flows::e[id[i]].cap?ca:cb);
	puts("");
	return 0;
}