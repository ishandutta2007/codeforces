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
	map<int, int> cnt;
	for (int i=0;i<n;++i) {
		int x;
		cin >> x;
		cnt[abs(x)]++;
	}

	int ans = 0;
	for (auto &p: cnt){
		int o = 2;
		if (p.first == 0) o = 1;
		ans += min(p.second, o);
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