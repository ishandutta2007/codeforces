#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	long long int N, K; cin >> N >> K;
	long long int t = N / K;
	if (t % 2==1)cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}