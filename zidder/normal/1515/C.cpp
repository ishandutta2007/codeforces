#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void solve(int test_ind){
	// [a, a+x]
	int n, m, x;
	cin >> n >> m >> x;
	vector<int> h(n);
	for (int &i: h) scanf("%d", &i);
	vector<pair<int, int> > hh(n);
	for (int i=0;i<n;++i) hh[i] = {h[i], i};
	set<pair<int, int> > s;
	vector<int> y(m, 0);
	vector<int> inds(n);
	for (int i=0;i<m;++i) s.emplace(0, i);
	sort(hh.begin(), hh.end());
	for (int i=n-1;i>=0;--i){
		int ind = s.begin()->second;
		s.erase(s.begin());
		y[ind] += hh[i].first;
		inds[hh[i].second] = ind + 1;
		s.emplace(y[ind], ind);
	}
	cout << "YES" << endl;
	for (int i: inds) printf("%d ", i);
	cout << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}