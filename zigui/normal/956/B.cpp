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

int IT_MAX = 1 << 18;
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)

const int MX = 100005;
const int MM = 1000000007;

int N, U;
int D[MX];

int main()
{
	scanf("%d%d", &N, &U);
	for(int i = 1; i <= N; i++) scanf("%d", D+i);
	int r = 1;
	double ans = -1;
	for(int i = 1; i <= N; i++){
		while(r < N && D[r+1] - D[i] <= U) r++;
		if(D[r] - D[i] <= U && r-i >= 2) ans = max(ans, (D[r] - D[i+1]) / (double)(D[r] - D[i]));
	}
	if(ans == -1) printf("-1\n");
	else printf("%.10lf\n", ans);
}