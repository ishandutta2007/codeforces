#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	string s;
	cin >> s;
	int n = s.size();
	vector<int> p(n+1);
	for (int i=0;i<n;++i) p[i+1] = p[i] + (s[i] == '1');
	// min n >= j > i >= 0 -> max[(j - p[j]) - (i - p[i]), p[i] + p[n] - p[j]] = min max(p[i] - p[j] + j - i, p[i]-p[j] + p[n])
	auto check = [&](int x) -> bool {
		int i1 = 0;
		for (int i=0;i<n;++i){
			while (i1 < n && (i1-i) - (p[i1] - p[i])<=x) i1++;
			// cout << i << " " << i1 << endl;
			if (p[n] - p[i1] + p[i] <= x) return true;
		}
		return false;
	};
	int l = 0, r = n;
	while (l + 1 != r){
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	if (check(l)) r = l;
	cout << r << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}