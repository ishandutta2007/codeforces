#include <bits/stdc++.h>
using namespace std;
const int N=100005,M=N*2;
struct Gragh{
	int cnt,y[M],nxt[M],fst[N],z[M];
	void clear(){
		cnt=0;
		memset(fst,0,sizeof fst);
	}
	void add(int a,int b,int c){
		y[++cnt]=b,nxt[cnt]=fst[a],fst[a]=cnt;z[cnt]=c;
	}
}g;
struct Edge{
	int x,y,z,id;
}e[N];
bool cmp(Edge a,Edge b){
	return a.z<b.z;
}
int ffa[N];
int n,m;
int getf(int x){
	return ffa[x]==x?x:ffa[x]=getf(ffa[x]);
}
int depth[N],fa[N][20],son[N],size[N],p[N],top[N],ap[N];
int tax[N*10],ans[N],f[N],Min[N][20];
vector <int> c[N];
void dfs(int x,int pre,int d){
	depth[x]=d,fa[x][0]=pre,size[x]=0,son[x]=-1;
	for (int i=1;i<20;i++){
		fa[x][i]=fa[fa[x][i-1]][i-1];
		int a=Min[x][i-1],b=Min[fa[x][i-1]][i-1];
		Min[x][i]=e[a].z>e[b].z?a:b;
	}
	for (int i=g.fst[x];i;i=g.nxt[i])
		if (g.y[i]!=pre){
			Min[g.y[i]][0]=g.z[i];
			dfs(g.y[i],x,d+1);
			size[x]+=size[g.y[i]];
			if (son[x]==-1||size[g.y[i]]>size[son[x]])
				son[x]=g.y[i];
		}
}
int cnp=0;
void Get_Top(int x,int Top){
    top[x]=Top;
    ap[p[x]=++cnp]=x;
    if (son[x]==-1)
        return;
    Get_Top(son[x],Top);
    for (int i=g.fst[x];i;i=g.nxt[i]){
        int y=g.y[i];
        if (y!=fa[x][0]&&y!=son[x])
            Get_Top(y,y);
    }
}
int LCA(int x,int y){
	if (depth[x]<depth[y])
		swap(x,y);
	for (int i=19;i>=0;i--)
		if (depth[x]-(1<<i)>=depth[y])
			x=fa[x][i];
	if (x==y)
		return x;
	for (int i=19;i>=0;i--)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int ask(int x,int d){
	int ans=0;
	for (int i=19;i>=0;i--)
		if (d>=(1<<i)){
			d-=1<<i;
			ans=e[ans].z>e[Min[x][i]].z?ans:Min[x][i];
			x=fa[x][i];
		}
	return ans;
}
void Tupdate(int x,int lca,int i){
	while (top[x]!=top[lca]){
		int f=top[x];
		c[p[f]].push_back(i);
		c[p[x]].push_back(-i);
		x=fa[f][0];
		if (e[Min[f][0]].z==e[i].z)
			ans[Min[f][0]]=1;
	}
	c[p[lca]].push_back(i);
	c[p[x]].push_back(-i);
}
int rans[N];
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
		scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].z),e[i].id=i;
	sort(e+1,e+m+1,cmp);
	for (int i=1;i<=n;i++)
		ffa[i]=i;
	g.clear();
	for (int i=1;i<=m;i++){
		int x=e[i].x,y=e[i].y,z=e[i].z;
		int px=getf(x),py=getf(y);
		if (px==py)
			continue;
		f[i]=1;
		ans[i]=2;
		ffa[px]=py;
		g.add(x,y,i);
		g.add(y,x,i);
	}
	dfs(1,0,0);
	Get_Top(1,0);
	for (int i=1;i<=m;i++){
		if (f[i])
			continue;
		int x=e[i].x,y=e[i].y,lca=LCA(x,y);
		int aa=ask(x,depth[x]-depth[lca]);
		int bb=ask(y,depth[y]-depth[lca]);
		ans[i]=(bool)(max(e[aa].z,e[bb].z)==e[i].z);
		Tupdate(x,lca,i);
		Tupdate(y,lca,i);
	}
	for (int i=1;i<=n;i++){
		for (int j=0;j<c[i].size();j++)
			if (c[i][j]<0)
				tax[e[-c[i][j]].z]--;
			else
				tax[e[c[i][j]].z]++;
		if (tax[e[Min[ap[i+1]][0]].z]>0)
			ans[Min[ap[i+1]][0]]=1;
	}
	for (int i=1;i<=m;i++)
		rans[e[i].id]=ans[i];
	for (int i=1;i<=m;i++){
		if (rans[i]==0)
			puts("none");
		if (rans[i]==1)
			puts("at least one");
		if (rans[i]==2)
			puts("any");
	}
	return 0;
}