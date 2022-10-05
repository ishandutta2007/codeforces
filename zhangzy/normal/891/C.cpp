#include<bits/stdc++.h>
#define unomp unordered_map
using namespace std;

struct E{
	int u,v,w;
}e[505000];
vector<E>vec[505000];
unomp<int,unomp<int,vector<int> > >que;
unomp<int,vector<int> >::iterator iv;

int fa[505000],sz[505000];
int n,m,T,x,y,z,die[505000],clo,top;
struct opt{
	int who,to,orgsz;
}st[1001000];

int GF(int x){
	return fa[x]==x? x: GF(fa[x]);
}

bool uni(int x,int y){
	int fx,fy;
	if ((fx=GF(x))==(fy=GF(y))) return 0;
	if (sz[fx]>sz[fy]) swap(fx,fy);
	st[++top]=(opt){fx,fy,sz[fy]};
	fa[fx]=fy; sz[fy]+=sz[fx];
	return 1;
}

void doit(unomp<int,vector<int> >&mp){
	for (iv=mp.begin();iv!=mp.end();++iv){
		for (;top>clo;--top){
			fa[st[top].who]=st[top].who;
			sz[st[top].to]=st[top].orgsz;
		}
		for (auto o:iv->second)
			die[iv->first]|=!uni(e[o].u,e[o].v);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].w);
		vec[e[i].w].push_back(e[i]);
	}
	
	scanf("%d",&T);
	for (int i=1;i<=T;i++)
		for (scanf("%d",&y);y--;que[e[x].w][i].push_back(x)) scanf("%d",&x);
	
	for (int i=1;i<=n;i++) fa[i]=i, sz[i]=1;
	for (int i=1;i<=502333;i++) if (vec[i].size()){
		doit(que[i]);
		for (auto o:vec[i]) uni(o.u,o.v);
		clo=top;
	}
	for (int i=1;i<=T;i++) puts(die[i]? "NO": "YES");
}