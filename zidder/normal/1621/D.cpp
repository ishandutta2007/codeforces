#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

pair<int, int> dirs[4] = {
	{0, 1},
	{1, 0},
	{0, -1},
	{-1, 0}
};

void solve(int test_ind){
	int n;
	scanf("%d", &n);
	vector<vector<int> > a(n, vector<int> (n, -1)), b(n, vector<int> (n, -1));
	// vector<vector<long long> > A(n, vector<long long> (n, -1)), B(n, vector<long long> (n, -1));
	long long ans = 0;
	for (int i=0;i<2*n;++i){
		for (int j=0;j<2*n;++j){
			int x;
			scanf("%d", &x);
			if (i < n && j < n) continue;
			if (i < n){
				a[i][j - n] = x;
				continue;
			}
			if (j < n){
				b[i - n][j] = x;
				continue;
			}
			ans += x;
		}
	}

	long long W = 1000000000;
	W *= 10000;

	{
		W = min(min(a[0][0], a[n-1][0]), min(a[0][n-1], a[n-1][n-1]));
		// set<pair<long long, pair<int, int>> > s; // sum, [i, j]
		// for (int i=0;i<n;++i) {s.emplace(make_pair(b[0][i], make_pair(0, i)));B[0][i] = b[0][i];}
		// for (int i=0;i<n;++i) {s.emplace(make_pair(b[n-1][i], make_pair(n-1, i)));B[n-1][i] = b[n-1][i];}
		// while (!s.empty()){
		// 	auto it = s.begin();
		// 	int i = it->second.first, j = it->second.second;
		// 	long long sm = it->first;
		// 	s.erase(it);
		// 	for (pair<int, int> &dr: dirs){
		// 		int ni = i + dr.first;
		// 		int nj = j + dr.second;
		// 		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		// 		long long ns = sm + b[ni][nj];
		// 		if (B[ni][nj] != -1 && B[ni][nj] <= ns) continue;
		// 		if (B[ni][nj] == -1){
		// 			B[ni][nj] = ns;
		// 			s.emplace(make_pair(ns, make_pair(ni, nj)));
		// 		} else {
		// 			// if (s.find(make_pair(B[ni][nj], make_pair(ni, nj))) != s.end())
		// 				s.erase(make_pair(B[ni][nj], make_pair(ni, nj)));
		// 			B[ni][nj] = ns;
		// 			s.emplace(make_pair(ns, make_pair(ni, nj)));
		// 		}
		// 	}
		// }
		// for (int i=0;i<n;++i)
		// 	W = min(W, B[i][n-1]);
		// for (int i=0;i<n;++i)
		// 	W = min(W, B[i][0]);
	}
	{
		W = min(W, 0ll+min(min(b[0][0], b[n-1][0]), min(b[0][n-1], b[n-1][n-1])));
		// set<pair<long long, pair<int, int>> > s; // sum, [i, j]
		// for (int i=0;i<n;++i) {s.emplace(make_pair(a[i][0], make_pair(i, 0)));A[i][0] = a[i][0];}
		// for (int i=0;i<n;++i) {s.emplace(make_pair(a[i][n-1], make_pair(i, n-1)));A[i][n-1] = a[i][n-1];}
		// while (!s.empty()){
		// 	auto it = s.begin();
		// 	int i = it->second.first, j = it->second.second;
		// 	long long sm = it->first;
		// 	s.erase(it);
		// 	for (pair<int, int> &dr: dirs){
		// 		int ni = i + dr.first;
		// 		int nj = j + dr.second;
		// 		if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;
		// 		long long ns = sm + a[ni][nj];
		// 		if (A[ni][nj] != -1 && A[ni][nj] <= ns) continue;
		// 		if (A[ni][nj] == -1){
		// 			A[ni][nj] = ns;
		// 			s.emplace(make_pair(ns, make_pair(ni, nj)));
		// 		} else {
		// 			// if (s.find(make_pair(A[ni][nj], make_pair(ni, nj))) != s.end())
		// 				s.erase(make_pair(A[ni][nj], make_pair(ni, nj)));
		// 			A[ni][nj] = ns;
		// 			s.emplace(make_pair(ns, make_pair(ni, nj)));
		// 		}
		// 	}
		// }
		// for (int i=0;i<n;++i)
		// 	W = min(W, A[n-1][i]);
		// for (int i=0;i<n;++i)
		// 	W = min(W, A[0][i]);
	}
	cout << ans + W << endl;
}

int main(){
	int t=1;
	cin >> t;
	for(int i=0;i<t;i++){
		solve(i);
	}
	return 0;
}