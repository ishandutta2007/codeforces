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
    char s[10];
    ll a = 1, b = 1;
    for (int i = 0; i < n; ++i) {
        scanf("%s", s);
        if (strlen(s) == 4) {
            ++a; ++b;
        } else if (s[0] == 'U') {
            if (s[1] == 'R')
                ++a;
            else ++b;
        } else {
            if (s[1] == 'L')
                ++a;
            else ++b;
        }
    }
    cout << a * b << endl;
    return 0;
}