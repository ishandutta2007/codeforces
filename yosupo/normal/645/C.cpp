#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

const int MN = 100100;

int n, k;
int d[MN] = {}, sm[MN];

bool calc(int md) {
    for (int i = 0; i < n; i++) {
        if (d[i] == 0) continue;
        int l = max(i-md, 0);
        int r = min(i+1+md, n);
        int s = sm[r]-sm[l];
        if (k <= s) return true;
    }
    return false;
}
int main() {
    string s;
    cin >> n >> k; k++;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') continue;
        d[i] = 1;
    }
    for (int i = 0; i < n; i++) {
        sm[i+1] = sm[i]+d[i];
    }
    int l = 0, r = n+1;
    while (r-l > 1) {
        int md = (l+r)/2;
        if (!calc(md)) {
            l = md;
        } else {
            r = md;
        }
    }
    cout << r << endl;
    return 0;
}