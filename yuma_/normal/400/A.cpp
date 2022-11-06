#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;

int a[7] = { 1,2,3,4,6,12 };

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; ++i) {
		string st; cin >> st;
		vector<int>oks;
		for (int j = 5; j >=0; --j) {
			int sa = a[j];
			bool allok = false;
			for (int k = 0; k < sa; ++k) {
				bool ok = true;
				for (int l = 0; l < 12 / sa; ++l) {
					if (st[k+ l*sa] != 'X') {
						ok = false;
					}
				}
				if (ok)allok =true;
			}
			if (allok)oks.push_back(sa);
		}
		cout << oks.size();
		for (int j = 0; j < oks.size(); ++j) {
			cout << " " << 12 / oks[j] << "x" << oks[j];
		}
		cout << endl;
	}
	return 0;
}