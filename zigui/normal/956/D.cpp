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

pii D[MX], *O[MX];
int A[MX], B[MX], R[MX];

struct BIT{
	int t[MX];
	int read(int x){
		int r = 0;
		while(x) r += t[x], x -= x&-x;
		return r;
	} void update(int x, int v){
		while(x < MX) t[x] += v, x += x&-x;
	}
} tree;
int N, W;

ll c1(pii x, pii y){
	x.second -= W, y.second -= W;
	if(x.second < 0) x.first *= -1, x.second *= -1;
	if(y.second < 0) y.first *= -1, y.second *= -1;
	return (ll)x.first * y.second - (ll)x.second * y.first;
}

ll c2(pii x, pii y){
	x.second += W, y.second += W;
	if(x.second < 0) x.first *= -1, x.second *= -1;
	if(y.second < 0) y.first *= -1, y.second *= -1;
	return (ll)x.first * y.second - (ll)x.second * y.first;
}

int main()
{
	ll ans = 0;
	scanf("%d%d", &N, &W);
	for(int i = 1; i <= N; i++) scanf("%d%d", &D[i].first, &D[i].second);
	for(int i = 1; i <= N; i++) O[i] = D+i;
	sort(O+1, O+N+1, [&](pii* l, pii* r){
		return c1(*l, *r) < 0 || c1(*l, *r) == 0 && c2(*l, *r) < 0;
	});
	for(int i = 1; i <= N; i++) A[i] = O[i] - D, R[A[i]] = i;
	ll ct = 1;
	for(int i = 1; i < N; i++){
		if(c1(*O[i], *O[i+1]) == 0) ct++;
		else ans += ct*(ct-1)/2, ct = 1;
	}
	ans += ct*(ct-1)/2, ct = 1;
	if(W == 0) return !printf("%lld\n", ans);

	sort(O+1, O+N+1, [&](pii* l, pii* r){
		return c2(*l, *r) < 0 || c2(*l, *r) == 0 && c1(*l, *r) < 0;
	});
	for(int i = 1; i <= N; i++) B[i] = R[O[i] - D];
	for(int i = 1; i < N; i++){
		if(c2(*O[i], *O[i+1]) == 0) ct++;
		else ans += ct*(ct-1)/2, ct = 1;
	}
	ans += ct*(ct-1)/2, ct = 1;
	for(int i = N; i >= 1; i--){
		ans += tree.read(B[i]);
		tree.update(B[i], 1);
	}
	printf("%lld\n", ans);
}