#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <sstream>
#include <typeinfo>
#include <queue>
#include <stack>
#include <tuple>

using namespace std;


typedef long long ll;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;

const int MAX_N = 3010;
int n, k;
int p[MAX_N], kill[MAX_N];
bool dp[MAX_N+1][MAX_N+2] = {};

int main(int argc, char *argv[]) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int d;
        scanf("%d", &d);
        if (d == 0) p[i] = 1;
        else if (d == 100) p[i] = 2;
        else p[i] = 3;
    }
    p[n] = 0;
    for (int i = n-1; i >= 0; i--) {
        if (p[i] == 2 || kill[i+1] == 2) {
            kill[i] = 2;
        } else {
            kill[i] = max(kill[i+1], p[i]);
        }
    }

    queue<T> q;
    q.push(T(0, 1, k));
    int res = 0;
    while (!q.empty()) {
        T t = q.front(); q.pop();
        int a = get<0>(t), b = get<1>(t), c = get<2>(t);
        if (b > n+1) continue;
        if (dp[a][b]) continue;
        dp[a][b] = true;
        res += 1;
        if (!c) continue;

        if (kill[b] & 0x01) {
            if (p[a] & 0x01) {
                q.push(T(a, b, c-1));
            }
            if (p[a] & 0x02) {
                q.push(T(a, b+1, c-1));
            }
        }
        if (kill[b] & 0x02) {
            if (p[a] & 0x01) {
                q.push(T(b, b+1, c-1));
            }
            if (p[a] & 0x02) {
                q.push(T(b+1, b+2, c-1));
            }
        }
    }
    cout << res << endl;
    return 0;
}