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
	map<int, int> mp;
	int up = 0, d = 0;
	for (int i=0;i<n;++i) {
		int a;
		scanf("%d", &a);
		if (mp[a] == 2) continue;
		mp[a]++;
		up++;
	}

	int ans = 0;
	for (auto &p: mp) {
		// p.first;
		up -= p.second;
		ans = max(ans, (up / 2 + d / 2 + 1));
		d += p.second;
	}
	cout << ans << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}