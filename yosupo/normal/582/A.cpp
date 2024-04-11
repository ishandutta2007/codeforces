#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
	if (a == 0) return b;
	return gcd(b%a, a);
}

int main() {
	int n;
	cin >> n;
	multiset<ll, greater<ll>> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ll w;
			cin >> w;
			s.insert(w);
		}
	}

	vector<ll> res;
	for (int i = 0; i < n; i++) {
		ll u = *s.begin();
		s.erase(s.find(u));
		for (int j = 0; j < i; j++) {
			s.erase(s.find(gcd(res[j], u)));
			s.erase(s.find(gcd(res[j], u)));
		}
		res.push_back(u);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " ";
	} cout << endl;
    return 0;
}