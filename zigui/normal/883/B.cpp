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
//#include <unordered_map>  
//#include <unordered_set>  
#include <vector>

#pragma warning(disable:4996)  
#pragma comment(linker, "/STACK:336777216")  
using namespace std;

#define mp make_pair  
#define Fi first  
#define Se second  
#define pb(x) push_back(x)  
#define szz(x) ((int)(x).size()) 
#define all(x) (x).begin(), (x).end()  
#define ldb ldouble  

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;
typedef tuple<int, int, int> t3;
#define rep(i, n) for(int i=0;i<n;i++)

int IT_MAX = 1 << 18;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

vector <int> conn[200050];
vector <int> rconn[200050];
int inc[200050];
int mx[200050];
int ans[200050];

int mn[200050];
set <pii> Sx1;
set <pii> Sx2;
vector <int> Vl;
void propagate() {
	while (!Vl.empty()) {
		int t = Vl.back();
		Vl.pop_back();
		for (auto it : rconn[t]) {
			mn[it] = max(mn[it], ans[t] + 1);
			if (--inc[it] == 0) Sx2.emplace(mn[it], it);
		}
	}
}
int main() {
	int N, M, K, i, j;
	scanf("%d %d %d", &N, &M, &K);
	for (i = 1; i <= N; i++) {
		int t;
		scanf("%d", &t);
		ans[i] = t;
		if (t != 0) mx[i] = mn[i] = t;
		else {
			mn[i] = 1;
			mx[i] = K;
		}
	}
	for (i = 1; i <= M; i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		conn[t1].push_back(t2);
		rconn[t2].push_back(t1);
	}
	
	for (i = 1; i <= N; i++) inc[i] = rconn[i].size();
	vector <int> Vu;
	for (i = 1; i <= N; i++) if (!inc[i]) Vu.push_back(i);
	for (i = 0; i < Vu.size(); i++) {
		for (auto it : conn[Vu[i]]) {
			mx[it] = min(mx[it], mx[Vu[i]] - 1);
			if (--inc[it] == 0) Vu.push_back(it);
		}
	}
	if (Vu.size() != N) return !printf("-1\n");
	Vu.clear();

	for (i = 1; i <= N; i++) {
		if (mx[i] <= 0) return !printf("-1\n");
		if (ans[i] && ans[i] > mx[i]) return !printf("-1\n");
	}

	for (i = 1; i <= N; i++) inc[i] = conn[i].size();
	for (i = 1; i <= N; i++) if (inc[i] == 0) Sx2.emplace(mn[i], i);

	for (i = 1; i <= K; i++) {
		while (!Sx2.empty()) {
			if (Sx2.begin()->first != i) break;
			int t = Sx2.begin()->second;
			Sx2.erase(Sx2.begin());
			Sx1.emplace(mx[t], t);
		}
		if (Sx1.empty()) return !printf("-1\n");

		auto it = Sx1.begin();
		Vl.push_back(it->second);
		ans[it->second] = i;
		Sx1.erase(it);
		while (!Sx1.empty()) {
			if (Sx1.begin()->first != i) break;
			int t = Sx1.begin()->second;
			Sx1.erase(Sx1.begin());
			ans[t] = i;
			Vl.push_back(t);
		}
		propagate();
	}
	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	return !printf("\n");
}