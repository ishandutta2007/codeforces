#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
using namespace std;
const int MAX_N = int(1e5) + 10;
int n, a[MAX_N], m, b[MAX_N];

vector<pair<int, pair<int, int> > > parse(int a[], int n, int st) {
	vector<pair<int, pair<int, int> > > ret;
	for (int i = 0, j; i < n; i = j) {
		for (j = i; j < n && a[i] == a[j]; ++j)
			;
		ret.push_back(make_pair(a[i], make_pair(i + st, j + st - 1)));
	}
	return ret;
}

void push(vector<int>&order, vector<int>&color, pair<int, int> p,int c) {
	for (int i = p.first; i <= p.second; ++i) {
		order.push_back(i);
		color.push_back(c);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		scanf("%d", b + i);
	}

	vector<pair<int, pair<int, int> > > pa = parse(a, n, 1);
	vector<pair<int, pair<int, int> > > pb = parse(b, m, n + 1);
	if (pa.size() < pb.size())
		swap(pa, pb);
	//|pa|>=|pb|
	//insert pb into pa
	vector<int> order;
	vector<int> color;
	if (pa[0].first == pb[0].first) {
		for (int i = 0; i < pa.size(); ++i) {
			push(order, color, pa[i].second, pa[i].first);
			if (i < pb.size())
				push(order, color, pb[i].second, pb[i].first);
		}
	} else if (pb.size() < pa.size()) {
		for (int i = 0; i < pa.size() || i < pb.size(); ++i) {
			if (i < pa.size())
				push(order, color, pa[i].second, pa[i].first);
			if (i < pb.size())
				push(order, color, pb[i].second, pb[i].first);
		}
	} else {
		//who go first?
		int n = pa.size();
		int first;
		if (n % 2 == 0) {
			//0
			first = 0;
		} else {
			first = 1;
		}
		if (pa[0].first != first)
			swap(pa, pb);
		for (int i = 0; i < pa.size() || i < pb.size(); ++i) {
			if (i < pa.size())
				push(order, color, pa[i].second, pa[i].first);
			if (i < pb.size())
				push(order, color, pb[i].second, pb[i].first);
		}
	}

	for (int i = 0; i < order.size(); ++i) {
		printf("%d ", order[i]);
	}
	puts("");
	vector<int> opts;
//	copy(color.begin(), color.end(), ostream_iterator<int>(cout, " "));
//	puts("");
	for (int i = 0, j; i < color.size(); i = j) {
		for (j = i; j < color.size() && color[i] == color[j]; ++j)
			;
		//[i,j)
		if (color[i] == 1) {
			if (i > 0)
				opts.push_back(i - 1);
			opts.push_back(j - 1);
		}
	}
	cout << opts.size() << endl;
	for (int i = 0; i < opts.size(); ++i) {
		printf("%d ", opts[i] + 1);
	}
	puts("");
	return 0;
}