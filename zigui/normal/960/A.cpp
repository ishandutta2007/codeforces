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

const int MX = 100005;

int main()
{
	string A;
	cin >> A;
	int a = 0, b = 0, c = 0, ch = 1;
	for(char v : A){
		if(v == 'a'){
			if(b || c) ch = 0;
			a++;
		}
		if(v == 'b'){
			if(c) ch = 0;
			b++;
		}
		if(v == 'c') c++;
	}
	if(c != a && c != b) ch = 0;
	if(a <= 0 || b <= 0) ch = 0;
	printf("%s\n", ch?"YES":"NO");
}