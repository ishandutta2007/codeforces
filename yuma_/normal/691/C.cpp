#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class t>
using table = vector<vector<t>>;
const ld eps=1e-9;


//

int main() {
	string st; cin >> st;
	int n = st.find('.');
	string a, b;
	if (n == string::npos) {
		a = st;
		b = "";
		
	}
	else {
		a = st.substr(0, n);
		b = st.substr(n + 1);
	}
	if (all_of(a.begin(), a.end(), [](const char&c) {
		return c == '0';
	})) {
		a = "";
	}
	else {

		a = a.substr(a.find_first_not_of('0'));
	}
	if (all_of(b.begin(), b.end(), [](const char&c) {
		return c == '0';
	})) {
		b = "";
	}
	else {
		const int n = b.find_last_not_of('0');
		b = b.substr(0,n+1);
	}
	if (!a.empty()) {
		int deci = 0;
		if (b.empty()) {
			const int n = a.find_last_not_of('0');
			deci = a.size() - n-1;
			a = a.substr(0,a.find_last_not_of('0') + 1);
		}
		string ans = a + b;
		deci += a.size() - 1;
		if (ans.size() == 1) {
			cout << ans[0];
		}
		else {
			cout << ans[0];
			cout << '.';
			cout << ans.substr(1);
		}
		if (deci) {
			cout << 'E' << deci << endl;
		}
		else {

		}
	}
	else {
		int deci = int(b.find_first_not_of('0'));
		b = b.substr(deci);
		deci = -deci - 1;
		string ans = b;
		if (ans.size() == 1) {
			cout << ans[0];
		}
		else {
			cout << ans[0];
			cout << '.';
			cout << ans.substr(1);
		}
		if (deci) {
			cout << 'E' << deci << endl;
		}
		else {

		}
	}
	
	return 0;
}