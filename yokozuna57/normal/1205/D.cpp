#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
const ll MOD = 998244353;

#define fr first
#define sc second

const int UnionFindTree_MAX_V = 1010;	//_
struct UnionFindTree{
	int par[UnionFindTree_MAX_V+10],r[UnionFindTree_MAX_V+10],cnt[UnionFindTree_MAX_V+10];
	void init(int n = UnionFindTree_MAX_V){
		for(int i = 0 ; i < n+10 ; i ++){
			par[i] = i;
			r[i] = 0;
			cnt[i] = 1;
		}
	}
	int find(int x){
		if(par[x] == x)return x;
		return par[x] = find(par[x]);
	}
	bool same(int x,int y){
		return find(x) == find(y);
	}
	void unit(int x,int y){
		if(same(x,y))return;
		x = find(x);
		y = find(y);
		if(r[x] < r[y]){
			par[x] = y;
			cnt[y] += cnt[x];
		}
		else {
			par[y] = x;
			cnt[x] += cnt[y];
			if(r[x] == r[y]){
				r[x] ++;
			}
		}
	}
}uf;

vector<int> G[1002];
int ans[1002][1002];
int dfs(int v,int p,int t){
	int ret = 1;
	for(int i = 0 ; i < G[v].size() ; i ++){
		int w = G[v][i];
		if(w == p)continue;
		ans[v][w] = min(ret*t,1000000);
		ans[w][v] = min(ret*t,1000000);
		ret += dfs(w,v,t);
	}
	return ret;
}

int main(){
	int n;
	int u[1002],v[1002];
	scanf("%d",&n);
	for(int i = 0 ; i < n-1 ; i ++){
		scanf("%d%d",&u[i],&v[i]);
	}
	int des = (2*n*n)/9;
	
	if(n == 1){
		return 0;
	}
	if(n == 2){
		cout << "1 2 1" << endl;
		return 0;
	}
	
	for(int i = 0 ; i < n-1 ; i ++){
		G[u[i]].push_back(v[i]);
		G[v[i]].push_back(u[i]);
	}
	
	int root = 1;
	vector<int> A,B;
	while(1){
		uf.init();
		for(int i = 0 ; i < n-1 ; i ++){
			if(u[i] != root && v[i] != root){
				uf.unit(u[i],v[i]);
			}
		}
		vector<P> vec;
		for(int i = 0 ; i < n-1 ; i ++){
			if(u[i] != root && v[i] != root)continue;
			int w;
			if(u[i] == root)w = v[i];
			else w = u[i];
			vec.push_back(P(uf.cnt[uf.find(w)],w));
		}
		sort(vec.begin(),vec.end());
		reverse(vec.begin(),vec.end());
		int cnt_a = 0,cnt_b = 0;
		for(int i = 0 ; i < vec.size() ; i ++){
			if(cnt_a <= cnt_b){
				A.push_back(vec[i].sc);
				cnt_a += vec[i].fr;
			}
			else {
				B.push_back(vec[i].sc);
				cnt_b += vec[i].fr;
			}
		}
		//cout << root << endl;
		//cout << cnt_a << " " << cnt_b << " " << des << endl;
		if((cnt_a+1)*(cnt_b+1)-1 >= des)break;
		A.clear();
		B.clear();
		root ++;
	}
	
	int cnt = 1;
	for(int i = 0 ; i < A.size() ; i ++){
		int w = A[i];
		ans[root][w] = cnt;
		ans[w][root] = cnt;
		cnt += dfs(w,root,1);
	}
	int M = cnt;
	cnt = 1;
	for(int i = 0 ; i < B.size() ; i ++){
		int w = B[i];
		ans[root][w] = min(cnt*M,1000000);
		ans[w][root] = min(cnt*M,1000000);
		cnt += dfs(w,root,M);
	}
	
	for(int i = 0 ; i < n-1 ; i ++){
		printf("%d %d %d\n",u[i],v[i],ans[u[i]][v[i]]);
	}
}