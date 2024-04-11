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

string f(const string & s) {
    if (s.size() % 2) return s;
    int n = s.size();
    string s1 = f(s.substr(n/2, n/2));
    string s2 = f(s.substr(0, n/2));
    for (int i = 0; i < n/2; ++i) {
        if (s1[i] < s2[i]) break;
        if (s1[i] > s2[i]) {
            s1.swap(s2);
            break;
        }
    }
    return s1 + s2;
}

int main() {
    string a, b;
    cin >> a >> b;
//    cerr << f(a) << ' ' << f(b) << endl;
    if (f(a) == f(b)) {
        cout << "YES\n";
    } else cout << "NO\n";
    return 0;
}