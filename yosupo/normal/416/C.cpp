#include <algorithm>
#include <numeric>
#include <map>
#include <vector>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;
typedef pair<int, int> p;
typedef pair<int, p> pp;
typedef long long ll;
int main() {
	int n;
	cin >> n;
	vector<pp> v = vector<pp>(n);
	for (int i = 0; i < n; i++) {
		int c_, p_;
		cin >> c_; cin >> p_;
		v[i] = pp(c_, p(p_, i+1));
	}
	sort(v.begin(),v.end());
	
	int k;
	cin >> k;
	vector<p> r = vector<p>(k);
	for (int i = 0; i < k; i++) {
		int r_;
		cin >> r_;
		r[i] = p(r_, i+1);
	}
	sort(r.begin(),r.end());

	vector<p> res;
	int max = 0;
	for (int i = 0; i < k; i++) {
		int index = -1, price = 0;
		for (int j = 0; j < v.size(); j++) {
			if (v[j].first > r[i].first) break;
			if (price <= v[j].second.first) {
				index = j;
				price = v[j].second.first;
			}
		}
		if (index >= 0) {
			res.push_back(p(v[index].second.second, r[i].second));
			v.erase(v.begin()+index);
			max += price;
		}
	}
	cout << res.size() << " " << max << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i].first << " " << res[i].second << endl;
	}
}