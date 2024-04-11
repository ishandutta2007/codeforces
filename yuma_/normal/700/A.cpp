#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.txt"

//

int main() {
	int n, l, k;ld  v1, v2; cin >> n >> l >> v1 >> v2 >> k;
	int bustime = (n - 1) / k + 1;
	
	ld t1 = l / ((bustime - 1)*v1 + v2 + (bustime - 1)*v1*(v2 - v1) / (v2 + v1));
	ld t2 = t1*(v2 - v1) / (v2 + v1);
	ld ans = t1*bustime + t2*(bustime - 1);
	cout << setprecision(12) << fixed << ans << endl;
	return 0;
}