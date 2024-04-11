#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <complex>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

char b[100005];

int main() {
    scanf("%s", b);
    int n = strlen(b);
    bool was = 0;
    for (int i = 0; i + 1 < n; ++i) {
        if (b[i] == '0')
            was = 1;
        if (was)
            b[i] = b[i + 1];
        printf("%c", b[i]);
    }
    printf("\n");
    return 0;
}