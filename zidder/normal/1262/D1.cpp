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

struct T {
	int left = -1;
	int right = -1;
	int count;
	int minl, maxr;
};

vector<T> tr(1);

void add(int pos, int v = 0) {
	tr[v].count++;
	if (tr[v].maxr - tr[v].minl == 1) {
		return;
	}
	int m = (tr[v].minl + tr[v].maxr) >> 1;
	if (pos < m) {
		if (tr[v].left == -1) {
			tr[v].left = tr.size();
			tr.emplace_back();
			tr.back().minl = tr[v].minl;
			tr.back().maxr = m;
		}
		add(pos, tr[v].left);
	}
	else {
		if (tr[v].right == -1) {
			tr[v].right = tr.size();
			tr.emplace_back();
			tr.back().minl = m;
			tr.back().maxr = tr[v].maxr;
		}
		add(pos, tr[v].right);
	}
}

int get_elem(int p, int v = 0) {
	if (tr[v].maxr - tr[v].minl == 1)
		return tr[v].minl;
	if (tr[v].left != -1 && tr[tr[v].left].count >= p) {
		return get_elem(p, tr[v].left);
	}
	return get_elem(p - (tr[v].left == -1 ? 0 : tr[tr[v].left].count), tr[v].right);
}

void solve(int test_id) {
	int n;
	cin >> n;
	vector<int> v(n);
	vector<pair<int, int> > s;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		s.emplace_back(v[i], -i);
	}
	sort(s.begin(), s.end());
	reverse(s.begin(), s.end());
	tr[0].count = 0;
	tr[0].minl = 0;
	tr[0].maxr = 1000000001;
	int m;
	cin >> m;
	vector<pair<pair<int, int>, int> > qs;
	for (size_t i = 0; i < m; i++)
	{
		int k, p;
		cin >> k >> p;
		qs.emplace_back(make_pair(k - 1, p), i);
	}
	vector<int> ans(m);
	sort(qs.begin(), qs.end());
	for (size_t i = 0, ind = 0; i < n && ind < m; ++i)
	{
		if (qs[ind].first.first < i) {
			ind++;
			continue;
		}
		add(-s[i].second);
		while (ind < m && qs[ind].first.first == i) {
			int p = qs[ind].first.second;
			ans[qs[ind].second] = v[get_elem(p)];
			ind++;
		}
	}
	for (size_t i = 0; i < m; i++)
		cout << ans[i] << endl;

}

int main() {
	t = 1;
	//cin >> t;
	for (size_t i = 0; i < t; i++)
	{
		solve(i + 1);
	}
	return 0;
}
/*
1
10 5
()((()()))
*/