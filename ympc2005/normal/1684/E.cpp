#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 4e5 + 10;

int n, m, a[N], b[N], T, f[N], g[N];

map <int, int> mp;

int main() {
    cin>>T;

    while (T--) {
        cin>>n>>m;

        for (int i = 0; i <= n*2 + 10; i++) {
            b[i] = 0;
        }

        mp.clear();
        int id = n;

        for (int i = 1; i <= n; i++) {
            cin>>a[i];

            if (a[i] <= n) {
                b[a[i]]++;
            } else {
                if (!mp.count(a[i])) {
                    mp[a[i]] = ++id;
                }

                b[mp[a[i]]]++;
            }
        }

        priority_queue <int> mx;
        int cnt = 0, sum = 0;
        g[id + 1] = 0;

        for (int i = id; i >= 0; i--) {
            if (b[i]) {
                sum += b[i];
                mx.push(b[i]);

                while (sum > m) {
                    sum -= mx.top();
                    mx.pop();
                    cnt++;
                }
            }

            f[i] = cnt;
            g[i] = min(m, g[i + 1] + b[i]);
        }

        int ans = 1e9, cur = 0, tmp = 0;

        for (int i = 0; i <= n; i++) {
            if (min(g[i] + tmp, m) < cur) {
                break;
            }

            ans = min(ans, f[i]);
            cur += !b[i];
            tmp += max(b[i] - 1, 0);
        }

        printf("%d\n", ans);
    }
}