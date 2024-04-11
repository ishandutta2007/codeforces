#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

const int INF=100000000;

#define fr first
#define sc second
#define chmax(a,b) a=max(a,b)
#define chmin(a,b) a=min(a,b)

int n;
vector<int> G[100010];

int ret;
int dp[100010][2];
void dfs(int v,int p){
	dp[v][0]=-INF;
	dp[v][1]=1;
	int MAX[2][2]={{-INF,-INF},{-INF,-INF}};
	//int id[2][2]={-1,-1};
	int cnt=0;
	for(int u: G[v]){
		if(u==p)continue;
		dfs(u,v);
		chmax(dp[v][0],dp[u][1]+(int)G[v].size()-2);
		chmax(dp[v][1],dp[u][0]+1);
		for(int t=0;t<2;t++){
			if(MAX[t][1]<dp[u][t]){
				MAX[t][1]=dp[u][t];
				//id[t][1]=u;
				if(MAX[t][0]<MAX[t][1]){
					swap(MAX[t][0],MAX[t][1]);
					//swap(id[t][0],id[t][1]);
				}
			}
		}
		cnt++;
	}
	chmax(ret,dp[v][1]);
	if(cnt>=2){
		chmax(ret,MAX[0][0]+MAX[0][1]+1);
		chmax(ret,MAX[1][0]+MAX[1][1]+(int)G[v].size()-2);
	}
	dp[v][1]=max(dp[v][1],dp[v][0]);
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
	dfs(root,0);
	printf("%d\n",ret);
}