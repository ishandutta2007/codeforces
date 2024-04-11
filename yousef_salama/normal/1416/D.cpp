#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m, q;
	scanf("%d %d %d", &n, &m, &q);
	
	vector <int> p(n);
	for(int i = 0; i < n; i++)
		scanf("%d", &p[i]);
		
	vector <bool> vis(m, false);
	vector < pair <int, int> > e(m);
	 
	for(int i = 0; i < m; i++){
		scanf("%d %d", &e[i].first, &e[i].second);
		e[i].first--, e[i].second--;
	}
	
	vector < pair <int, int> > evs(q);
	for(int i = 0; i < q; i++){
		scanf("%d %d", &evs[i].first, &evs[i].second);
		evs[i].second--;
		
		if(evs[i].first == 2){
			vis[evs[i].second] = true;
		}
	}
	
	vector <int> u(n);
	vector < set <int> > s(n);
	vector < vector <int> > g(n);
	
	for(int i = 0; i < n; i++){
		u[i] = i;
		g[i].push_back(i);
	}
	
	for(int i = 0; i < m; i++)if(!vis[i]){
		int ar = u[e[i].first], br = u[e[i].second];
		
		if(ar == br){
			continue;
		}else{
			if(g[ar].size() > g[br].size())swap(ar, br);
			
			for(auto x : g[ar]){
				u[x] = br;
				g[br].push_back(x);
			}
			
			g[ar].clear();
		}
	}
	
	vector < vector < array <int, 3> > > trans(q);
	
	for(int i = q - 1; i >= 0; i--)if(evs[i].first == 2){
		pair <int, int> c = e[evs[i].second];
		int ar = u[c.first], br = u[c.second];
		
		if(ar == br){
			continue;
		}else{
			if(g[ar].size() > g[br].size())swap(ar, br);
			
			for(auto x : g[ar]){
				trans[i].push_back({ar, br, x});
				
				u[x] = br;
				g[br].push_back(x);
			}
			
			g[ar].clear();
		}
	}
	
	for(int i = 0; i < n; i++){
		for(auto x : g[i]){
			s[i].insert(p[x]);
		}
	}
	
	for(int i = 0; i < q; i++){
		if(evs[i].first == 1){
			int c = u[evs[i].second];
			
			if(s[c].empty())printf("0\n");
			else{
				printf("%d\n", *prev(s[c].end()));
				s[c].erase(prev(s[c].end()));
			}
		}else{
			for(auto t : trans[i]){
				u[t[2]] = t[0];
				
				if(s[t[1]].count(p[t[2]])){
					s[t[1]].erase(p[t[2]]);
					s[t[0]].insert(p[t[2]]);
				}
			}
		}
	}
	
	return 0;
}