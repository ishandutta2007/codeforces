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
    int k;
    cin >> k;
    const int n = 1000;
    const int p2 = 30;
    char m[n][n+1];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) m[i][j] = 'N';
        m[i][n] = '\0';
    }
    int cur = 2;
    for (int i = 0; i < p2-1; ++i) {
        for (int a = 0; a < 2; ++a) for (int b = 0; b < 2; ++b)
            m[cur+2*i+a][cur+2*i+2+b] = 'Y';
    }
    cur += 2*p2;
    m[cur-1][1] = m[cur-2][1] = 'Y';
    for (int i = 0; i < p2+1; ++i) if (k & (1 << i)) {
        m[0][cur] = 'Y';
        int cnt = p2 - i;
        for (int j = 0; j < cnt; ++j) {
            m[cur+j][cur+j+1] = 'Y';
        }
        if (i == 0) {
            m[cur+cnt][1] = 'Y';
        } else {
            m[cur+cnt][2+2*(p2-i)] = 'Y';
            m[cur+cnt][2+2*(p2-i)+1] = 'Y';
        }
        cur += cnt + 1;
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (m[i][j] == 'Y')
        m[j][i] = 'Y';
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        printf("%s\n", m[i]);
    }
    return 0;
}