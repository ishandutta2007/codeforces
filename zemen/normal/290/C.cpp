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

#define INF __INT_MAX__
#define INFL __LONG_LONG_MAX__
#define pb push_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef long double ld;
typedef complex <double> point;

int main() {
    int n;
    cin >> n;
    int foo = 0;
    int bar = 0;
    int baz = 0;
    int quz = 1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        foo += a;
        ++bar;
        if (foo * quz >= bar * baz) {
            //~ cerr << "H" << '\n';
            baz = foo;
            quz = bar;
        }
        //~ cerr << foo << ' ' << bar << ' ' << baz << ' ' << quz << '\n';
    }
    cout.precision(10);
    cout.setf(ios::fixed);
    cout << double(baz) / double(quz);
}