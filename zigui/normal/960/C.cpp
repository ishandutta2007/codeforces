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

int main()
{
	int X, d;
	scanf("%d%d", &X, &d);
	int num = min(3600, X); X -= num;
	num--;

	vector<ll> P, L, M;
	for(int i = 1; i <= 60; i++){
		P.push_back((1ll<<i) - i-1);
	}
	for(int i = 0; i < num; i++){
		int v = upper_bound(P.begin(), P.end(), X) - P.begin()-1;
		X -= P[v]; M.push_back(v);
	}
	L.push_back(1);
	for(int c : M){
		if(!num) break;
		ll v = L.back() + d + 1;
		for(int i = 0; i <= c; i++) L.push_back(v), num--;
	}
	for(int t = 0; t < num; t++) L.push_back(L.back() + d+1);
	printf("%d\n", L.size());
	for(ll c : L) printf("%lld ", c);
}