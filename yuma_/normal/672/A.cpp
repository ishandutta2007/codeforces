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
	int rest(N-1);
	for (int i = 1; i < 10000; ++i) {
		int asize = to_string(i).size();
		if (rest < asize) {
			cout << to_string(i)[rest] << endl;
			break;
		}
		else {
			rest -= asize;
		}
	}
	return 0;
}