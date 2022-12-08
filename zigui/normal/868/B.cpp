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
	int A, B, C, D, E;
	scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
	A %= 12, D %= 12, E %= 12;
	D *= 2, E *= 2;
	vector<int> X;
	X.push_back(A*2 + 1);
	X.push_back(B/5*2+1);
	X.push_back(C/5*2+1);
	if( D > E ) swap(D, E);

	int ch = 0;
	for(int c : X) if( D <= c && c <= E ) ch |= 1;
	for(int c : X) if( c <= D || E <= c ) ch |= 2;
	if( ch == 3 ) printf("NO\n");
	else printf("YES\n");
}