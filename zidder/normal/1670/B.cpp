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
	string s;
	cin >> s;
	int k;
	cin >> k;
	vector<char> c(k);
	for (int i=0;i<k;++i) cin>>c[i];
	vector<int> nxt(n), prv(n);
	for (int i=0;i<n;++i) nxt[i] = i+1;
	for (int i=0;i<n;++i) prv[i] = i-1;
	set<int> r;
	vector<int> rm;
	auto remove =[&](int ind){
		if (prv[ind] >= 0) {
			nxt[prv[ind]] = nxt[ind];
		}
		if (nxt[ind] < n){
			prv[nxt[ind]] = prv[ind];
		}
		if (r.count(ind)) rm.push_back(ind);
	};
	for (int i=0;i<n;++i){
		for (char ci: c) if (s[i] == ci) {
			r.insert(i);
		}
	}

	int cnt = 0;
	while (r.size()) {
		rm.clear();
		bool ok = false;
		for (int i: r) {
			if (prv[i] >=0) {remove(prv[i]); ok=true;}
			else rm.push_back(i);
		}
		for (int i: rm) r.erase(i);
		if (ok) cnt++;
	}

	cout << cnt << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}