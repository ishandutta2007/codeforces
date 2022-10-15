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
	vector<int> a(n);
	map<int, vector<int> > inds;
	for (int i=0;i<n;++i) scanf("%d", &a[i]);
	for (int i=0;i<n;++i) inds[a[i]].push_back(i);
	for (auto &p: inds) {
		if (p.second.size() % 2){
			cout << -1 << endl;
			return;
		}
		reverse(p.second.begin(), p.second.end());
	}
	// a b1 .. bn a b1... bn bn.. b1 bn ... b1 b1 ... bn
	// a b1 b2 a b1 b2 b2 b1 b2 b1 b1 b2 
	vector<pair<int, int> > res;
	vector<int> ans;
	res.reserve(2 * n * n);
	int pref = 0;
	for (int i=0;i<n;++i){
		if (a[i] == -1) continue;
		inds[a[i]].pop_back();
		a[inds[a[i]].back()] = -1;
		int ind = 2;
		for (int j=i+1;j<inds[a[i]].back();++j){
			if (a[j] != -1) ind++;
		}
		int dind = inds[a[i]].back() - i + 1;
		inds[a[i]].pop_back();
		pref += ind;
		int c = 0;
		for (int j=1;j<dind-1;++j){
			if (a[i+j] == -1) continue;
			res.emplace_back(pref + c, a[i + j]);
			c++;
		}
		ans.emplace_back(ind * 2 - 2);
		pref += (ind - 2) * 2;
		c = 0;
		for (int j=dind-2;j>=1;--j){
			if (a[i+j] == -1) continue;
			res.emplace_back(pref + c, a[i + j]);
			c++;
		}
		if (ind - 2 > 0) ans.emplace_back(ind * 2 - 4);
		pref += (ind - 2);
	}
	printf("%d\n", (int)res.size());
	for (auto &p: res){
		printf("%d %d\n", p.first, p.second);
	}
	printf("%d\n", (int)ans.size());
	for (auto &a: ans){
		printf("%d\n", a);
	}
}

// 1 3 1 3 3 3 3 2 2 3

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}