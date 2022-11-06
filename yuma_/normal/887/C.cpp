#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;

bool valid(vector<int>&cs) {
	bool ok = true;
	for (int i = 0; i < 6; ++i) {
		
		if (cs[i * 4] == cs[i * 4 + 1] && cs[i * 4 + 1] == cs[i * 4 + 2] && cs[i * 4 + 2] == cs[i * 4 + 3]) {

		}
		else {
			ok = false;
		}
	}
	return ok;
}
void r_r(int&a, int&b, int&c, int&d) {
	int e = d;
	d = c;
	c = b;
	b = a;
	a = e;
	
}
bool ans = false;
bool check(const vector<int>cs, vector<int>aa,vector<int>bb) {
	for (int i = 0; i < 4; ++i) {
		aa[i]--;
		bb[i]--;
	}
	{
		vector<int>acs(cs);
		r_r(acs[aa[0]], acs[aa[1]], acs[aa[2]], acs[aa[3]]);
		r_r(acs[bb[0]], acs[bb[1]], acs[bb[2]], acs[bb[3]]);
		if (valid(acs))ans = true;

		r_r(acs[aa[0]], acs[aa[1]], acs[aa[2]], acs[aa[3]]);
		r_r(acs[bb[0]], acs[bb[1]], acs[bb[2]], acs[bb[3]]);
		r_r(acs[aa[0]], acs[aa[1]], acs[aa[2]], acs[aa[3]]);
		r_r(acs[bb[0]], acs[bb[1]], acs[bb[2]], acs[bb[3]]);
		if (valid(acs))ans = true;
	}
	return false;
}
bool solve(const vector<int>cs) {
	{
		vector<int>acs(cs);
		check(cs, vector<int>{3, 17, 10, 16}, vector<int>{4, 19, 9, 14});
		check(cs, vector<int>{6, 2, 23, 10}, vector<int>{8, 4, 21, 12});
		check(cs, vector<int>{1, 18, 12, 15}, vector<int>{2, 20, 11, 13});
		check(cs, vector<int>{5, 9, 24, 1}, vector<int>{7, 11, 22, 3});
		check(cs, vector<int>{5, 17, 21, 13}, vector<int>{6, 18, 22, 14});
		check(cs, vector<int>{7, 19, 23, 15}, vector<int>{8, 20, 24, 16});
	}
	return false;
}

int main() {
	vector<int>cs(24);
	for (int i = 0; i < 24; ++i) {
		cin >> cs[i];
	}
	solve(cs);
	if (ans)cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}