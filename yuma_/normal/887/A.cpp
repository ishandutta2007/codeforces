#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;


int main() {
	string st; cin >> st;
	if (st.find('1') == string::npos) {
		cout << "no" << endl;
	}
	else {

		bool ok = count(st.begin() + st.find('1'), st.end(), '0') >= 6;
		if (ok)cout << "yes" << endl;
		else cout << "no" << endl;
	}
	return 0;
}