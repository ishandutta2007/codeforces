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
int MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define rep(i, n) for(int i=0;i<n;i++)
#define Se second
#define Fi first

const int MX = 2600 * 2;
const int MM = 1000000007;

vector<int> ans, cur;
void solve(vector<int> &L, int m = 1){
	if(cur.size() >= 20 ) return;
//	for(int c : L) fprintf(stderr, "%d ", c); fprintf(stderr, "\n");
	if(L.size() == 0){
		if(ans.empty() || cur.size() < ans.size()) ans = cur;
		return;
	}
	bool ch = 0;
	for(int c : L){
		if((c&1) == 1) ch = 1;
	}
	if(!ch){
		vector<int> nxt;
		for(int c : L) nxt.push_back(c/2);
		solve(nxt, m*2);
		return;
	}
	for(int flag = -1; flag <= 1; flag += 2){
		vector<int> nxt;
		for(int c : L){
			int v;
			if(c&1) v = (c-flag)/2;
			else v = c/2;
			if(v && (nxt.empty() || nxt.back() != v)) nxt.push_back(v);
		}
		cur.push_back(m*flag);
		solve(nxt, m*2);
		cur.pop_back();
	}
}

int main()
{
	int N;
	vector<int> L;
	scanf("%d", &N);
	for(int i = 1; i <= N; i++){
		int a;
		scanf("%d", &a);
		if(a) L.push_back(a);
	}
	sort(L.begin(), L.end());
	solve(L);
	printf("%d\n", ans.size());
	for(int c : ans) printf("%d ", c);
	printf("\n");
}