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
typedef pair<int, int> P;
const int INT_INF = (1U<<31)-10000;

const int MAX_N = 100010;
int K, N, MAX_B, T;
int b[MAX_N], b_num;
int dp[MAX_N], dp_min[MAX_N];
set<int> s;

int solve() {
    fill_n(dp, MAX_N, INT_INF);
    fill_n(dp_min, MAX_N, 0);
    for (int i = 0; i < T; i++) {
        for (int j = 0; j < N; j++) {
            int d = b[j];
            while (dp[dp_min[j]] < d) dp_min[j]++;
            dp[dp_min[j]] = d;
        }
    }
    return (lower_bound(dp, dp+N, INT_INF) - dp);  
}

int main(int argc, char *argv[]) {
    cin >> K >> N >> MAX_B >> T;
    for (int k = 0; k < K; k++) {
        s.clear();
        for (int i = 0; i < N; i++) {
            scanf("%d", &(b[i]));
            b[i]--;
            s.insert(b[i]);
        }
        b_num = s.size();
        if (T >= b_num) {
            printf("%d\n", b_num);
            continue;
        }
        printf("%d\n", solve());
    }
    return 0;
}