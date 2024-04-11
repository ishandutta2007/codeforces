#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;


int main() {
	int h,  m;
	scanf("%d:%d", &h, &m);
	int a; cin >> a;
	m += a;
	int plus = m / 60;
	h += plus;
	m %= 60;
	h %= 24;
	printf("%02d:%02d", h, m);
	return 0;
}