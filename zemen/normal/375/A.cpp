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

int a[7] = {1869, 1968, 6918, 6891, 8691, 1986, 1896};
int d[6] = {1, 3, 2, 6, 4, 5};

char s[2000001];
int cnt[100];
char res[2000001];

int main() {
    #ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    #endif
    gets(s);
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
        cnt[s[i] - '0']++;
    cnt[1]--;
    cnt[6]--;
    cnt[8]--;
    cnt[9]--;
    int c = 0;
    int m = 0;
    for (int i = 0; i < 10; ++i)
        for (int j = 0; j < cnt[i]; ++j) {
            m += i * d[c % 6];
            m %= 7;
            res[c++] = i + '0';
        }
    reverse(res, res + c);
    res[c] = 0;
    for (int i = 0; i < 7; ++i) {
        if ((a[i] * d[c % 6] + m) % 7 == 0) {
            cout << a[i];
            printf("%s\n", res);
            return 0;
        }
    }
}