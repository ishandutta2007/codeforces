#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	
	vector < pair <int, int> > v(n), w(m);
	
	for(int i = 0; i < n; i++)scanf("%d %d", &v[i].first, &v[i].second);
	for(int i = 0; i < m; i++)scanf("%d %d", &w[i].first, &w[i].second);
	
	vector <int> r(1000002, 0);
	
	for(int i = 0; i < n; i++)
	for(int j = 0; j < m; j++)if(v[i].first <= w[j].first && v[i].second <= w[j].second){
		r[w[j].first - v[i].first] = max(r[w[j].first - v[i].first], w[j].second - v[i].second + 1);
	}
	
	int res = 1 << 30, mx = 0;
	for(int i = 1000001; i >= 0; i--){
		mx = max(mx, r[i]);
		res = min(res, i + mx);
	}
	printf("%d\n", res);
	
	return 0;
}