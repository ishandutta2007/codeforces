#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;
const int MAX_N = 100000 + 10;
int n;

struct Skyscraper {
	int h, l, r;
	void read() {
		scanf("%d%d%d", &h, &l, &r);
	}
} skyscrapers[MAX_N];

template<class T>
struct Index: public vector<T> {
	using vector<T>::erase;
	using vector<T>::begin;
	using vector<T>::end;
	void doit() {
		sort(begin(), end());
		erase(unique(begin(), end()), end());
	}
	int get(T x) {
		return lower_bound(begin(), end(), x) - begin();
	}
};

Index<int> idx;
vector<int> st[MAX_N * 2], ed[MAX_N * 2];
int mx[MAX_N * 2]; //idx[i]-idx[i+1]

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		skyscrapers[i].read();
		idx.push_back(skyscrapers[i].l);
		idx.push_back(skyscrapers[i].r);
	}
	idx.doit();
	for (int i = 0; i < n; ++i) {
		int l = skyscrapers[i].l, r = skyscrapers[i].r;
		l = idx.get(l), r = idx.get(r);
		st[l].push_back(skyscrapers[i].h);
		ed[r].push_back(skyscrapers[i].h);
	}
	multiset<int> hs;
	hs.insert(0);

	for (int i = 0; i < idx.size(); ++i) {
		for (vector<int>::iterator e = st[i].begin(); e != st[i].end(); ++e) {
			hs.insert(*e);
		}
		for (vector<int>::iterator e = ed[i].begin(); e != ed[i].end(); ++e) {
			hs.erase(hs.find(*e));
		}
		mx[i] = *hs.rbegin();
	}

	//draw it!
	int prev = 0;
	vector<int> x, y;
	for (int i = 0; i < idx.size(); ++i) {
		if (prev != mx[i]) {
			x.push_back(idx[i]), y.push_back(prev);
			x.push_back(idx[i]), y.push_back(mx[i]);
		}
		prev = mx[i];
	}
	cout << x.size() << endl;
	for (int i = 0; i < x.size(); ++i) {
		printf("%d %d\n", x[i], y[i]);
	}
	return 0;
}