#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
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

char s[30005][25];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        scanf("%s", s[i]);
    int ans = 0;
    int k = strlen(s[0]);
    for (int i = 0; i < k; ++i) {
        bool ok = 1;
        for (int j = 0; j < n; ++j) if (s[j][i] != s[0][i])
            ok = 0;
        if (!ok) {
            cout << i << endl;
            return 0;
        }
    }
    cout << k << endl;
    return 0;
}