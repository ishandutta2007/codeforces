#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	int a[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	string s;
	cin >> s;
	ll r = 0;
	for (char c: s) {
		r += a[c-'1'];
	}
	cout << r << endl;
}