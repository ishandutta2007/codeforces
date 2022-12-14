#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <utility>
#include <random>
#include <chrono>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#include <bitset>
#include <complex>
using namespace std;

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
uniform_real_distribution<double> unif(0,1);

const double p = 1. / 1.3;
double P[20000];
string s;
int main( ) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    P[0] = 1;
    for (int i = 1; i < 20000; i++) {
        P[i] = P[i - 1] * p;
    }
    int n, m; cin >> n >> m;
    vector<int> mistake(n);
    int minMistake = 0;
    for (int i = 0; i < m; i++) {
        cin >> s;
        double score = 0;
        minMistake = m + 1;
        for (int j = 0; j < n; j++) {
            minMistake = min(minMistake, mistake[j]);
        }
        for (int j = 0; j < n; j++) {
            score += P[mistake[j] - minMistake];
        }
        double score1 = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == '1') {
                score1 += P[mistake[j] - minMistake];
            }
        }
        double r = unif(rng);
        if (r <= score1 / score) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
        int a;
        cin >> a;
        for (int j = 0; j < n; j++) {
            if (a != s[j] - '0') {
                mistake[j]++;
            }
        }
    }
}