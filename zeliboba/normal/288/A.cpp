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
    int n, k;
    cin >> n >> k;
    if (n < k || (k==1 && n > 1)) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) s[i] = 'a';
        else s[i] = 'b';
    }
    for (int i = 0; i < k-2; ++i)
        s[n-1-i] = 'a'+k-1-i;
    s[n] = '\0';
    printf("%s\n", s);
    return 0;
}