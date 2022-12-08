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
	char A[10];
	char D[100][10];

	int N;
	scanf("%s%d", A, &N);
	for(int i = 1; i <= N; i++){
		scanf("%s", D[i]);
	}
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			if( A[0] == D[i][1] && A[1] == D[j][0] ) return !printf("YES\n");
		}
	}
	for(int i = 1; i <= N; i++){
		if( A[0] == D[i][0] && A[1] == D[i][1] ) return !printf("YES\n");
	}
	printf("NO\n");
}