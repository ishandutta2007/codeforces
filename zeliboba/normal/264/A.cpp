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
char s[1000005];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    vi b, e;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'l')
            e.push_back(i + 1);
        else b.push_back(i + 1);
    }
    for (int i = 0; i < b.size(); ++i)
        printf("%d\n", b[i]);
    for (int i = (int)e.size() - 1; i >= 0; --i)
        printf("%d\n", e[i]);
    return 0;
}