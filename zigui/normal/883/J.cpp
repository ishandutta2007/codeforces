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

pll in1[100050];
pll in2[100050];
priority_queue <ll> Hx;
int main() {
	int N, M, i, j;
	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) scanf("%lld", &in1[i].first);
	for (i = 1; i <= M; i++) scanf("%lld", &in2[i].first);
	for (i = 1; i <= M; i++) scanf("%lld", &in2[i].second);
	sort(in2 + 1, in2 + M + 1);
	for (i = 1; i <= N; i++) in1[i].second = lower_bound(in2 + 1, in2 + M + 1, pll(in1[i].first + 1, 0)) - (in2 + 1);

	vector <pll> Vu;
	for (i = 1; i <= N; i++) {
		pll u = in1[i];
		while (!Vu.empty()) {
			if (Vu.back().second <= u.second) {
				u.first += Vu.back().first;
				Vu.pop_back();
			}
			else break;
		}
		Vu.push_back(u);
	}
	if (Vu.back().second != 0) Vu.emplace_back(0, 0);
	
	ll tot = 0, mx = 0;
	for (i = 0; i + 1 < Vu.size(); i++) {
		mx += Vu[i].first;
		int st = Vu[i + 1].second + 1, en = Vu[i].second;
		vector <ll> Vp;
		for (j = st; j <= en; j++) Vp.push_back(in2[j].second);
		sort(all(Vp));

		for(j = 0; j < Vp.size(); j++) {
			if (tot + Vp[j] <= mx) {
				tot += Vp[j];
				Hx.push(Vp[j]);
			}
			else if (!Hx.empty() && Hx.top() > Vp[j]) {
				tot -= Hx.top();
				tot += Vp[j];
				Hx.pop();
				Hx.push(Vp[j]);
			}
			else break;
		}
	}
	printf("%d\n", (int)Hx.size());
}