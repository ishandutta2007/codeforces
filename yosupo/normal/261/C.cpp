#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>

using namespace std;

typedef long long ll;

ll comb(int n, int k) {
    if (n < k) return 0;
    ll result = 1;
    for (int i = 1; i <= k; i++) {
        result *= n - i + 1;
        result /= i;
    }
    return result;
}

ll N;
ll solve(bool near, int m, int c) {
    if (!c) return 1;
    if (!m) return 0;
    if (near) {
        if (N & (1LL << (m-1))) {
            return solve(true, m-1, c-1) + solve(false, m-1, c);
        } else {
            return solve(true, m-1, c);
        }
    } else {
        return comb(m, c);
    }
}

int main(int argc, char *argv[]) {
    ll M;
    cin >> N >> M;
    N++;
    int n;
    ll d;
    for (n = 0, d = 1; d < M; n++, d *= 2);
    if (d != M) {
        printf("0\n");
        return 0;
    }
    ll res = solve(true, 60, n+1);
    if (M == 1) res--;
    cout << res << endl;
    return 0;
}