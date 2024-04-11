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
	int N; cin >> N;
	string st; cin >> st;
	set<int>s;
	for (auto c : st) {
		s.emplace(c);
	}
	if (st.size() >= 27)cout << -1 << endl;
	else cout << st.size() - s.size() << endl;
	return 0;
}