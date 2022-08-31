#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
typedef long long ll;

const int MN = 100100;
int a[MN], ra[MN];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; a[i]--;
		ra[a[i]] = i;
	}
	int ba = 0;
	int re = 0;
	for (int i = 0; i < n-1; i++) {
		if (ra[i] < ra[i+1]) {
			continue;
		}
		re = max(re, i+1 - ba);
		ba = i+1;
	}
	re = max(re, n - ba);
	cout << n - re << endl;
    return 0;
}