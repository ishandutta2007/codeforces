#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int main(){
	int t;
	scanf("%d", &t);
	
	while(t--){
		int n, m, k;
		scanf("%d %d %d", &n, &m, &k);
		
		vector < unordered_set <int, custom_hash> > g(n);
		while(m--){
			int u, v;
			scanf("%d %d", &u, &v);
			u--, v--;
			
			g[u].insert(v);
			g[v].insert(u);
		}
		
		priority_queue < pair <int, int> > q;
		vector <bool> vis(n, false);
		
		for(int i = 0; i < n; i++)
			q.push(make_pair(-((int)g[i].size()), i));
			
		int res = -1;
		while(!q.empty()){
			auto[deg, u] = q.top();
			q.pop();
			
			if(vis[u])continue;
			vis[u] = true;
			
			deg = -deg;
			if(deg >= k){
				vis[u] = false;
				res = 1;
				break;
			}
			
			if(deg == k - 1){
				bool ok = true;
				
				vector <int> w;
				
				for(int v : g[u]){
					for(int z : w){
						if(!g[v].count(z)){
							ok = false;
							break;
						}
					}
					if(!ok)break;
					w.push_back(v);
				}
				
				if(ok){
					w.push_back(u);
					res = 2;
					
					printf("2\n");
					for(int i = 0; i < (int)w.size(); i++){
						if(i > 0)printf(" ");
						printf("%d", w[i] + 1);
					}
					printf("\n");
					
					break;
				}
			}
			
			for(int v : g[u]){
				g[v].erase(u);
				q.push(make_pair(-((int)g[v].size()), v));
			}
		}
		
		if(res == -1){
			printf("-1\n");
			continue;
		}else if(res == 1){
			vector <int> w;
			for(int i = 0; i < n; i++)
				if(!vis[i])w.push_back(i);
			
			printf("1 %d\n", (int)w.size());
			for(int i = 0; i < (int)w.size(); i++){
				if(i > 0)printf(" ");
				printf("%d", w[i] + 1);
			}
			printf("\n");
		}
	}
	return 0;
}