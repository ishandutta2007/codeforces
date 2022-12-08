#include <stdio.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
#define rep(i, n) for(int i=0;i<n;i++)
#define pb(x) push_back(x)
#define all(x) (x).begin(), (x).end()
#define szz(x) (int)(x).size()
#define Fi first
#define Se second

const int INF = 0x3f3f3f3f;
const ll LL_INF = 0x3f3f3f3f;
const ll MOD = 1000000007;
const int IT_MAX = 1 << 17;

const int MX = 1000005;

int in[500050];
int sum[500050];

int dp[500050];
int tdp[500050];
int main() {
    int N, K, P, i, j;
    scanf("%d %d %d", &N, &K, &P);
    for(i = 1; i <= N; i++) {
        scanf("%d", &in[i]);
        sum[i] = (sum[i-1] + in[i]) % P;
    }

    dp[0] = 0;
    for(i = 1; i <= N; i++) dp[i] = INF;
    for(i = 1; i <= K; i++) {
        for(j = 0; j <= N; j++) tdp[j] = INF;

        int mn = dp[0], v = 0;
        for(j = 1; j <= N; j++) {
            tdp[j] = mn;
            if(v > sum[j]) tdp[j]++;

            if(mn > dp[j] || (mn == dp[j] && v > sum[j])) {
                mn = dp[j];
                v = sum[j];
            }
        }
        for(j = 0; j <= N; j++) dp[j] = tdp[j];
    }
    return !printf("%d\n", dp[N] * P + sum[N]);
}