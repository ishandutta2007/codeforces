#include <bits/stdc++.h>
using namespace std;
vector <int> g[100001];
int far[100001];
bool done[100001];
int ans[100001];
int n;
int check_val;
void dfs(int u){
	done[u]=1;
	far[u]=0;
	for(int i=0; i<g[u].size(); i++){
		if(done[g[u][i]]){
			swap(g[u][i], g[u].back());
			g[u].pop_back();
			i--;
		}
		else{
			dfs(g[u][i]);
			far[u]=max(far[u], far[g[u][i]]+1);
		}
	}
}
int check(int u, bool is_root){
	//return 1 for good, 0 for bad, -1 for good but the child need to be removed first
	int after_weight=g[u].size()+(!is_root);
	for(int &v: g[u]){
		int res=check(v, 0);
		if(res==0) return 0;
		if(res==-1) after_weight--;
	}
	if(is_root){
		if(after_weight%check_val==0) return 1;
		else return 0;
	}
	else{
		if(after_weight%check_val==0){//need to do before parent
			return -1;
		}
		else if(after_weight%check_val==1){//need to do after parent
			return 1;
		}
		else return 0;//can't be done at all
	}
}

const long long base=998244353;
long long power(long long a, long long x){
	if(x==0) return 1;
	long long t=power(a, x/2);
	(t*=t)%=base;
	if(x%2) (t*=a)%=base;
	return t;
}
void solve(){
	cin>>n;
	for(int i=1; i<=n; i++) g[i].clear();
	for(int i=1; i<=n; i++) done[i]=0;
	for(int i=1, u, v; i<n; i++){
		cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	if(n==2){
		cout<<"2 0\n";
		return;
	}
	int root=1;
	while(g[root].size()==1) root++;
	dfs(root);
	check_val=n+1;
	for(int i=1; i<=n; i++) if((g[i].size()>=1)&&(far[i]==1)){
		check_val=min(check_val, (int)g[i].size());
	}
	for(int i=1; i<=n; i++) ans[i]=0;
	ans[1]=power(2, n-1);
	vector <int> good;
	vector <int> to_check;
	check_val++;
	for(int i=check_val; i>=2; i--) if(check_val%i<=1) to_check.push_back(i);
	for(int i: to_check){
		check_val=i;
		for(int x: good) if(x%check_val==0) goto line0;
		if(check(root, 1)){
			ans[check_val]=1;
			good.push_back(check_val);
			ans[1]--;
		}
		line0:;
		check_val--;
	}
	(ans[1]+=base)%=base;
	for(int i=1; i<=n; i++) cout<<ans[i]<<" \n"[i==n];
	//for the case k=1
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
}