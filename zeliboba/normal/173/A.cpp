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

int v(char c) {
    if (c == 'R')
        return 0;
    if (c == 'P')
        return 1;
    return 2;
}

ll b1[1000005], b2[1000005];

int main() {
    ll n, m, k;
    string s1, s2;
    cin >> n >> s1 >> s2;
    m = s1.size();
    k = s2.size();
    int i = 0;
    b1[0] = b2[0] = 0;
    for (; i < n; ++i) {
        b1[i + 1] = b1[i];
        b2[i + 1] = b2[i];
        if (i && (i % m == 0) && (i % k == 0))
            break;
        if ((v(s1[i % m]) - v(s2[i % k]) + 3) % 3 == 1)
            ++b2[i + 1];
        else if ((v(s1[i % m]) - v(s2[i % k]) + 3) % 3 == 2)
            ++b1[i + 1];
    }
    int N = n / i;
    cout << b1[n % i] + N * b1[i] << " " << b2[n % i] + N * b2[i] << endl;
    return 0;
}