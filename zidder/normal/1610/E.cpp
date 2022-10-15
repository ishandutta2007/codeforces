#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n;
	cin >> n;
	map<long long, int> cnt;
	for (int i=0;i<n;++i){
		int x;
		scanf("%d", &x);
		cnt[x]++;
	}
	int ans = 2;
	for (auto &p: cnt){
		int ans1 = p.second;
		auto it = cnt.lower_bound(p.first + 1);
		while(it != cnt.end()){
			ans1++;
			it = cnt.lower_bound(2 * (it->first) - p.first);
		}
		ans = max(ans, ans1);
	}
	cout << n - ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}