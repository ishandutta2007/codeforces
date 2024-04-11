#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <functional>

using namespace std;

void solve(int test_ind){
	int n, x;
	cin >> n >> x;
	x--;
	vector<vector<int> > g(n);
	for (int i=1;i<n;++i){
		int a, b;
		scanf("%d%d", &a, &b);
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> p(n);
	for (int i=0;i<n;++i){
		scanf("%d", &p[i]);
		p[i]--;
	}

	int center = -1;
	for (int i=0;i<n;++i) if (g[i].size() == n - 1) center = i;

	if (center == -1) {
		cout << "Alice" << endl;
		return;
	}
	// star
	int c = 0;
	for (int i=0;i<n;++i) {
		if (p[i] == i) c++;
	}
	if (c == n) {
		cout << "Alice" << endl;
		return;
	}

	if (n == 2) throw "ERROR!!!";

	if (n == 3) {
		if (p[x] == x) {
			cout << "Alice" << endl;
			return;
		}
		if (p[center] == center || x == center) {
			cout << "Bob" << endl;
			return;
		}
		if (p[center] == x) {
			cout << "Bob" << endl;
			return;
		}
		cout << "Alice" << endl;
		return;
	}

	if ((x != center && p[center] != x)) {
		if (p[center] != center) {
			for (int i=0;i<n;++i) if (p[i] == center) {
				swap(p[i], p[center]);
				x = center;
				break;
			}
		}
	}

	if (p[center] == center) {
		int cnt = 0;
		vector<bool> visited(n, false);
		visited[center] = true;
		for (int i=0;i<n;++i) {
			if (!visited[i]){
				for (int j=p[i];j!=i;j=p[j]){
					visited[j] = true;
					cnt++;
				}
				visited[i] = true;
			}
		}
		if (x == center) {
			if (cnt == 0 || cnt % 2) {
				cout << "Alice" << endl;
				return;
			}
		} else {
			if (cnt == 1 && p[x] == x || cnt % 2 == 0) {
				cout << "Alice" << endl;
				return;
			}
		}
	}
	// bad star
	cout << "Bob" << endl;
	return;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}