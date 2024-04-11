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

string getnum(const string from, const string st) {
	if (from.size() >= st.size()) {
		if (from.substr(from.size() - st.size()) <= st) {
			string ans = from.substr(0,from.size() - st.size()) + st;
			return ans;
		}
		else {
			int anum;
			if (from.size() == st.size()) {
				anum = 0;
			}
			else {
				anum = stoi(from.substr(0, from.size() - st.size()));
			}
			anum++;
			string ans = to_string(anum) + st;
			return ans;
		}
	}
	else {
		return st;
	}
}
int main() {
	int N; cin >> N;
	while (N--) {
		string st; cin >> st;
		st = st.substr(4,st.size()-4);
		string from = "1988";
		for (int keta = 1; keta <= st.size(); ++keta) {
			from = to_string(stoi(from) + 1);
			from = getnum(from, st.substr(st.size() - keta, keta));
			if (from[0] == '0')from = '1' + from;
		}
		cout << from << endl;
	}
	return 0;
}