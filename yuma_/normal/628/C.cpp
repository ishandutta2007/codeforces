#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;

long long int fib[80];
int main() {
	int N, K; cin >> N >> K;
	string st; cin >> st;
	string ansst;
	for (int i = 0; i < N; ++i) {
		int num = st[i] - 'a';
		if (num < 13) {
			int minus = min(K, 25 - num);
			char nextc = st[i] + minus;
			K -= minus;
			ansst.push_back(nextc);
		}
		else {
			int minus = min(K, num);
			char nextc = st[i] - minus;
			K -= minus;
			ansst.push_back(nextc);
		}
	}
	if (K) {
		cout << -1 << endl;
	}
	else {
		cout << ansst << endl;
	}
	return 0;
}