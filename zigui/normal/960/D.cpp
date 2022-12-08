#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cmath>
#include <complex>
#include <deque>
#include <functional>
#include <iostream>
#include <limits.h>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#pragma warning(disable:4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble

typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

const int MX = 100005;

ll val[MX];
void shift(int c, ll K){
	ll unit = (1ll<<c);
	val[c] = ((val[c] + K) % unit + unit) % unit;
}

void trace(int c, ll X){
	printf("%lld ", X);
	if(c == 0) return;
	ll d = val[c];
	ll unit = (1ll<<c);
	ll p = d + (X-unit);
	p = (p%unit + unit) % unit + unit;
	p /= 2;
	trace(c-1, p);
}

int main()
{
	int Q;
	scanf("%d", &Q);
	for(int i = 1; i <= Q; i++){
		ll T, X, K;
		scanf("%lld%lld", &T, &X);
		int v = 63-__builtin_clzll(X);
		if(T == 3) trace(v, X), puts("");
		else{
			scanf("%lld", &K);
			if(T == 2) shift(v, K);
			else shift(v, K), shift(v+1, -2*K);
		}
	}
}