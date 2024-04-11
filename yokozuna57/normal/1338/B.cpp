#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int n;
vector<int> G[100010];

int cnt[100010];
bool used[2];
void dfs(int v,int p,int d){
	if(G[v].size()==1){
		cnt[p]++;
		used[d&1]=true;
		return;
	}
	for(int u: G[v]){
		if(u==p)continue;
		dfs(u,v,d+1);
	}
}

int main(){
	static int a[100010],b[100010];
	scanf("%d",&n);
	for(int i=0;i<n-1;i++){
		scanf("%d%d",&a[i],&b[i]);
		G[a[i]].push_back(b[i]);
		G[b[i]].push_back(a[i]);
	}
	int root=-1;
	for(int i=1;i<=n;i++){
		if(G[i].size()!=1){
			root=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		cnt[i]=0;
	}
	used[0]=used[1]=false;
	dfs(root,0,0);
	
	int ret[2];
	if(used[0]&&used[1])ret[0]=3;
	else ret[0]=1;
	ret[1]=n-1;
	for(int i=1;i<=n;i++){
		ret[1]-=max(cnt[i]-1,0);
	}
	printf("%d %d\n",ret[0],ret[1]);
}