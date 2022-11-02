#include <bits/stdc++.h>
#define y1 _fy89uasd
using namespace std;
const int N=200005,S=N*30;
map <string,int> Map;
vector <int> son[N],id[N],dfn[N];
int n,m=0,q,v[N],rt;
int Time=-1,in[N],out[N];
int depth[N],p[N],Prev[N],ap[N];
int tax[N];
void dfs(int x,int d){
	depth[x]=d;
	in[x]=++Time;
	if (depth[x]>=0){
		id[depth[x]].push_back(x);
		dfn[depth[x]].push_back(in[x]);
	}
	for (int i=0;i<son[x].size();i++)
		dfs(son[x][i],d+1);
	out[x]=Time;
}
int root[N],sum[S],ls[S],rs[S],tot=0;
void build(int &rt,int L,int R){
	sum[rt=++tot]=0;
	if (L==R)
		return;
	int mid=(L+R)>>1;
	build(ls[rt],L,mid);
	build(rs[rt],mid+1,R);
}
void update(int prt,int &rt,int L,int R,int x,int d){
	if (!rt||rt==prt)
		sum[rt=++tot]=sum[prt];
	sum[rt]+=d;
	if (L==R)
		return;
	if (!ls[rt])
		ls[rt]=ls[prt];
	if (!rs[rt])
		rs[rt]=rs[prt];
	int mid=(L+R)>>1;
	if (x<=mid)
		update(ls[prt],ls[rt],L,mid,x,d);
	else
		update(rs[prt],rs[rt],mid+1,R,x,d);
}
int query(int rt,int L,int R,int xL,int xR){
	if (!rt||R<xL||L>xR)
		return 0;
	if (xL<=L&&R<=xR)
		return sum[rt];
	int mid=(L+R)>>1;
	return query(ls[rt],L,mid,xL,xR)+query(rs[rt],mid+1,R,xL,xR);
}
int Query(int x1,int x2,int y1,int y2){
	return query(root[x2],1,n,y1,y2)-query(root[x1-1],1,n,y1,y2);
}
void Get_AP(){
	int tot=0;
	memset(tax,0,sizeof tax);
	for (int i=0;i<n;i++)
		for (int j=0;j<id[i].size();j++){
			ap[++tot]=id[i][j];
			p[id[i][j]]=tot;
			Prev[tot]=tax[v[ap[tot]]];
			tax[v[ap[tot]]]=tot;
		}
}
int main(){
	scanf("%d",&n);
	Map.clear();
	for (int i=1;i<=n;i++)
		son[i].clear();
	for (int i=1;i<=n;i++){
		string s;
		int r;
		cin >> s >> r;
		if (!Map[s])
			Map[s]=++m;
		v[i]=Map[s];
		son[r].push_back(i);
	}
	for (int i=1;i<=n;i++)
		id[i].clear(),dfn[i].clear();
	rt=0;
	dfs(rt,-1);
	Get_AP();
	build(root[0],1,n);
	for (int i=0;i<n;i++)
		for (int j=0;j<id[i].size();j++){
			int k=p[id[i][j]];
			update(root[k-1],root[k],1,n,Prev[p[id[i][j]]],-1);
			update(root[k-1],root[k],1,n,p[id[i][j]],1);
		}
	scanf("%d",&q);
	for (int i=0;i<n;i++)
		dfn[i].push_back(n+1);
	while (q--){
		int x,y;
		scanf("%d%d",&x,&y);
		if (id[depth[x]+y].size()<1){
			puts("0");
			continue;
		}
		int i=depth[x]+y;
		int L=lower_bound(dfn[i].begin(),dfn[i].end(),in[x])-dfn[i].begin();
		int R=upper_bound(dfn[i].begin(),dfn[i].end(),out[x])-1-dfn[i].begin();
		if (L>R){
			puts("0");
			continue;
		}
		int l=id[i][L],r=id[i][R];
		printf("%d\n",-Query(p[l],p[r],1,p[l]-1));
	}
	return 0;
}