#include <bits/stdc++.h>
using namespace std;

int findr(vector <int>& d, int u){
	if(u == d[u])return u;
	else return d[u] = findr(d, d[u]);
}

int main(){
	int m, n;
	scanf("%d %d", &m, &n);
	
	vector <int> a(m), b(n);
	
	for(int i = 0; i < m; i++)scanf("%d", &a[i]);
	for(int i = 0; i < n; i++)scanf("%d", &b[i]);
	
	long long sum = 0;
	vector < pair <int, pair <int, int> > > e;
	
	for(int i = 0; i < m; i++){
		int s;
		scanf("%d", &s);
		
		for(int j = 0; j < s; j++){
			int c;
			scanf("%d", &c);
			c--;
			
			sum += a[i] + b[c];
			e.push_back({-a[i] - b[c], {i, c + m}});
		}
	}
	
	sort(e.begin(), e.end());
	
	vector <int> d(n + m);
	for(int i = 0; i < n + m; i++)d[i] = i;
	
	for(auto t : e){
		int u = findr(d, t.second.first), v = findr(d, t.second.second);
		if(u == v)continue;
		
		sum += t.first;
		d[u] = v;
	}
	printf("%lld\n", sum);
	
	return 0;
}