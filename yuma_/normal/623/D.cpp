#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


int main() {
	int N; cin >> N;
	vector<ld>pers;
	for (int i = 0; i < N; ++i) {
		ld a; cin >> a;
		a /= 100;
		pers.push_back(a);
	}
	vector<ld>livepers(N,1);
	ld ans = 0;
	for (int i = 0; i < 1000000; ++i) {
		ld clearper = 1;
		for (int j = 0; j < N; ++j) {
			clearper *= (1 - livepers[j]);
		}
		ans += 1 - clearper;

		vector<ld>sucpers(N);
		for (int j = 0; j < N; ++j) {
			sucpers[j] = (1 - livepers[j]*(1-pers[j]))/(1- livepers[j]);
		}
		int select = max_element(sucpers.begin(), sucpers.end()) - sucpers.begin();
		livepers[select] *= 1-pers[select];

		
	}
	cout <<fixed<<setprecision(22)<< ans << endl;
	
	return 0;
}