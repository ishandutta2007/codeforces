#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = (int)2e5 + 123, inf = 1e9, mod = 1e9 + 7;
const ll INF = 1e18;

char s[N], t[N];
int n, cnt[2][2];
int ans;

void solve () {
    scanf("%d", &n);
    scanf ("%s", s);
    scanf ("%s", t);

    cnt[0][0] = cnt[0][1] = 0;
    cnt[1][0] = cnt[1][1] = 0;


    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        int y = t[i] - '0';
        cnt[x][y]++;
    }

    ans = inf;

    if (cnt[1][0] == cnt[0][1])
        ans = min (ans, cnt[1][0] + cnt[0][1]);

    for (int i = 0; i < n; i++) {
        int x = s[i] - '0';
        int y = t[i] - '0';
        if (x == 0)
            continue;
        cnt[x][y]--;
        swap (cnt[0][0], cnt[1][0]);
        swap (cnt[0][1], cnt[1][1]);
        cnt[x][y]++;

        if (cnt[1][0] == cnt[0][1])
            ans = min (ans, cnt[1][0] + cnt[0][1] + 1);

        cnt[x][y]--;
        swap (cnt[0][0], cnt[1][0]);
        swap (cnt[0][1], cnt[1][1]);
        cnt[x][y]++;
    }

    if (ans == inf)
        ans = -1;

    printf ("%d\n", ans);
}
int main () {
    int t = 1;
    scanf ("%d", &t);
    while (t--)
        solve ();
}