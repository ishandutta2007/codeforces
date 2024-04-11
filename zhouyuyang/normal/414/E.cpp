#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,Q,cnt,rt;
int dfn[N],ed[N];
int id[N],fa[N],ch[N][2];
struct node{
	int now,mx,mn,tg;
	node(){
		mn=1<<30;
		mx=-mn;
	}
}t[N];
void Update(int x,int v){
	if (x){
		t[x].now+=v; t[x].mn+=v;
		t[x].mx+=v; t[x].tg+=v;
	}
}
void update(int x){
	int ls=ch[x][0],rs=ch[x][1];
	t[x].mn=min(t[x].now,min(t[ls].mn,t[rs].mn));
	t[x].mx=max(t[x].now,max(t[ls].mx,t[rs].mx));
}
void pushdown(int x){
	if (!t[x].tg) return;
	Update(ch[x][0],t[x].tg);
	Update(ch[x][1],t[x].tg);
	t[x].tg=0;
}

void rotate(int x){
	int y=fa[x],z=fa[y];
	int r=(ch[y][0]==x),t;
	if (t=ch[y][!r]=ch[x][r]) fa[t]=y;
	if (fa[x]=z) ch[z][ch[z][1]==y]=x;
	ch[fa[y]=x][r]=y; update(y);
}
void splay(int x,int aim){
	for (pushdown(x);fa[x]!=aim;rotate(x)){
		int y=fa[x],z=fa[y];
		pushdown(z); pushdown(y); pushdown(x);
		if (fa[y]!=aim)
			if ((ch[z][0]==y)^(ch[y][0]==x))
				rotate(x);
			else rotate(y);
	}
	update(x);
	if (!aim) rt=x;
}

vector<int> e[N];
void dfs(int x,int dep){
	dfn[x]=++cnt; id[cnt]=x; t[cnt].now=dep;
	for (int i=0;i<e[x].size();i++) dfs(e[x][i],dep+1);
	ed[x]=++cnt; id[cnt]=x; t[cnt].now=dep;
}
void build(int &k,int l,int r,int f){
	fa[k=(l+r)/2]=f;
	if (l<k) build(ch[k][0],l,k-1,k);
	if (k<r) build(ch[k][1],k+1,r,k);
	update(k);
}
int find(int x,int v){
	int l=ch[x][0],r=ch[x][1];
	pushdown(x);
	if (t[r].mn<=v&&v<=t[r].mx) return find(r,v);
	return t[x].now==v?x:find(l,v);
}

int pre(int x){
	splay(x,0); x=ch[x][0];
	for (;ch[x][1];x=ch[x][1]);
	pushdown(x); return x;
}
int suf(int x){
	splay(x,0); x=ch[x][1];
	for (;ch[x][0];x=ch[x][0]);
	pushdown(x); return x;
}
void get(int x,int y){
	splay(x,0);
	splay(y,x);
}
int main(){
	scanf("%d%d",&n,&Q);
	for (int i=1;i<=n;i++){
		int cnt,x; scanf("%d",&cnt);
		while (cnt--){
			scanf("%d",&x);
			e[i].push_back(x);
		}
	}
	cnt++; dfs(1,1); cnt++;
	build(rt,1,cnt,0);
	while (Q--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			scanf("%d",&y);
			if (x==y) puts("0");
			else{
				x=dfn[x]; y=dfn[y]; get(x,y);
				int z=(ch[x][0]==y?t[ch[y][1]]:t[ch[y][0]]).mn;
				printf("%d\n",t[x].now+t[y].now-2*min(z-1,min(t[x].now,t[y].now)));
			}
		}
		else if (tp==2){
			scanf("%d",&y); get(1,dfn[x]);
			int w=id[find(ch[dfn[x]][0],t[dfn[x]].now-y)];
			int l=pre(dfn[x]),r=suf(ed[x]); get(l,r);
			int t=ch[r][0]; ch[r][0]=0;
			update(r); update(l);
			r=ed[w],l=pre(r); get(l,r);
			ch[r][0]=t; fa[t]=r;
			Update(t,-y+1); splay(t,0);
		}
		else
			printf("%d\n",id[find(rt,x+1)]);
	}
}