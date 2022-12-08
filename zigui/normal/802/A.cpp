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
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size())  
#define rep(i, n) for(int i=0;i<n;i++)  
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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1E-11;

const int MX = 100005;

set <pii> Sx;
bool chk[400050];
int pos[400050];
int nxt[400050];
int totc = 0;

int in[400050];
int main() {
	int N, K, i, j;
	scanf("%d %d", &N, &K);
	for (i = 1; i <= N; i++) scanf("%d", &in[i]);
	for (i = 1; i <= 400000; i++) pos[i] = N + 1;
	for (i = N; i >= 1; i--) {
		nxt[i] = pos[in[i]];
		pos[in[i]] = i;
	}

	int ans = 0;
	for (i = 1; i <= N; i++) {
		int t;
		t = in[i];
		if (chk[t]) {
			Sx.erase(pii(pos[t], t));
			pos[t] = nxt[i];
			Sx.emplace(pos[t], t);
			continue;
		}
		
		if (totc == K) {
			totc--;
			auto it = Sx.end();
			it--;
			pii u = *it;
			Sx.erase(it);
			chk[u.second] = false;
		}
		
		chk[t] = true;
		ans++;
		totc++;
		pos[t] = nxt[i];
		Sx.emplace(pos[t], t);
	}
	return !printf("%d\n", ans);
}