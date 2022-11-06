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
	int ans = 0;
	while (N--) {
		string st; cin >> st;
		if (st[0] == 'T')ans += 4;
		if (st[0] == 'C')ans += 6;
		if (st[0] == 'O')ans += 8;
		if (st[0] == 'D')ans+=12;
		if (st[0] == 'I')ans += 20;

	}
	cout << ans << endl;
	return 0;
}