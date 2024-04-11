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

const int MX = 200005;
const int MM = 1000000007;

struct finwick{
	vector<int> t, X;
	void init(){
		sort(X.begin(), X.end());
		X.resize(unique(X.begin(), X.end()) - X.begin());
		t.resize(X.size(), 0);
	}
	void update(int x, int v){
		x = lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
		while(x < t.size()){
			t[x] = max(t[x], v);
			x += x&-x;
		}
	}
	int read(int x){
		x = lower_bound(X.begin(), X.end(), x) - X.begin();
		int c = 0;
		while(x){
			c = max(c, t[x]);
			x -= x&-x;
		}
		return c;
	}
} T[MX];

vector<int> G[MX];
t3 E[MX];

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		E[i] = t3(a, b, c);
		T[b].X.push_back(c);
		T[a].X.push_back(c);
	}
	for(int i = 1; i <= N; i++) T[i].init();

	int ans = 0;
	for(int i = 1; i <= M; i++){
		int a, b, c;
		tie(a, b, c) = E[i];
		int v = T[a].read(c) + 1;
		ans = max(ans, v);
		T[b].update(c, v);
	}
	printf("%d\n", ans);
}