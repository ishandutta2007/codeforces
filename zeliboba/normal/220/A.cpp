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
    vi a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vi b = a;
    sort(b.begin(), b.end());
    int cnt = 0;
    for (int i = 0; i < n; ++i) if (a[i] != b[i])
        ++cnt;
    if (cnt <= 2) cout << "YES\n";
    else cout << "NO\n"; 
    return 0;
}