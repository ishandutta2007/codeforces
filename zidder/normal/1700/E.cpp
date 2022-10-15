#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void solve(int test_ind){
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) scanf("%d", &a[i][j]);
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) a[i][j]--;

	vector<pair<int, int> > pos(n*m);
	for (int i=0;i<n;++i) for (int j=0;j<m;++j) pos[a[i][j]] = {i, j};

	auto valid = [&](int i, int j){
		if (i < 0 || i >= n || j < 0 || j >= m) return false;
		return true;
	};

	auto check = [&]() {
		for (int i=1;i<n*m;++i){
			auto p = pos[i];
			bool ok = false;
			for (int j=0;j<4;++j){
				int x = p.first + dx[j];
				int y = p.second + dy[j];
				if (valid(x, y)) {
					if (a[x][y] < i) {
						ok = true;
						break;
					}
				}
			}
			if (!ok) {
				return false;
			}
		}
		return true;
	};

	if (check()) {
		cout << 0 << endl;
		return;
	}

	auto swp = [&](int x, int y) {
		swap(a[pos[x].first][pos[x].second], a[pos[y].first][pos[y].second]);
		swap(pos[x], pos[y]);
	};

	set<pair<int, int> > st;

	for (int j=0;j<4;++j) {
		// 1 to 2
		int x = pos[1].first + dx[j];
		int y = pos[1].second + dy[j];
			// cout << axy << endl;
		if (valid(x, y)) {
			int axy = a[x][y];
			swp(0, axy);
			if (check()) {
				st.emplace(0, axy);
				st.emplace(axy, 0);
			}
			swp(0, axy);
		}
	}

	set<int> nes = {0};
	int k = -1;
	for (int i=1;i<n*m;++i){
		auto p = pos[i];
		vector<int> ns;
		for (int j=0;j<4;++j){
			int x = p.first + dx[j];
			int y = p.second + dy[j];
			if (valid(x, y)) {
				if (a[x][y] < i) {
					ns.push_back(a[x][y]);
				}
			}
		}
		if (ns.empty()) {
			k = i;
			break;
		} else {
			if (ns.size() == 1) nes.insert(ns[0]);
		}
	}

	auto slv = [&](int ind) {
		set<int> nss = nes;
		vector<int> ns;
		int mn = n * m;
		for (int j=0;j<4;++j){
			int x = pos[ind].first + dx[j];
			int y = pos[ind].second + dy[j];
			if (valid(x, y)) {
				if (a[x][y] < k) {
					ns.push_back(a[x][y]);
					mn = min(mn, a[x][y]);
				}
			}
		}
		if (ns.empty()) return;
		if (ns.size() == 1) {
			nes.insert(ns[0]);
		}
		set<int> ns2;
		for (int i=k;i<n*m;++i) {
			if (i == ind) {
				ns2 = nes;
				continue;
			}
			auto p = pos[i];
			vector<int> ns;
			for (int j=0;j<4;++j){
				int x = p.first + dx[j];
				int y = p.second + dy[j];
				if (valid(x, y)) {
					if (a[x][y] < i || a[x][y] == ind) {
						ns.push_back(a[x][y]);
					}
				}
			}
			if (ns.empty()) {
				return;
			} else {
				if (ns.size() == 1) nes.insert(ns[0]);
			}
		}
		for (int i=mn+1;i<k;++i) {
			if (ns2.count(i)) continue;
			st.emplace(ind, i);
			st.emplace(i, ind);
		}
		nes = nss;
	};

	for (int j=0;j<4;++j) {
		int x = pos[k].first + dx[j];
		int y = pos[k].second + dy[j];
		if (valid(x, y)) {
			slv(a[x][y]);
			int axy = a[x][y];
			swp(axy, k);
			if (check()) {
				st.emplace(axy, k);
				st.emplace(k, axy);
			}
			swp(axy, k);
		}
	}
	set<int> reachable;
	for (int i=0;i<k;++i) {
		for (int j=0;j<4;++j){
			int x = pos[i].first + dx[j];
			int y = pos[i].second + dy[j];
			if (valid(x, y) && a[x][y] > k) {
				reachable.insert(a[x][y]);
			}
		}
	}
	// swap k with reachable
	bool end = true;
	for (int i=k+1;i<n*m;++i){
		auto p = pos[i];
		vector<int> ns;
		for (int j=0;j<4;++j){
			int x = p.first + dx[j];
			int y = p.second + dy[j];
			if (valid(x, y)) {
				if (a[x][y] < i && a[x][y] != k) {
					ns.push_back(a[x][y]);
				}
			}
		}
		if (ns.empty()) {
			bool ok = false;
			for (int j=0;j<4;++j){
				int x = pos[i].first + dx[j];
				int y = pos[i].second + dy[j];
				if (valid(x, y) && a[x][y] == k) {
					ok = true;
				}
			}

			// ok => k is nei of i
			for (int j=0;j<4;++j){
				int x = pos[i].first + dx[j];
				int y = pos[i].second + dy[j];
				if (valid(x, y)) {
					int axy = a[x][y];
					swp(axy, k);
					// cout << axy << " " << k << endl;
					if (check()) {
						// cout << "checked" << endl;
						st.emplace(axy, k);
						st.emplace(k, axy);
					}
					swp(axy, k);
				}
			}
			// cout << "hey" << endl;
			if (ok) {
				if (!reachable.empty())  {
					int axy = *reachable.begin();
					swp(k, axy);
					if (check()) {
						for (int j: reachable) {
							if (j < i) {
								st.emplace(k, j);
								st.emplace(j, k);
							}
						}
					}
					swp(k, axy);
					// k is reachable
				}
			}
			end = false;
			break;
		}
	}
	if (end) {
		int mn = n * m;
		for (int j=0;j<4;++j){
			int x = pos[k].first + dx[j];
			int y = pos[k].second + dy[j];
			if (valid(x, y)) {
				mn = min(mn, a[x][y]);
			}
		}
		for (int i: reachable) {
			if (i > mn) {
				st.emplace(i, k);
				st.emplace(k, i);
			}
		}
	}

	if (st.empty()) {
		cout << 2 << endl;
	} else {
		cout << 1 << " " << st.size() / 2 << endl;
	}
}

int main(){
	int t=1;
	//cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}