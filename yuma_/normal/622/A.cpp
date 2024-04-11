#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


int main() {
	long long int N; cin >> N;
	long long int now = 1;
	while (N > now) {
		N -= now;
		now++;
	}
	cout << N << endl;
	return 0;
}