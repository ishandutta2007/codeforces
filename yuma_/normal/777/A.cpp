#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int N; cin >> N;
	N %= 6;
	int t; cin >> t;
	for (int x = 0; x < 3; ++x) {

		vector<int>v(3);
		v[x] = 1;
		for (int i = 0; i < N; ++i) {
			if (i % 2)swap(v[1], v[2]);
			else swap(v[0], v[1]);
		}
		int ans = find(v.begin(), v.end(), 1) - v.begin();
		if (ans == t)cout << x << endl;
	}
	return 0;
}