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
#include <queue>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n;
    string s;
    cin >> n >> s;
    for (int d = 1; d <= n; ++d) {
        for (int i = 0; i < n; ++i) if (i + 4*d < n && s[i] == '*' && s[i+d] == '*' && s[i+2*d] == '*' && s[i+3*d] == '*' && s[i+4*d] == '*') {
            cout << "yes\n";
            return 0;
        }
    }
    cout << "no\n";
    return 0;
}