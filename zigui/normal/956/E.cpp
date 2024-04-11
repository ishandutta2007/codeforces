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

const int MX = 10005;
const int MM = 1000000007;

int N, L, R;
int D[MX], p1[MX], p2[MX];

int main()
{
	int tot = 0;
	scanf("%d%d%d", &N, &L, &R);
	for(int i = 1; i <= N; i++){
		scanf("%d", D+i);
		tot += D[i];
	}
	vector<int> P, Q;
	for(int i = 1; i <= N; i++){
		int a;
		scanf("%d", &a);
		if(a) P.push_back(D[i]);
		else Q.push_back(D[i]);
	}
	int cur = 0;
	int arr[2][MX] = {}, *S = arr[0], *E = arr[1];
	for(int i = 0; i < MX; i++) S[i] = -1e9;
	S[0] = 0;

	for(int c : Q){
		cur += c;
		for(int i = 0; i < MX; i++) E[i] = -1e9;
		for(int i = 0; i <= cur; i++){
			E[i] = S[i];
			if(i >= c) E[i] = max(E[i], S[i-c]);
		}
		swap(S, E);
	}
	sort(P.begin(), P.end(), greater<int>());

	for(int c : P){
		cur += c;
		for(int i = 0; i < MX; i++) E[i] = -1e9;
		for(int i = 0; i <= cur; i++){
			E[i] = S[i] + (i+(tot-cur) >= L && i+(tot-cur) <= R);
			if(i >= c) E[i] = max(E[i], S[i-c] + (L <= i-c && i-c <= R));
		}
		swap(S, E);
	}
	int ans = 0;
	for(int i = 0; i <= cur; i++) ans = max(ans, S[i]);
	printf("%d", ans);
}