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

int main()
{
	set<int> X;
	int N, K;
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++){
		int a, b = 0;
		for(int j = 0; j < K; j++){
			scanf("%d", &a);
			b = b*2 + a;
		}
		X.insert(b);
	}
	for(int c : X){
		for(int d : X){
			if( (c&d) == 0 ) return !printf("YES\n");
		}
	}
	printf("NO\n");
}