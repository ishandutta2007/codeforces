#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;


int main() {
	int N; cin >> N;
	string ast, bst; cin >> ast >> bst;
	vector<int>v(N), u(N);
	for (int i = 0; i < N; ++i) {
		v[i] = ast[i] - '0';
		u[i] = bst[i] - '0';
	}
	sort(u.begin(), u.end());
	int ansa = 0, ansb = 0;
	{
		auto au(u);
		for (int i = 0; i < N; ++i) {
			auto it = upper_bound(au.begin(), au.end(), v[i]);
			if (it == au.end())au.erase(au.begin());
			else {
				ansa++;
				au.erase(it);
			}
		}
	}
	{
		auto bu(u);
		for (int i = 0; i < N; ++i) {
			auto it = lower_bound(bu.begin(), bu.end(), v[i]);
			if (it == bu.end())bu.erase(bu.begin());
			else {
				ansb++;
				bu.erase(it);
			}
		}
	}
	cout << N - ansb << endl << ansa << endl;
	return 0;
}