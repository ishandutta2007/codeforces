#include<bits/stdc++.h>
using namespace std;

unordered_set<int> e[100010];

int deg[100010];
bool vis[100010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--){
		int n, m, k;
		cin >> n >> m >> k;
		for(int i=1;i<=n;i++)
			e[i].clear(), deg[i] = 0, vis[i] = 0;
		for(int i=0,u,v;i<m;i++)
			cin >> u >> v, e[u].insert(v), e[v].insert(u), deg[u] ++, deg[v] ++;
		priority_queue<pair<int,int>, vector<pair<int,int> > , greater<pair<int,int> > > pq;
		for(int i=1;i<=n;i++)
			pq.emplace(deg[i],  i);
		int ans = 0;
		int remain = n;
		auto remove = [&](int x) -> void {
			vis[x] = true;
			remain --;
			for(auto it:e[x])
				if(!vis[it])
					pq.emplace(--deg[it], it);
		};
		vector<int> check;
		while(!pq.empty()){
			int x = pq.top().second;pq.pop();
			if(vis[x])	continue;
			if(deg[x] < k - 1){
				remove(x);
			}
			else if(deg[x] == k - 1){
				if(remain < k)
					break;
				check = vector<int>(1, x);
				for(int it:e[x])
					if(!vis[it])
						check.emplace_back(it);
				bool clique = true;
				for(int i=0;i<check.size();i++)
					for(int j=i+1;j<check.size()&&clique;j++)
						clique &= e[check[i]].count(check[j]);
				if(clique){
					ans = 2;
					break;
				}
				remove(x);
			}
			else{
				ans = 1;
				break;
			}
		}
		if(ans == 0)
			cout << -1 << '\n';
		else if(ans == 1){
			int cnt = 0;
			for(int i=1;i<=n;i++)
				if(!vis[i])
					cnt ++;
			cout << 1 << ' ' << cnt << '\n';
			for(int i=1;i<=n;i++)
				if(!vis[i])
					cout << i << ' ';
				cout << '\n';
		}
		else{
			cout << 2 << '\n';
			for(int it:check)
				cout << it << ' ';
			cout << '\n';
		}
	}
}