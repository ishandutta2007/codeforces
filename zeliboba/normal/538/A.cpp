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
    string s; cin >> s;
    string f = "CODEFORCES";
    for (int i = 0; i < s.size(); ++i) for (int j = i; j <= s.size(); ++j) {
        if (s.substr(0, i) + s.substr(j, s.size() - j) == f) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}