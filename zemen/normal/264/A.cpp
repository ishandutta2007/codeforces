#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>
#include <deque>

using namespace std;

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

char s[1000001];
deque <int> o;

int main() {
	gets(s);
	int n = strlen(s);
	o.push_back(n);
	for (int i = n - 1; i > 0; --i) {
		if (s[i - 1] == 'l')
			o.push_back(i);
		else
			o.push_front(i);
	}
	while (!o.empty()) {
		printf("%d\n", o.front());
		o.pop_front();
	}
}