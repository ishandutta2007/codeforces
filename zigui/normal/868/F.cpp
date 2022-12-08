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

const int L = 1<<16;
const int MX = 100005;

int N, K;
int D[MX];
ll T[21][MX];

int state[MX];
ll v = 0;
int l = 1, r = 0;
ll get_value(int s, int e){
	while(l < s) state[D[l]]--, v -= state[D[l]], l++;
	while(l > s) l--, v += state[D[l]], state[D[l]]++;

	while(r < e) r++, v += state[D[r]], state[D[r]]++;
	while(r > e) state[D[r]]--, v -= state[D[r]], r--;
	return v;
}

void DnC(int s, int e, int l, int r, ll S[MX], ll E[MX])
{
	if( l > r ) return;
	int m = (l+r) / 2, v = m;
	for(int i = s; i <= e && i <= m; i++){
		if( S[i-1] + get_value(i, m) < E[m] ){
			v = i;
			E[m] = S[i-1] + get_value(i, m);
		}
	}
	DnC(s, v, l, m-1, S, E);
	DnC(v, e, m+1, r, S, E);
}

int main()
{
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++){
		scanf("%d", D+i);
	}
	for(int i = 1; i <= N; i++) T[1][i] = get_value(1, i);
	for(int k = 2; k <= K; k++){
		for(int i = 1; i <= N; i++) T[k][i] = 1e18;
		DnC(1, N, 1, N, T[k-1], T[k]);
	}
	printf("%lld\n", T[K][N]);
}