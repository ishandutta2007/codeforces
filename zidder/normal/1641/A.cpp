#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	map<pair<int, int>, int> b;
	for (int i=0;i<n;++i){
		pair<int, int> p;
		p.first = a[i];
		p.second = 0;
		while (p.first % x == 0){
			p.first /= x;
			p.second++;
		}
		b[p]++;
	}
	pair<pair<int, int>, int> prev{{-1, -1}, 0};
	int ans = 0;
	for (auto &pp: b){
		auto p = pp.first;
		if (p.first == prev.first.first){
			if (p.second == prev.first.second + 1){
				prev.second -= pp.second;
				if (prev.second > 0){
					ans += prev.second;
					prev.second = 0;
				} else {
					prev.second = -prev.second;
				}
				prev.first = p;
			} else {
				ans += prev.second;
				prev.first = p;
				prev.second = pp.second;
			}
		} else {
			ans += prev.second;
			prev.first = p;
			prev.second = pp.second;
		}
	}
	ans += prev.second;
	printf("%d\n", ans);
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}