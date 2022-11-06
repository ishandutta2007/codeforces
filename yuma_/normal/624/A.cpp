#include "bits/stdc++.h"
#include<unordered_map>
#pragma warning(disable:4996)
using namespace std;



int main() {
	double d, L, v1, v2; cin >> d >> L >> v1 >> v2;
	double ans = (L - d) / (v1 + v2);
	cout << setprecision(22) << fixed << ans << endl;
	return 0;
}