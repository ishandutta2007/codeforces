#include<bits/stdc++.h>
using namespace std;

int n,m;
struct R{
	int to,nex;
}r[404000];
int hea[202000]={0},cnt=1,g[202000],s[202000];
int fa[202000],top[202000],dep[202000]={0},bs[202000]={0},sz[202000],id[202000],tid=0;
struct L{
	int u,v,w;
}tmp;
vector<L>vec[202000];

namespace bit_g{
	int c[202000];
	void RE(){
		memset(c,0,sizeof c);
	}
	void A(int x,int v){
		for (int i=x;i<=n;i+=(i&-i)){
			c[i]+=v;
		}
	}
	int que(int x){
		int t=0;
		for (int i=x;i>0;i-=(i&-i)){
			t+=c[i];
		}
		return t;
	}
	int Q(int st,int en){
		return que(en)-que(st-1);
	}
}
namespace bit_s{
	int c[202000];
	void RE(){
		memset(c,0,sizeof c);
	}
	void A(int x,int v){
		for (int i=x;i<=n;i+=(i&-i)){
			c[i]+=v;
		}
	}
	int que(int x){
		int t=0;
		for (int i=x;i>0;i-=(i&-i)){
			t+=c[i];
		}
		return t;
	}
	int Q(int st,int en){
		return que(en)-que(st-1);
	}
}

void pre(int x,int fff){
	fa[x]=fff;
	dep[x]=dep[fff]+1;
	sz[x]=1;
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to; if (y==fff) continue;
		pre(y,x);
		sz[x]+=sz[y];
		if (sz[y]>sz[bs[x]]) bs[x]=y;
	}
}
void pour_shit(int x,int ttt){
	id[x]=++tid;
	top[x]=ttt;
	if (bs[x]) pour_shit(bs[x],ttt);
	int y;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to; if (y==fa[x]||y==bs[x]) continue;
		pour_shit(y,y);
	}
}

int lca(int x,int y){
	while (top[x]!=top[y]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	if (dep[x]<dep[y]) swap(x,y);
	return y;
}
int from(int x,int y){
	while (top[x]!=top[y]){
		if (fa[top[x]]==y) return top[x];
		x=fa[top[x]];
	}
	return bs[y];
}
int asks(int x,int y){
	int res=0;
	while (top[x]!=top[y]){
		res+=bit_s::Q(id[top[x]],id[x]);
		x=fa[top[x]];
	}
	res+=bit_s::Q(id[y],id[x]);
	return res;
}
int askg(int x,int y){
	int res=0;
	while (top[x]!=top[y]){
		res+=bit_g::Q(id[top[x]],id[x]);
		x=fa[top[x]];
	}
	res+=bit_g::Q(id[y],id[x]);
	return res;
}

void dfs(int x){
	g[x]=s[x]=0;
	int y,t,fr;
	for (int i=hea[x];i>0;i=r[i].nex){
		y=r[i].to; if (y==fa[x]) continue;
		dfs(y);
		s[x]+=g[y];
	}
	g[x]=s[x];
	for (int i=0;i<(int)vec[x].size();i++){
		tmp=vec[x][i];
		t=s[x];
		for (int ttt=0;ttt<2;ttt++){
			if (tmp.u!=x){
				fr=from(tmp.u,x);
				t+=asks(tmp.u,fr)-askg(tmp.u,fr);
			}
			swap(tmp.u,tmp.v);
		}
		g[x]=max(g[x],t+tmp.w);
	}
	bit_s::A(id[x],s[x]);
	bit_g::A(id[x],g[x]);
}

int main(){
	//freopen("haha.txt","r",stdin);
	bit_g::RE();bit_s::RE();
	scanf("%d%d",&n,&m);
	int x,y,z;
	for (int i=1;i<n;i++){
		scanf("%d",&y);x=i+1;
		r[++cnt]=(R){y,hea[x]}; hea[x]=cnt;
		r[++cnt]=(R){x,hea[y]}; hea[y]=cnt;
	}
	pre(1,0);
	pour_shit(1,1);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		vec[lca(x,y)].push_back((L){x,y,z});
	}
	dfs(1);
	printf("%d\n",g[1]);
}