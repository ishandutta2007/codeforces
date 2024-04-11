#include<bits/stdc++.h>
#define ll long long
#define pli pair<ll,int>
#define pii pair<int,int>
#define N 100005
#define inf (1ll<<60)
using namespace std;

int n,m,q;

struct edge{
	int to,next;
}e[N*2];
int head[N],tot;
void add(int x,int y){
	e[++tot]=(edge){y,head[x]};
	head[x]=tot;
}
int fa[N],dep[N],sz[N];
void dfs(int x){
	dep[x]=dep[fa[x]]+1;
	sz[x]=1;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			fa[e[i].to]=x;
			dfs(e[i].to);
			sz[x]+=sz[e[i].to];
		}
}
int top[N],dfn[N],las[N],T;
void dfs2(int x,int tp){
	top[x]=tp;
	dfn[x]=++T;
	int k=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&sz[e[i].to]>sz[k])
			k=e[i].to;
	if (k) dfs2(k,tp);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=k)
			dfs2(e[i].to,e[i].to);
	las[x]=T;
}

ll tg[265000];
pli t[265000];
vector<pii > vec[N];
void upd(int x,ll v){
	t[x].first+=v;
	tg[x]+=v;
}
void pushdown(int k){
	if (!tg[k]) return;
	upd(k*2,tg[k]);
	upd(k*2+1,tg[k]);
	tg[k]=0;
}
void build(int k,int l,int r){
	if (l==r){
		if (vec[l].empty())
			t[k]=pli(inf,0);
		else t[k]=pli(vec[l].back().first,l);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=min(t[k*2],t[k*2+1]);
}
void erase(int k,int l,int r,int p){
	if (l==r){
		vec[l].pop_back();
		if (vec[l].empty())
			t[k]=pli(inf,0);
		else t[k]=pli(vec[l].back().first+tg[k],l);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (p<=mid) erase(k*2,l,mid,p);
	else erase(k*2+1,mid+1,r,p);
	t[k]=min(t[k*2],t[k*2+1]);
}
void change(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		upd(k,v);
		return;
	}
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) change(k*2,l,mid,x,y,v);
	else if (x>mid) change(k*2+1,mid+1,r,x,y,v);
	else change(k*2,l,mid,x,mid,v),
		 change(k*2+1,mid+1,r,mid+1,y,v);
	t[k]=min(t[k*2],t[k*2+1]);
}
pli ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	pushdown(k);
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return min(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}
pli ask(int x,int y){
	pli ans=pli(inf,0);
	for (;top[x]!=top[y];x=fa[top[x]]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=min(ans,ask(1,1,n,dfn[top[x]],dfn[x]));
	}
	if (dep[x]<dep[y]) swap(x,y);
	return min(ans,ask(1,1,n,dfn[y],dfn[x]));
}

vector<int> ans;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1);
	dfs2(1,1);
	for (int i=1;i<=m;i++){
		int x; scanf("%d",&x);
		vec[dfn[x]].push_back(pii(i,i));
	}
	for (int i=1;i<=n;i++){
		sort(vec[i].begin(),vec[i].end());
		reverse(vec[i].begin(),vec[i].end());
	}
	build(1,1,n);
	while (q--){
		int tp,x,y,k;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==1){
			scanf("%d",&k);
			ans.clear();
			while (k--){
				pli tmp=ask(x,y);
				if (tmp.second==0) break;
				ans.push_back(vec[tmp.second].back().second);
				erase(1,1,n,tmp.second);
			}
			printf("%d ",ans.size());
			for (int i=0;i<ans.size();i++)
				printf("%d ",ans[i]);
			puts("");
		}
		else
			change(1,1,n,dfn[x],las[x],y);
	}
}