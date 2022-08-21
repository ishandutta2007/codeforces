#include <vector>
#include <iostream>
#include <set>
#include <cstdio>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <complex>
#include <algorithm>
#include <tuple>
#include <algorithm>
#include <limits>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

template <int N>
struct Primes {
    bool used[N] = {};
    std::vector<int> primes;
    Primes() {
        for (int i = 2; i < N; i++) {
            if (!used[i]) {
                primes.push_back(i);
            }
            for (int j = i; j < N; j += i) {
                used[j] = true;
            }
        }
    }
};

Primes<59> p;
const int MP = 59;
const int PS = 16;

int b[MP];
int n;
int d[110];


int dp[110][1<<PS];

int sol(int i, int bu) {
    if (i == n) return 0;
    if (dp[i][bu] != -1) return dp[i][bu]; 
    int r = 1000000;
    for (int j = 1; j < MP; j++) {
        if (!(b[j] & bu)) {
            r = min(r, sol(i+1, bu | b[j]) + abs(d[i]-j));
        }
    }
    dp[i][bu] = r;
    return r;
}

vector<int> res;
void rec(int i, int bu) {
    if (i == n) return;
    for (int j = 1; j < MP; j++) {
        if (!(b[j] & bu)) {
            if (dp[i][bu] == sol(i+1, bu | b[j]) + abs(d[i]-j)) {
                res.push_back(j);
                rec(i+1, bu | b[j]);
                break;
            }
        }        
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i < MP; i++) {
        for (int j = 0; j < PS; j++) {
            if (!(i%p.primes[j])) {
                b[i] |= 1<<j;
            }
        }
    }
    fill_n(dp[0], 110*(1<<PS), -1);
    sol(0, 0);
    rec(0, 0);
    for (int i = 0; i < n-1; i++) {
        printf("%d ", res[i]);
    }
    printf("%d\n", res[n-1]);
    return 0;
}