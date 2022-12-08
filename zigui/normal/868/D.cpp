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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const int L = 1<<17;

set<int> X[205];
string A[205], B[205];

int main()
{
	int N, M;
	scanf("%d", &N);
	for(int t = 1; t <= N; t++){
		string P;
		cin >> P;
		for(int i = 0; i < P.size(); i++){
			int k = 1;
			for(int j = i; j < P.size(); j++){
				k = k*2 + P[j] - '0';
				if( k >= L ) break;
				X[t].insert(k);
			}
		}
		A[t] = P.substr(0, min(16, (int)P.size()));
		B[t] = P.substr(max(0, (int)P.size() - 16), -1);
	}
	scanf("%d", &M);
	for(int t = N+1; t <= M+N; t++){
		int a, b;
		scanf("%d%d", &a, &b);
		string P = B[a], Q = A[b], R = B[a] + A[b];
		for(int i = 0; i < R.size(); i++){
			int k = 1;
			for(int j = i; j < R.size(); j++){
				k = k*2 + R[j] - '0';
				if( k >= L ) break;
				X[t].insert(k);
			}
		}
		for(int c : X[a]) X[t].insert(c);
		for(int c : X[b]) X[t].insert(c);

		if( P.size() <= 16 ){
			string tt = A[a] + A[b];
			A[t] = tt.substr(0, min(16, (int)tt.size()));
		}
		if( Q.size() <= 16 ){
			string tt = B[a] + B[b];
			B[t] = tt.substr(max(0, (int)tt.size()-16), -1);
		}
	}
	for(int i = N+1; i <= N+M; i++){
		auto it = X[i].begin();
		int t = 2;
		for(t = 2; it != X[i].end(); t++, it++){
			if( *it != t ) break;
		}
		int ans = 0;
		while(t >= 1<<ans+2) ans++;
		printf("%d\n", ans);
	}
}