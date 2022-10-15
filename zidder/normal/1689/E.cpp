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
	for (int &i: a) scanf("%d", &i);
	int m = 0;
	for (int &i: a) {
		if (i == 0) {
			i = 1;
			m++;
		}
	}
	auto check = [&]() -> bool {
		vector<vector<bool> > v(30, vector<bool>(30));
		vector<bool> vis(30, true);
		for (int i=0;i<30;++i) for (int j: a) if (j&(1<<i)) vis[i] = false;
		for (int i: a) {
			vector<int> js;
			for (int j=0;j<30;++j) if ((1<<j)&i) js.push_back(j);
			for (int j1: js) for (int j2: js) v[j1][j2] = true;
		}
		vector<int> q;
		for (int ind=0;ind<30;++ind) if (!vis[ind]) {q.push_back(ind); break;}
		vis[q[0]] = true;
		for (int ind=0;ind<q.size();++ind) {
			for (int j=0;j<30;++j) {
				if (v[q[ind]][j] && !vis[j]) {
					vis[j] = true;
					q.push_back(j);
				}
			}
		}
		for (bool b: vis) if (!b) return false;
		return true;
	};

	auto print = [&](){
		cout << m << endl;
		for (int i: a) printf("%d ", i);
		cout << endl;
	};

	if (check()) {
		cout << m << endl;
		for (int i: a) printf("%d ", i);
		cout << endl;
		return;
	}

	m++;
	for (int &i: a) {
		i--;
		if (i && check()) {
			print();
			return;
		}
		i += 2;
		if (check()) {
			print();
			return;
		}
		i--;
	}

	m++;
	vector<vector<bool> > v(30, vector<bool>(30));
	for (int i: a) {
		vector<int> js;
		for (int j=0;j<30;++j) if ((1<<j)&i) js.push_back(j);
		for (int j1: js) for (int j2: js) v[j1][j2] = true;
	}

	vector<bool> vis(30, true);
	for (int i=0;i<30;++i) for (int j: a) if (j&(1<<i)) vis[i] = false;
	vector<vector<int> > components;
	vector<int> least;
	for (int i=0;i<30;++i) {
		if (vis[i]) continue;
		vector<int> q;
		q.push_back(i);
		vis[i] = true;
		int msk = (1<<i);
		for (int ind=0;ind<q.size();++ind) {
			for (int j=0;j<30;++j) {
				if (v[q[ind]][j] && !vis[j]) {
					vis[j] = true;
					q.push_back(j);
					msk |= (1<<j);
				}
			}
		}
		vector<int> inds;
		for (int j=0;j<n;++j) if (a[j] & msk) inds.push_back(j);
		for (int j=0;j<n;++j) if (a[j] & (1<<i)) {least.push_back(j); break;}
		components.push_back(inds);
	}

	int j = least.back();
	a[j]--;
	for (int i: components.back()) {
		if (i == j) continue;
		a[i]++;
		break;
	}
	print();
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}