#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;
bool isso(long long int a) {
	if (a == 1 || a == 0)return false;
	for (long long int i = 2; i*i <= a; ++i) {
		if ((a%i)) {
		}
		else {
			return false;
		}
	}
	return true;
}
//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	vector<bool>so(101);
	vector<int>ss;
	for (int i = 2; i < 101; ++i) {
		so[i] = isso(i);
		if (so[i])ss.emplace_back(i);
	}
	vector<int>anss;
	for (int j = 0; j < 18; ++j) {
		cout << ss[j] << endl;
		string st; cin >> st;
		if (st == "yes") {
			anss.push_back(true);
		}
		else {
			anss.push_back(false);
		}

	}
	int sum = accumulate(anss.begin(), anss.end(), 0);
	if (sum > 1) {
		cout << "composite" << endl;
	}
	else if(!sum){
		cout << "prime" << endl;
	}
	else {
		int num = 0;
		for (int i = 0; i < 18; ++i) {
			if (anss[i]) {
				num = ss[i];
			}
		}
		if (num <= 10) {
			cout << num*num<<endl;
			string st; cin >> st;
			if (st == "yes") {
				cout << "composite" << endl;
			}
			else {
				cout << "prime" << endl;
			}
		}
		else {
			cout << "prime" << endl;
		}
	}
	return 0;
}