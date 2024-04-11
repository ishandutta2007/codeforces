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
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;

int main() {
    int n, p;
    cin >> n >> p;
    string s; 
    cin >> s;
    if (p == 1) {
        cout << "NO\n";
        return 0;
    }
    if (p == 2) {
        if (n == 1) {
            if (s[0] == 'a') {
                cout << "b\n";
            } else {
                cout << "NO\n";
            }
        } else {
            if (s[0] == 'a') {
                cout << "ba\n";
            } else {
                cout << "NO\n";
            }
        }
        return 0;
    }
    bool ok = 0;
    for (int i = n-1; i >= 0; --i) {
        char c = s[i];
        for (char x = s[i] + 1; x < 'a' + p; ++x) {
            if (i >= 1 && x == s[i-1]) continue;
            if (i >= 2 && x == s[i-2]) continue;
            c = x;
            break;
        }
        if (c != s[i]) {
            ok = 1;
            s[i] = c;
            for (int j = i+1; j < n; ++j) {
                for (char x = 'a'; x < 'a' + p; ++x) {
                    if (j >= 1 && x == s[j-1]) continue;
                    if (j >= 2 && x == s[j-2]) continue;
                    s[j] = x;
                    break;
                }
            }
            break;
        }
    }
    if (ok) {
        cout << s << endl;
    } else {
        cout << "NO\n";
    }
    return 0;
}