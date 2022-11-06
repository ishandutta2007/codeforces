#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
int main() {
	int a, b, c; cin >> a >> b >> c;
	bool ok = true;
	if (a == b) {
		ok = true;
	}
	else {
		if (a > b) {
			if (c > 0) {
				ok = false;
			}
			else if (c < 0) {
				c = -c;
				int sa = a - b;
				if (sa%c)ok = false;
				else ok = true;
			}
			else {
				ok = false;
			}
		}
		else {
			if (c < 0) {
				ok = false;
			}
			else if (c > 0) {
				int sa = -(a - b);
				if (sa%c)ok = false;
				else ok = true;
			}
			else {
				ok = false;
			}
		}
	}
	if (ok)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}