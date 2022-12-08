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

void make(int P, int A[]) {
	rep(i, 250) {
		A[i] = rand() % (2 * P + 1) - P;
	}
}

double X[51][255];

void poisson(int P, int A[], int t) {
	double pos[10001] = {};
	double r = 1;
	for (int k = 0;k <= 10000; k++) {
		if(k) r = r * k;
		pos[k] = exp(-P) * pow(P, k) / r;
	}
	if(P <= 50 && t) for (int k = 0; k <= 100; k++) X[P][k] = pos[k];
	rep(i, 250) {
		double pp = (double)rand() / RAND_MAX;
		int f = -1;
		for (int j = 0; j <= 10000; j++) {
			if (pp <= pos[j]) { f = j; break; }
			else pp -= pos[j];
		}
		A[i] = f - P;
	}
}

double get(int P, int x){
	x += P;
	if(x < 0) return 0;
	return X[P][x];
}

void Do(int x, int y) {
	int A[255] = {};
	rep(i, 250) scanf("%d", A + i);
	
	//scanf("%d%d", &x, &y);
//	if(x == 0) make(y, A);
//	else poisson(y, A, 0);
	
	//	int n; scanf("%d", &n);
	//	make(n, A);
	//	int n; scanf("%d", &n);
	//	poisson(20, A);
	//	make(25, A);
	
	int t = *max_element(A, A + 250) - *min_element(A, A + 250);
	
	if(t == 2){ puts("uniform"); return; }
	
	int temp[10010] = {};
	int *B = temp + 5050;
	rep(i, 250) B[A[i]]++;
	if (t <= 20) {
		double xx[11] = {};
		if(t&1)++t;
		int tt = t / 2;
		for(int i=-tt;i<=tt;i++) xx[0] += (250.0 / (t+1) - B[i]) * (250.0 / (t+1) - B[i]);
		for (int P = 1; P <= 15; P++) {
			double rr = 0;
			for(int i=-20;i<=20;i++) rr += (B[i] - get(P, i)) * (B[i] - get(P, i));
			//printf("%f\n", rr);
			xx[P] = rr;
			//mn = min(mn, rr);
		}
		int a = (int)(min_element(xx, xx+16) - xx);
		if (a != 0) puts("poisson");
		else puts("uniform");
		return;
	}
	int a = 0, b = B[0];
	while(1){
		if(b >= 125) break;
		++a; b += B[a] + B[-a];
	}
	double C = 2 * a / (double)t;
	if(C < 0.35) puts("poisson");
	else puts("uniform");
}

int main() {
	
	for (int P = 1; P <= 35; P++) {
		int temp[300] = {};
		poisson(P, temp, 1);
		for (int i = 0; i <= 100; i++) X[P][i] *= 250;
	}
	int V; V = 1000; scanf("%d", &V);
	int x, y;// scanf("%d%d", &x, &y);
	while (V--) {
		Do(x, y);
	}
	return 0;
}