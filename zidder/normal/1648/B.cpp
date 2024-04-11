#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <random>
#include <set>

using namespace std;

void solve(int test_ind){
	int n, c;
	cin >> n >> c;
	vector<int> a(n);
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	if (a[0] != 1) {
		cout << "No" << endl;
		return;
	}

	auto find_ind = [&](int x) -> int {
		return lower_bound(a.begin(), a.end(), x) - a.begin();
	};

	auto inside = [&](int x) -> bool {
		if (a[find_ind(x)] != x) return false;
		return true;
	};

	vector<int> divs;
	for (int i=1;i<a.size();++i){
		bool ok = true;
		for (int j:divs){
			if (a[i] % j == 0) {
				ok = false;
				break;
			}
		}
		if (ok){
			divs.push_back(a[i]);
		}
		if (a[i]*1ll*a[i]>a.back()) break;
	}

	vector<int> divs2;
	for (int i=0;i<divs.size();++i){
		if (divs2.size() < 30) {
			divs2.push_back(divs[i]);
			continue;
		}
	}
	divs = divs2;

	for (int i=1;i<n;++i){
		for (int j: divs) {
			if (j < a[i] && !inside(a[i] / j)) {
				cout << "No" << endl;
				return;
			}
		}
	}
	cout << "Yes" << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}