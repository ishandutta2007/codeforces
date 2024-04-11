#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int &i: v) scanf("%d", &i);
	map<int, int> mp;
	for (int i: v) mp[i]++;
	map<int, int> counts;
	for (auto &p: mp) counts[p.second]++;
	int ans = mp.size();
	int ck = 0;
	for (int mx=0;mx<n;++mx){
		int c = mp[mx];
		mp.erase(mx);
		if (c) {
			counts[c]--;
			if (counts[c] == 0) counts.erase(c);
		} else {
			ck++;
		}
		if (ck > k) break;
		int ans1 = 0;
		for (auto &p: counts) ans1 += p.second;
		int k1 = k;
		for (auto &p: counts) {
			if (k1 >= p.first * p.second) {
				k1 -= p.first * p.second;
				ans1 -= p.second;
			} else {
				ans1 -= (k1 / p.first);
				break;
			}
		}
		ans = min(ans, ans1);
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