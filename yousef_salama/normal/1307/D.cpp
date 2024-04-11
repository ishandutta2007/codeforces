#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int n, m, k, a[MAXN], xi, yi;
vector <int> g[MAXN];

int d[2][MAXN];
void bfs(int s, int ind){
	memset(d[ind], -1, sizeof d[ind]);
	queue <int> q;
	
	d[ind][s] = 0;
	q.push(s);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int v : g[u]){
			if(d[ind][v] == -1){
				d[ind][v] = d[ind][u] + 1;
				q.push(v);
			}
		}
	}
}

vector < pair <int, int> > v, w;
bool can(int L){
	w.clear();
	
	for(pair <int, int> a : v){
		if(w.empty()){
			w.push_back(a);
		}else{
			int j = lower_bound(w.begin(), w.end(), make_pair(L - 1 - a.second, 0)) - w.begin();
			
			if(j != (int)w.size()){
				if(w[j].second + a.first + 1 >= L){
					return true;
				}
			}
			
			while(!w.empty() && w.back().second <= a.second)
				w.pop_back();
			w.push_back(a);
		}
	}
	return false;
}

int main(){
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < k; i++){
		scanf("%d", &a[i]);
		a[i]--;
	}
	
	while(m--){
		scanf("%d %d", &xi, &yi);
		xi--, yi--;
		
		g[xi].push_back(yi);
		g[yi].push_back(xi);
	}
	
	bfs(0, 0);
	bfs(n - 1, 1);
	
	for(int i = 0; i < k; i++)
		v.push_back(make_pair(d[0][a[i]], d[1][a[i]]));
	sort(v.begin(), v.end());
	
	int L = 1, R = d[0][n - 1];
	while(L < R){
		int mid = (L + R + 1) / 2;
		if(can(mid))L = mid;
		else R = mid - 1;
	}
	printf("%d\n", L);

	return 0;
}