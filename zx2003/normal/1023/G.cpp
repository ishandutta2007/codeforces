#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
typedef vector<P>V;
const int N=1e5+5,I=1<<30;
int n,m,u,v,w,i,rt[N];
V e[N],ev[N];
struct node{
	int ch[2],fa;
	int tg,v,mn,w,s,sz,lv,rv;bool tp,lt,rt;
	inline int dir(int x){return ch[1]==x;}
	inline void addtag(int d){tg+=d;tp?v+=d:v-=d;lt?lv+=d:lv-=d;rt?rv+=d:rv-=d;mn-=d*2;}
}t[N*2];int tcnt;
inline void upd(int x){
	int l=t[x].ch[0],r=t[x].ch[1];
	if(l)t[x].lv=t[l].lv,t[x].lt=t[l].lt;else t[x].lv=t[x].v,t[x].lt=t[x].tp;
	if(r)t[x].rv=t[r].rv,t[x].rt=t[r].rt;else t[x].rv=t[x].v,t[x].rt=t[x].tp;
	t[x].s=t[l].s+t[r].s+t[x].w;t[x].sz=t[l].sz+t[r].sz+1;
	t[x].mn=min(min(t[l].mn,t[r].mn),t[x].tp?r && !t[r].lt?t[r].lv-t[x].v:I:
		l && t[l].rt?t[x].v-t[l].rv:I);
}
inline void pushdown(int x){
	int&z=t[x].tg;
	if(z){if(t[x].ch[0])t[t[x].ch[0]].addtag(z);if(t[x].ch[1])t[t[x].ch[1]].addtag(z);z=0;}
}
inline void rotate(int x){
	int y=t[x].fa,z=t[y].fa,o=t[y].dir(x);
	t[z].ch[t[z].dir(y)]=x;t[x].fa=z;
	t[t[x].ch[!o]].fa=y;t[y].ch[o]=t[x].ch[!o];
	t[x].ch[!o]=y;t[y].fa=x;upd(y);
}
inline void splay(int x,int xx=0){
	static int st[N*2];int w=0,y,z;
	for(y=x;y!=xx;y=t[y].fa)st[++w]=y;
	for(;w;)pushdown(st[w--]);
	for(;t[x].fa!=xx;rotate(x)){
		y=t[x].fa;z=t[y].fa;
		if(z!=xx)rotate(t[z].dir(y)==t[y].dir(x)?y:x);
	}
	upd(x);
}
inline void go(int&x,int o){for(;t[x].ch[o];x=t[x].ch[o]);}
inline int merge(int x,int y){
	t[x].fa=t[y].fa=0;
	if(!x || !y)return x|y;
	go(x,1);splay(x);t[x].ch[1]=y;t[y].fa=x;upd(x);return x;
}
inline void stre(int&x,int le){
	if(!x)return;
	for(;t[x].mn<=le*2;){
		for(;;){
			pushdown(x);
			int l=t[x].ch[0],r=t[x].ch[1],y=t[x].fa,o=t[y].dir(x);
			if(!t[x].tp && l && t[l].rt && t[x].v-t[l].rv<=le*2){
				go(l,1);splay(l,x);
				t[l].w+=t[x].w;if(t[l].w>0)t[l].tp=0,t[l].v=t[x].v;upd(l);
				x=merge(t[l].w?l:t[l].ch[0],r);t[y].ch[o]=x;t[x].fa=y;if(!x)x=y;break;
			}
			if(t[x].tp && r && !t[r].lt && t[r].lv-t[x].v<=le*2){
				go(r,0);splay(r,x);
				t[r].w+=t[x].w;if(t[r].w<0)t[r].tp=1,t[r].v=t[x].v;upd(r);
				x=merge(l,t[r].w?r:t[r].ch[1]);t[y].ch[o]=x;t[x].fa=y;if(!x)x=y;break;
			}
			x=t[l].mn<=le*2?l:r;
		}
		splay(x);
	}
	t[x].addtag(le);
}
inline void ins(int&x,int v,int w,int u=0){
	auto getn=[&](){if(!u)u=++tcnt;t[u]=node{0,0,x,0,v,I,w,w,1,w,w,0,0,0};x=u;};
	if(!x)getn();else for(;;){
		if(v==t[x].v){t[x].w+=w;break;}
		pushdown(x);int o=v>t[x].v;
		if(!t[x].ch[o]){t[x].ch[o]=u?u:tcnt+1;getn();break;}
		x=t[x].ch[o];
	}
	splay(x);if(!t[x].w)x=merge(t[x].ch[0],t[x].ch[1]);else t[x].tp=t[x].w<0;upd(x);
}
int aa[N*2],ww;
void dfss(int x){
	pushdown(x);
	if(t[x].ch[0])dfss(t[x].ch[0]);
	aa[++ww]=x;
	if(t[x].ch[1])dfss(t[x].ch[1]);
}
inline void join(int&x,int y){
	ww=0;dfss(y);
	for(i=1;i<=ww;++i)ins(x,t[aa[i]].v,t[aa[i]].w,aa[i]);
}
inline int getv(int&x,int k){
	if(!x)return 0;
	int ans=0;
	for(;;){
		pushdown(x);int o=k>=t[x].v;
		if(o)ans+=t[t[x].ch[0]].s+t[x].w;if(t[x].ch[o])x=t[x].ch[o];else break;
	}
	splay(x);return ans;
}
void dfs(int x,int fa){
	for(auto u:e[x]){
		int y,l;tie(y,l)=u;
		if(y==fa)continue;
		dfs(y,x);
		stre(rt[y],2*l-1);
		if(t[rt[x]].sz<t[rt[y]].sz)swap(rt[x],rt[y]);
		if(rt[y])join(rt[x],rt[y]);
	}
	for(auto&u:ev[x])u.second+=getv(rt[x],u.first);
	stre(rt[x],1);
	for(auto u:ev[x]){
		int xx,y,z;tie(xx,y)=u;z=getv(rt[x],xx);
		if(y>z)ins(rt[x],xx,y-z),ins(rt[x],xx+1,z-y);
	}
}
int main(){
	t[0].mn=I;
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	for(i=1;i<n;++i)cin>>u>>v>>w,e[u].push_back({v,w}),e[v].push_back({u,w});
	cin>>m;
	for(i=1;i<=m;++i)cin>>w>>v>>u,ev[u].push_back({w*2,v});
	int ans=0,zz=0;
	dfs(1,0);
	ww=0;dfss(rt[1]);for(i=1;i<=ww;++i)ans=max(ans,zz+=t[aa[i]].w);
	cout<<ans<<endl;
}