#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	int N; cin >> N;
	int nlmin = 1e9;
	int nlmax = 0;
	int nrmin = 1e9;
	int nrmax = 0;
	for (int i = 0; i < N; ++i) {
		int l, r; cin >> l >> r;
		nlmin = min(nlmin, l);
		nlmax = max(nlmax, l);
		nrmin = min(nrmin, r);
		nrmax = max(nrmax, r);
	}
	int M; cin >> M;

	int mlmin = 1e9;
	int mlmax = 0;
	int mrmin = 1e9;
	int mrmax = 0;
	for (size_t i = 0; i < M; i++)
	{
		int l, r; cin >> l >> r;
		mlmin = min(mlmin, l);
		mlmax = max(mlmax, l);
		mrmin = min(mrmin, r);
		mrmax = max(mrmax, r);
	}
	int ans = 0;
	ans = max(ans, mlmax - nrmin);
	ans = max(ans, nlmax - mrmin);
	cout << ans << endl;
	return 0;
}