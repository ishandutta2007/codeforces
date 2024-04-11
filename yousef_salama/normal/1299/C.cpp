#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	vector < pair <double, int> > v;
	
	for(int i = n - 1; i >= 0; i--){
		pair <double, int> p = make_pair(a[i], 1);
		while(!v.empty() && v.back().first < p.first){
			p = make_pair(v.back().first * v.back().second / (v.back().second + p.second) + p.first * p.second / (v.back().second + p.second),
							v.back().second + p.second);
			v.pop_back();
		}
		v.push_back(p);
	}
	
	
	for(int i = (int)v.size() - 1; i >= 0; i--){
		for(int j = 0; j < v[i].second; j++){
			printf("%.9f\n", v[i].first);
		}
	}
	
	return 0;
}