#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "a"

char s[1000];
char t[1000];

inline int conv(char c) {
	if (c == '(')
		return 0;
	else if (c == '[')
		return 1;
	else
		return 2;
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(10);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	gets(s);
	gets(t);
	int n = strlen(s) / 2;
	int a = 0, b = 0;
	for (int i = 0; i < n; ++i) {
		int k1 = conv(s[i * 2]);
		int k2 = conv(t[i * 2]);
		if (k1 == k2)
			continue;
		if ((k1 == 0 && k2 == 1) || (k1 == 1 && k2 == 2) || (k1 == 2 && k2 == 0))
			++a;
		else
			++b;
	}
	if (a > b)
		cout << "TEAM 2 WINS\n";
	else if (a < b)
		cout << "TEAM 1 WINS\n";
	else
		cout << "TIE\n";
}