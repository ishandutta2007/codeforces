#include <bits/stdc++.h>
using namespace std;

struct result{
	long long init, free, d;
	result(long long init, long long free, long long d): init(init), free(free), d(d){}
	result(){}
};

vector < vector <int> > g;
vector <int> a;

result dfs(int u){
	if(g[u].size() == 0){
		return result(a[u], 0, 1);
	}
	
	vector <result> vec;
	long long mx = 0;
	
	for(int v : g[u]){
		result c = dfs(v);
		
		vec.push_back(c);
		mx = max(mx, c.init);
	}
	
	long long free = 0, d = 0;
	for(result c : vec){
		free += c.free;
		free += c.d * (mx - c.init);
		d += c.d;
	}
	
	if(free >= a[u]){
		free -= a[u];
	}else{
		a[u] -= free;
		mx += (a[u] + d - 1) / d;
		free = (a[u] + d - 1) / d * d - a[u];
	}
	return result(mx, free, d);
}

int main(){
	int n;
	scanf("%d", &n);
	
	g.resize(n);
	a.resize(n);
	
	vector <int> p(n);
	for(int i = 1; i < n; i++){
		scanf("%d", &p[i]);
		p[i]--;
		
		g[p[i]].push_back(i);
	}
	
	for(int i = 0; i < n; i++)scanf("%d", &a[i]);
	
	result r = dfs(0);
	printf("%lld\n", r.init);
	
	return 0;
}