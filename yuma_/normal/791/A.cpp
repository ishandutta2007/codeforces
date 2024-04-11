#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
const ld eps = 1e-9;

//// < "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\a.txt" > "d:\d_download\visual studio 2015\projects\programing_contest_c++\debug\b.txt"


int main() {
	long long int a, b; cin >> a >> b;
	int ans = 0;
	while (1) {
		if (a > b)break;
		else {
			a *= 3;
			b *= 2;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}