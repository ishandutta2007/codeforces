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
vector<long long int>as, bs;
int N, K;
bool check(const long long int bake) {
	long long int magic= 0;
	for (int i = 0; i < as.size(); ++i) {
		const long long int need = as[i] * bake;
		magic += max(0ll, need - bs[i]);
		if (magic > K)return false;
	}
	return magic <= K;
}
int main() {
	cin >> N >> K;
	as.resize(N); bs.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> as[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> bs[i];
	}
	long long int amin = 0;
	long long int amax = 3e9;
	while (amin + 1 != amax) {
		long long int amid = (amin + amax) / 2;
		if (check(amid)) {
			amin = amid;
		}
		else {
			amax = amid;
		}
	}
	cout << amin << endl;
	return 0;
}