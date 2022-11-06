#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt" > "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\b.answer"
int main() {
	int N; cin >> N;
	long long int sum; cin >> sum;
	int dist = 0;
	for (int i = 0; i < N; ++i) {
		char c; cin >> c;
		int a; cin >> a;
		if (c == '+') {
			sum += a;
		}
		else {
			if (sum >= a) {
				sum -= a;
			}
			else {
				dist++;
			}
		}
	}
	cout << sum <<" "<<dist<< endl;
	return 0;
}