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
	int N, B, P; cin >> N >> B >> P;
	int bottle = (N - 1)*(2 * B + 1);
	int towel = N*P;
	cout << bottle << " " << towel << endl;
	return 0;
}