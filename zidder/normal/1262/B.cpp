#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int t;
void yes() {
	cout << "Yes" << endl;
	if (t == 1)
		exit(0);
}

void no() {
	cout << "No" << endl;
	if (t == 1)
		exit(0);
}

void solve(int test_id) {
	int n;
	cin >> n;
	vector<int> q(n), p(n);
	set<int> ps;
	for (size_t i = 0; i < n; i++)
	{
		ps.insert(i + 1);
	}
	for (size_t i = 0; i < n; i++) {
		cin >> q[i];
		if (i) {
			if (q[i] == q[i - 1]) {
				if (*ps.begin() < q[i]) {
					p[i] = *ps.begin();
					ps.erase(ps.begin());
				}
			}
			else {
				p[i] = q[i];
				if (ps.count(p[i]))
					ps.erase(p[i]);
			}
		}
		else {
			p[0] = q[0];
			if (ps.count(p[0]))
				ps.erase(p[0]);
		}
	}
	if (!ps.empty()) {
		cout << -1 << endl;
	}
	else {
		for (size_t i = 0; i < n; i++)
		{
			cout << p[i] << " ";
		}
		cout << endl;
	}
}

int main() {
	t = 1;
	cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}