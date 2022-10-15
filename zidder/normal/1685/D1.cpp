#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

vector<int> solve(int n, vector<int> p){
	vector<int> p1;
	p1 = p;
	vector<vector<int> > cycles;
	for (int i=0;i<n;++i){
		if (p[i] == -1) continue;
		vector<int> cycle={i};
		for (int j=p[i];j!=i;j=p[j]){
			cycle.push_back(j);
		}
		for (int j: cycle) p[j] = -1;
		cycles.push_back(cycle);
	}
	
	p = p1;

	// 2 x max difference

	for (int l=0;l<n;++l){
		for (int mn=0;mn<n-l;++mn){
			int mx = mn+l;
			// each has in [mn, mx]
			int cnt = 0;
			for (auto &c:cycles){
				for (int i: c) {
					if (mn <= i && i <= mx){
						cnt++;
						break;
					}
				}
			}
			if (cnt == cycles.size()) {
				vector<int> a;
				vector<pair<int, int> > ci;
				for (int ind=0;ind<cycles.size();++ind){
					for (int i: cycles[ind]) {
						if (mn <= i && i <= mx){
							ci.emplace_back(i, ind);
							break;
						}
					}
				}
				sort(ci.begin(), ci.end());
				for (int i=0;i<ci.size();++i){
					int ind = ci[i].second;
					int j = ci[i].first;
					// cout << ind << " " << j << endl;
					while (p[j] != -1) {
						a.push_back(j);
						int pj = p[j];
						p[j] = -1;
						j = pj;
					}
				}
				reverse(a.begin(), a.end());
				return a;
			}
		}
	}
	return {};
}

vector<int> solve3(int n, vector<int> p){
	vector<int> p1=p;
	vector<vector<int> > cycles(n);
	vector<bool> nxt(n, false);
	for (int i=0;i<n;++i) {
		if (p[i] == -1) continue;
		vector<int> cycle={i};
		for (int j=p[i];j!=i;j=p[j]){
			cycle.push_back(j);
		}
		if (i) nxt[i-1] = true;
		cycles[i] = cycle;
		for (int j: cycle) p[j] = -1;
	}
	p = p1;
	vector<int> a;
	function<void(int)> dfs =[&](int v){
		for (int u: cycles[v]) {
			a.push_back(u);
			if (nxt[p[u]]) {
				dfs(p[u]+1);
			}
		}
		cycles[v].clear();
	};
	for (int i=0;i<n;++i){
		dfs(i);
	}
	reverse(a.begin(), a.end());
	return a;
}

int get_ans(vector<int> &p, vector<int> &q){
	int ans1 = 0;
	for (int i=0;i<p.size();++i) {
		ans1 += abs(q[i] - p[q[(i+1)%p.size()]]);
	}
	return ans1;
}

vector<int> solve2(int n, vector<int> p){
	vector<int> q(n);
	for (int i=0;i<n;++i) q[i] = i;
	// permute q
	vector<int> ans;
	int ansd = n * n;
	do {
		int ans1 = get_ans(p, q);
		if (ans1 < ansd) {
			ansd = ans1;
			ans = q;
		}
    } while (next_permutation(q.begin(), q.end()));
	return ans;
}

void solve(int test_ind){
	// cycle1, cycle2, .., cyclen 
	int n;
	cin >> n;
	vector<int> p(n);
	for (int &i: p) scanf("%d", &i);
	for (int &i: p) --i;
	vector<int> a = solve3(n, p);
	for (int i: a) printf("%d ", i + 1);
	cout << endl;
	return;
	for (int i=0;i<n;++i) p[i] = i;
	do {
		vector<int> a = solve3(n, p);
		vector<int> b = solve2(n, p);
		if (get_ans(p, a) != get_ans(p, b)) {
			for (int i: p) cout << i << " ";
			cout << endl;
			for (int i: a) cout << i << " ";
			cout << endl;
			cout << get_ans(p, a) << endl;
			for (int i: b) cout << i << " ";
			cout << endl;
			cout << get_ans(p, b) << endl;
			cout << endl << "WA" << endl;
			// return;
		}	
	} while (next_permutation(p.begin(), p.end()));
}


int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}