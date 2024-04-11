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
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int n;
    char s[100005];
    scanf("%s", s);
    n = strlen(s);
    int n0 = 0, n1 = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0')
            ++n0;
        else if (s[i] == '1')
            ++n1;
    }
    if (2 * n1 < n)
        cout << "00\n";
    if (2 * n0 <= n && 2 * n1 <= n + 1) {
        if (s[n - 1] == '1' || s[n - 1] == '?' && 2 * n1 < n)
            cout << "01\n";
        if (s[n - 1] == '0' || s[n - 1] == '?' && 2 * n0 < n - 1)
            cout << "10\n";
    }
    if (2 * n0 < n - 1)
        cout << "11\n";
    return 0;
}