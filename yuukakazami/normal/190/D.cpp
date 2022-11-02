#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <climits>
#include <numeric>
#include <vector>
#include <set>
using namespace std;

typedef long long int64;

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

Index<int> ida;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		ida.push_back(a[i]);
	}
	ida.doit();
	for (int i = 0; i < n; ++i) {
		a[i] = ida.get(a[i]);
	}
	vector<int> cnt(ida.size(), 0);
	multiset<int> st;
	for (int i = 0; i < cnt.size(); ++i) {
		st.insert(0);
	}

	int r = 0;

	int64 ans = 0;

	for (int i = 0; i < n; ++i) {
		//[i,r)
		while (r < n && *st.rbegin() < k) {
			int ad = a[r];
			st.erase(st.find(cnt[ad]));
			cnt[ad]++;
			st.insert(cnt[ad]);
			++r;
		}
		if (*st.rbegin() >= k)
			ans += n - r + 1;

		int rm = a[i];
		st.erase(st.find(cnt[rm]));
		cnt[rm]--;
		st.insert(cnt[rm]);
	}

	cout << ans << endl;
	return 0;
}