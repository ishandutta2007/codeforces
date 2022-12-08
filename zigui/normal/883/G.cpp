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

int IT_MAX = 1 << 19;
const ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x1f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-12;

class edge {
public:
	int s, e, t;
	int dir; // 0 : s->e, 1:e->s;
	edge() {
		*this = edge(0, 0, 0);
		dir = -1;
	}
	edge(int s, int e, int t) :s(s), e(e), t(t) {
		dir = -1;
	}
};
vector <edge> Ve;
vector <int> conn[300050];
void epush(int s, int e, int t) {
	conn[s].push_back(Ve.size());
	if (t == 2) conn[e].push_back(Ve.size());
	Ve.emplace_back(s, e, t);
}

bool dchk[300050];
void DFS(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		int s = Ve[it].s, e = Ve[it].e, t = Ve[it].t;
		if (t == 2) {
			if (Ve[it].dir == 1 && n == s) continue;
			if (Ve[it].dir == 0 && n == e) continue;
			if (s != n) swap(s, e);
		}
		if (dchk[e]) continue;
		if (t == 2) {
			if (Ve[it].e == n) Ve[it].dir = 1;
			else Ve[it].dir = 0;
		}
		DFS(e);
	}
}

void DFS2(int n) {
	dchk[n] = true;
	for (auto it : conn[n]) {
		if (Ve[it].t == 2) continue;
		int s = Ve[it].s, e = Ve[it].e;
		if (dchk[e]) continue;
		DFS2(e);
	}
}
int main() {
	int N, M, S, i;
	scanf("%d %d %d", &N, &M, &S);
	for (i = 1; i <= M; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		epush(t2, t3, t1);
	}

	// Max
	DFS(S);
	int c = 0;
	for (i = 1; i <= N; i++) if (dchk[i]) c++;
	printf("%d\n", c);
	for (auto it : Ve) {
		if (it.t == 1) continue;
		if (it.dir == 1) printf("-");
		else printf("+");
	}
	printf("\n");

	// Min
	for (i = 1; i <= N; i++) dchk[i] = false;
	for (auto &it : Ve) it.dir = -1;
	DFS2(S);
	c = 0;
	for (i = 1; i <= N; i++) if (dchk[i]) c++;
	printf("%d\n", c);
	for (auto it : Ve) {
		if (it.t == 1) continue;
		if (dchk[it.s]) printf("-");
		else printf("+");
	}
	return !printf("\n");
}