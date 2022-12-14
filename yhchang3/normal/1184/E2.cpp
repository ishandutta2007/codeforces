#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5;
int pa[MN+1],de[MN+1];
void Init(){
   for(int i=1;i<=MN;i++)
      de[pa[i]=i]=1;
}
int Find(int x){
   return x==pa[x]?x:pa[x]=Find(pa[x]);
}
void Union(int x,int y){
   x=Find(x);y=Find(y);
   if(x!=y){
      if(de[x]<de[y])    swap(x,y);
      pa[y]=x;
      if(de[x]==de[y])    de[x]++;
   }
}

int ans[1000001];
struct E{
	int u,v,w,idx;
	bool operator<(const E& rhs)const{
		return w<rhs.w;
	}
}e[1000001];
vector<pair<int,int> > edge[100001];
const int MAXLOG = 18,MAXN = 1e5;
int parent[MAXLOG+1][MAXN+1],depth[MAXN+1],d[MAXLOG+1][MAXN+1];//depth[root] init as 0
void dfs(int index,int father,int len){
   parent[0][index]=father;
   d[0][index]=len;
   for(int i=0;i+1<=MAXLOG;i++){
      parent[i+1][index]=parent[i][parent[i][index]];
      d[i+1][index]=max(d[i][index],d[i][parent[i][index]]);
   }
   for(int i=0;i<edge[index].size();i++){
      int next=edge[index][i].first;
      if(next==father)  continue;
      depth[next]=depth[index]+1;
      dfs(next,index,edge[index][i].second);
   }
}
int LCA(int a,int b){
	int res=0;
   if(depth[a]>depth[b])   swap(a,b);
   int k=0;
   for(int i=depth[b]-depth[a];i;i/=2){
      if(i%2){
      	res=max(res,d[k][b]);
      	b=parent[k][b];
      }
      k++;
   }
   if(a==b) return res;
   for(int i=MAXLOG;i>=0;i--)
      if(parent[i][a]!=parent[i][b]){
      	 res=max(res,d[i][a]);
         a=parent[i][a];
         res=max(res,d[i][b]);
         b=parent[i][b];
      }
      return max(max(res,d[0][a]),d[0][b]);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	Init();
	for(int i=1;i<=m;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
		e[i].idx=i;
	}
	sort(e+1,e+1+m);
	for(int i=1;i<=m;i++)
		if(Find(e[i].u)!=Find(e[i].v)){
			Union(e[i].u,e[i].v);
			ans[e[i].idx]=-1;
			edge[e[i].u].emplace_back(make_pair(e[i].v,e[i].w));
			edge[e[i].v].emplace_back(make_pair(e[i].u,e[i].w));
		}
	dfs(1,0,0);
	for(int i=1;i<=m;i++){
		if(ans[e[i].idx]!=-1){
			ans[e[i].idx]=LCA(e[i].u,e[i].v);
		}
	}
	for(int i=1;i<=m;i++)
		if(ans[i]!=-1)
			cout<<ans[i]<<'\n';
}