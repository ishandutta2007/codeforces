#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> P1;
#define mp1(a,b,c) P1(a,P(b,c))
#define fr first
#define sc second

int n;
int u[500010],v[500010];
vector<int> G[500010];
vector<int> D[500010];
int dp[500010];

int dfs(int v,int p){
	int ret = 0;
	for(int i = 0 ; i < G[v].size() ; i ++){
		if(G[v][i] == p)continue;
		ret = max( ret , dfs(G[v][i],v) );
	}
	ret ++;
	dp[v] = ret;
	if(p != 0)D[p].push_back(ret);
	return ret;
}
void dfs2(int v,int p,int a){
	if(p != 0)D[v].push_back(a);
	sort(D[v].begin(),D[v].end());
	reverse(D[v].begin(),D[v].end());
	for(int i = 0 ; i < G[v].size() ; i ++){
		if(G[v][i] == p)continue;
		if(dp[G[v][i]] == D[v][0])dfs2(G[v][i],v,(D[v].size()==1)?1:(D[v][1]+1));
		else dfs2(G[v][i],v,D[v][0]+1);
	}
}

int main(){
	scanf("%d",&n);
	for(int i = 0 ; i < n-1 ; i ++){
		scanf("%d%d",&u[i],&v[i]);
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	dfs(1,0);
	dfs2(1,0,0);
	
	/*for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < D[i].size() ; j ++){
			cout << D[i][j] << " ";
		}
		cout << endl;
	}*/
	
	static int ret[1000010] = {};
	ret[n] = 1;
	ret[n-1] = 1;
	int R = 0;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 0 ; j < D[i].size() ; j ++){
			R = max( R , D[i][j] );
		}
	}
	ret[R] = 2;
	if(R >= 2)ret[R-1] = 2;
	for(int i = 1 ; i <= n ; i ++){
		for(int j = 1 ; j < D[i].size() ; j ++){
			ret[2*D[i][j]] = max( ret[2*D[i][j]] , j+1 );
			ret[2*D[i][j]-1] = max( ret[2*D[i][j]-1] , j+1 );
		}
		for(int j = 1 ; j < D[i].size() ; j ++){
			if(D[i][j] < D[i][j-1]){
				ret[2*D[i][j]+1] = max( ret[2*D[i][j]+1] , j+1 );
			}
		}
	}
	static vector<int> E[500010];
	for(int i = 1 ; i <= n ; i ++){
		reverse(D[i].begin(),D[i].end());
		for(int j = 0 ; j < D[i].size() ; j ++){
			E[i].push_back(0);
		}
	}
	for(int i = 0 ; i < n-1 ; i ++){
		vector<int> vec;
		if(D[u[i]].size() > D[v[i]].size())swap(u[i],v[i]);
		for(int j = 0 ; j < D[u[i]].size() ; j ++){
			int k = D[v[i]].end()-lower_bound(D[v[i]].begin(),D[v[i]].end(),D[u[i]][j]);
			ret[2*D[u[i]][j]] = max( ret[2*D[u[i]][j]] , (int)D[u[i]].size()-j+k-2 );
			int l = D[v[i]].end()-upper_bound(D[v[i]].begin(),D[v[i]].end(),D[u[i]][j]);
			k = l+1;
			if(0 <= (int)D[v[i]].size()-k)E[v[i]][D[v[i]].size()-k] = max( E[v[i]][D[v[i]].size()-k] , (int)D[u[i]].size()-j );
		}
		/*for(int j = 0 ; j < D[u[i]].size() ; j ++){
			vec.push_back(D[u[i]][j]);
		}
		for(int j = 0 ; j < D[v[i]].size() ; j ++){
			vec.push_back(D[v[i]][j]);
		}
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		for(int j = 2 ; j < vec.size() ; j ++){
			ret[2*vec[j]] = max( ret[2*vec[j]] , j-1 );
		}*/
	}
	for(int i = 1 ; i <= n ; i ++){
		for(int j = (int)D[i].size()-1 ; j >= 0 ; j --){
			ret[2*D[i][j]] = max( ret[2*D[i][j]] , E[i][j]+(int)D[i].size()-j-2 );
			if(j > 0)E[i][j-1] = max( E[i][j-1] , E[i][j] );
		}
	}
	for(int i = n ; i >= 1 ; i --){
		ret[i] = max( ret[i] , ret[i+2] );
	}
	ret[1] = 0;
	for(int i = 1 ; i <= n ; i ++){
		ret[1] = max( ret[1] , (int)G[i].size()+1 );
	}
	for(int i = 1 ; i <= n ; i ++){
		printf("%d%c",ret[i],(i==n)?'\n':' ');
	}
}