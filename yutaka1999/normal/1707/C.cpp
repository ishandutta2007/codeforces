#include <bits/stdc++.h>
#define SIZE 200005
#define BT 20
using namespace std;

struct UF{
	int par[SIZE],rank[SIZE];
	void init(int n){
		for(int i=0;i<n;i++){
			par[i]=i;
			rank[i]=0;
		}
	}
	int find(int x){
		return par[x]==x?x:par[x]=find(par[x]);
	}
	void unite(int x,int y){
		x=find(x),y=find(y);
		if(x==y) return;
		if(rank[x]==rank[y]){
			par[x]=y;
			rank[y]++;
		} else{
			if(rank[x]>rank[y]) swap(x,y);
			par[x]=y;
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
}uf;
int A[SIZE],B[SIZE];
vector <int> vec[SIZE];
int par[SIZE][BT],dep[SIZE];
int dp[SIZE];
bool use[SIZE];
int n,m;
void dfs(int v=0,int p=-1,int d=0){
	dep[v]=d;
	par[v][0]=p;
	for(int i=0;i<vec[v].size();i++){
		int to=vec[v][i];
		if(to!=p) dfs(to,v,d+1);
	}
}
void dfs2(int v=0,int p=-1){
	for(int i=0;i<vec[v].size();i++){
		int to=vec[v][i];
		if(to!=p){
			dp[to]+=dp[v];
			dfs2(to,v);
		}
	}
}
void build(){
	for(int i=0;i+1<BT;i++){
		for(int j=0;j<n;j++){
			if(par[j][i]==-1) par[j][i+1]=-1;
			else par[j][i+1]=par[par[j][i]][i];
		}
	}
}
int LCA(int a,int b){
	if(dep[a]>dep[b]) swap(a,b);
	for(int i=BT-1;i>=0;i--){
		if(par[b][i]!=-1&&dep[par[b][i]]>=dep[a]){
			b=par[b][i];
		}
	}
	if(a==b) return a;
	for(int i=BT-1;i>=0;i--){
		if(par[a][i]!=par[b][i]){
			a=par[a][i],b=par[b][i];
		}
	}
	return par[a][0];
}
int main(){
	scanf("%d%d",&n,&m);
	uf.init(n+2);
	for(int i=0;i<m;i++){
		scanf("%d%d",&A[i],&B[i]);
		A[i]--,B[i]--;
		use[i]=!uf.same(A[i],B[i]);
		if(use[i]){
			uf.unite(A[i],B[i]);
			vec[A[i]].push_back(B[i]);
			vec[B[i]].push_back(A[i]);
		}
	}
	dfs();
	build();
	for(int i=0;i<m;i++){
		if(!use[i]){
			int p=LCA(A[i],B[i]);
			if(dep[A[i]]>dep[B[i]]) swap(A[i],B[i]);
			if(p!=A[i]){
				dp[0]++;
				dp[A[i]]--,dp[B[i]]--;
			} else{
				int b=B[i];
				for(int j=BT-1;j>=0;j--){
					if(par[b][j]!=-1&&dep[par[b][j]]>dep[A[i]]){
						b=par[b][j];
					}
				}
				dp[b]++;
				dp[B[i]]--;
			}
		}
	}
	dfs2();
	for(int i=0;i<n;i++) printf("%d",dp[i]==0);
	puts("");
}