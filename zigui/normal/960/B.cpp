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

int A[MX], B[MX], C[MX];

int main()
{
	int N, P, Q;
	scanf("%d%d%d", &N, &P, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", A+i);
	for(int i = 1; i <= N; i++) scanf("%d", B+i);
	priority_queue<int> X;
	for(int i = 1; i <= N; i++) X.push(abs(B[i] - A[i]));
	for(int t = 0; t < P+Q; t++){
		int p = X.top(); X.pop();
		X.push(p? p-1 : 1);
	}
	ll ans = 0;
	while(X.size()){
		ans += (ll)X.top() * X.top();
		X.pop();
	}
	printf("%lld\n", ans);
}