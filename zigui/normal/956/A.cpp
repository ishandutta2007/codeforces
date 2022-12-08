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
ll MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f3f3f3f3f;
const db PI = acos(-1);
const db ERR = 1e-10;
#define szz(x) (int)(x).size()
#define Se second
#define Fi first
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)

const int MX = 105;
const int MM = 1000000007;

char D[MX][MX];
int N, M;
vector<int> R, C;
int vst[2][MX];

void dfs(int x, int flag)
{
	if(vst[flag][x]) return;
	vst[flag][x] = 1;
	if(!flag){
		R.push_back(x);
		for(int i = 1; i <= M; i++){
			if( D[x][i] == '#') dfs(i, !flag);
		}
	}
	else{
		C.push_back(x);
		for(int i = 1; i <= N; i++){
			if( D[i][x] == '#') dfs(i, !flag);
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) scanf("%s", D[i]+1);
	for(int i = 1; i <= N; i++){
		R.clear(); C.clear();
		dfs(i, 0);
		for(int c : R){
			for(int d : C){
				if( D[c][d] != '#') return !printf("No\n");
				D[c][d] = '.';
			}
		}
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= M; j++){
			if(D[i][j] == '#') return !printf("No\n");
		}
	}
	printf("Yes\n");
}