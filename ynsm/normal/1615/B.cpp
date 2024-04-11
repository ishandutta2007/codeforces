#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int LOG = 20, N = 200500, inf = 1e9;


int pre[LOG][N];
void solve () {
    int l, r;
    scanf ("%d%d", &l, &r);
    int ans = inf;
    for (int i = 0; i < LOG; i++)
        ans = min (ans, r - l + 1 - pre[i][r] + pre[i][l - 1]);
    printf ("%d\n", ans);
}
int main () {
    for (int i = 0; i < LOG; i++) {
        for (int j = 1; j < N; j++) {
            pre[i][j] = pre[i][j - 1];
            if ((j >> i) & 1)
                pre[i][j]++;
        }
    }
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve ();
}