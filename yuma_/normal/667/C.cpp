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
	string st; cin >> st; reverse(st.begin(), st.end());
	vector<set<string>>sets(st.size());
	sets[0].emplace("");
	for (int i = 0; i < st.size(); ++i) {
		for (int l = 2; l <= 3; ++l) {
			if (i + l <= st.size() - 5) {
				string suf = st.substr(i, l);
				if (sets[i].size() >= 2) {
					sets[i + l].emplace(suf);
				}
				else if (sets[i].size() == 1) {
					if (suf != *sets[i].begin()) {
						sets[i + l].emplace(suf);
					}
				}
				else {

				}
			}
		}
	}
	set<string>anss;
	
	for (int i = 1; i < st.size(); ++i) {
		for (auto s : sets[i]) {
			reverse(s.begin(), s.end());
			anss.emplace(s);
		}
	}
	cout << anss.size() << endl;
	for (auto ans : anss) {
		cout << ans << endl;
	}
	return 0;
}