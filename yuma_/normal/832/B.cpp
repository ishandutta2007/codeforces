#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


string good;

bool check(const string&a, const string &b) {
	if (a.size() != b.size())return false;
	 
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] == b[i])continue;
		if (a[i] == '?') {
			if (good.find(b[i]) != -1)continue;
			else return false;
		}
		else {
			return false;
		}
	}
	return true;
}
bool all_bad(const string st) {
	for (auto&&ch : st) {
		if (good.find(ch) != -1)return false;
	}
	return true;
}

int main() {
	cin >> good;
	string S; cin >> S;
	int n = S.find('*');

	string frs, bas;

	if (n != -1) {
		frs = S.substr(0, n);
		bas = S.substr(n + 1);
	}
	int Q; cin >> Q;
	while (Q--) {
		string st; cin >> st;
		int ans = -1;
		if (n == -1) {
			ans = check(S, st);
		}
		else {
			int aa = n;
			int bb = int(st.size())- int(S.size() - 1) ;
			int cc = int(st.size()) - aa - bb;
			if (bb<0)ans = 0;
			else {
				if (check(frs, st.substr(0, aa)) && 
					all_bad(st.substr(aa,bb)) &&
					check(bas, st.substr(aa+bb))) {
					ans = 1;
				}
				else {
					ans = 0;
				}
			}
		}
		assert(ans != -1);
		if (ans)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}