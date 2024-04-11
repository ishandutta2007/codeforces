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

int main() {
    int n;
    cin >> n;
    vi s(n);
    vi prev(n), next(n);
    vii ord(n);
    for (int i = 0; i < n; ++i) {
        prev[i] = i - 1;
        next[i] = i + 1;
        scanf("%d", &s[i]);
        ord[i].first = s[i];
        ord[i].second = i;
    }
    prev[0] = next.back() = -1;
    sort(ord.begin(), ord.end());
    int ma = 0; 
    for (int i = 0; i < n; ++i) {
        int pos = ord[i].second;
        int pr = prev[pos], nx = next[pos];
        if (pr != -1) {
            ma = max(ma, s[pos]^s[pr]);
            next[pr] = nx;
        }
        if (nx != -1) {
            ma = max(ma, s[pos]^s[nx]);
            prev[nx] = pr;
        }
    }
    cout << ma << endl;
    return 0;
}