#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <string.h>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <complex>
#include <cassert>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

#define NAME "a"
//~ #undef NAME
#ifndef NAME
    #error "Write problem name"
#endif

char s[1000001];
char a[1000001];
int m;

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s);
    m = 0;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
        if (m && a[m - 1] == s[i])
            --m;
        else
            a[m++] = s[i];
    }
    cout << (!m ? "YES\n" : "NO\n");
}