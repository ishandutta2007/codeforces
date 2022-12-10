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

int r[100050];
int root(int x) {
	return (x == r[x]) ? x : (r[x] = root(r[x]));
}

char in[100050];
int sa[18][300000];
int lcp(int a, int b) {
	int rv = 0, i;
	for (i = 17; i >= 0; i--) {
		if (sa[i][a] == sa[i][b]) {
			rv += 1 << i;
			a += 1 << i;
			b += 1 << i;
		}
	}
	return rv;
}


int rsa[100050];
int u[100050];
int u2[100050];
int pos[100050];
int L[100050];
int cnt[100050];

vector <pair<int, pii>> Vq;
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", in);

		int N = strlen(in), i, j, k;
		for (i = 0; i < N; i++) u[i] = u2[i] = i;
		sort(u, u + N, [](int a, int b) {
			return in[a] < in[b];
		});
		for (i = 0, j = 0; i < N; i++) {
			if (!i || in[u[i]] != in[u[i-1]]) j++;
			sa[0][u[i]] = j;
		}
		for (i = 1; i <= 17; i++) {
			for (j = 0; j <= N; j++) pos[j] = 0;
			for (j = 0; j < N; j++) pos[sa[i - 1][j + (1 << (i - 1))]]++;
			for (j = 1; j <= N; j++) pos[j] += pos[j - 1];
			for (j = N - 1; j >= 0; j--) u[--pos[sa[i - 1][j + (1 << (i - 1))]]] = j;

			for (j = 0; j <= N; j++) pos[j] = 0;
			for (j = 0; j < N; j++) pos[sa[i - 1][j]]++;
			for (j = 1; j <= N; j++) pos[j] += pos[j - 1];
			for (j = N - 1; j >= 0; j--) u2[--pos[sa[i - 1][u[j]]]] = u[j];
			for (j = 0, k = 0; j < N; j++) {
				if (!j || sa[i - 1][u2[j]] != sa[i - 1][u2[j - 1]] ||
					sa[i - 1][u2[j] + (1 << (i - 1))] != sa[i - 1][u2[j - 1] + (1 << (i - 1))]) k++;
				sa[i][u2[j]] = k;
			}
		}
		for (i = 0; i < N; i++) rsa[sa[17][i] - 1] = i;
		for (i = 0; i + 1 < N; i++) Vq.emplace_back(lcp(rsa[i], rsa[i + 1]), pii(i, i + 1));
		sort(all(Vq), [](auto a, auto b) {
			return a.first > b.first;
		});
		for (i = 0; i < N; i++) {
			r[i] = i;
			L[i] = N - rsa[i];
			cnt[i] = 1;
		}
		
		ll ans = 0;
		for (auto u : Vq) {
			int l = u.first, x = u.second.first, y = u.second.second;
			x = root(x), y = root(y);
			ans += (ll)cnt[x] * cnt[x] * (L[x] - l);
			ans += (ll)cnt[y] * cnt[y] * (L[y] - l);

			r[x] = y;
			cnt[y] += cnt[x];
			L[y] = l;
		}
		ans += (ll)L[root(1)] * N * N;
		printf("%lld\n", ans);

		Vq.clear();

		memset(sa, 0, sizeof(sa));
	}
	return 0;
}