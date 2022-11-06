
#include "bits/stdc++.h"
using namespace std;



int main() {
	string st; cin >> st;
	for (char c = 'a'; c < 'a' + 26; ++c) {
		for (int i = 0; i < st.size() + 1; ++i) {
			string nst = st.substr(0, i) + c + st.substr(i, st.size() - i);
			bool ok = true;
			for (int j = 0; j < nst.size(); ++j) {
				if (nst[j] != nst[nst.size() - j - 1]) {
					ok = false;
					break;
				}
			}
			if (ok) {
				cout << nst << endl;
				return 0;
			}
		}
	}
	cout << "NA"<< endl;
	
	return 0;
}