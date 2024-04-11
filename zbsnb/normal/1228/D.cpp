#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
map<pii,int> mp;
const int N = 1e5+9;
int n,m;
vector<int> G[N];
int tag[N];
int siz[4];
int num[4];
bool dfs(int u){
	num[1] = num[2] = num[3] = 0;
	for(int i = 0 ; i<G[u].size();++i){
		int v = G[u][i];
		if(tag[v] == tag[u]) return 0;
		++num[tag[v]];
	}
	if(tag[u] == 1){
		if(num[2] == siz[2] && num[3]==siz[3]) return 1;
		else return 0;
	}
	if(tag[u] == 2){
		if(num[1] == siz[1] && num[3]==siz[3]) return 1;
		else return 0;
	}
	if(tag[u] == 3){
		if(num[2] == siz[2] && num[1]==siz[1]) return 1;
		else return 0;
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i = 1;i<=m;++i){
		int u,v; scanf("%d %d",&u,&v);
		if(u>v) swap(u,v);
		mp[make_pair(u,v)] = 1;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	tag[1] = 1; siz[1]++;
	if(G[1].size()==0){
		printf("-1");
		return 0;
	}
	int u = G[1][0];
	tag[u] = 2;
	siz[2]++;
	for(int j = 0;j<G[u].size();++j){
		int v = G[u][j];
		if(v == 1) continue;
		if(mp[make_pair(1,v)]==1){
			tag[v] = 3;
			siz[3]++;
		}
		else{
			tag[v] = 1;
			siz[1]++;
		}
	}
	for(int i =1;i<=n;++i){
		if(!tag[i]){
			tag[i] = 2;
			siz[2]++;
		}
	}
	if(siz[1]==0 || siz[2]==0 || siz[3]==0){
		printf("-1");
		return 0;
	}
	for(int i =1 ;i<=n;++i){
		if(!dfs(i)){
			printf("-1");
			return 0;
		}
	}
	for(int i=1;i<=n;++i) printf("%d ",tag[i]); 
}