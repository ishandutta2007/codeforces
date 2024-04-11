#include <bits/stdc++.h>
using namespace std;

int T, n;
string s;
bool pr[110];

int main() {
    ios::sync_with_stdio(0);
    fill(pr + 2, pr + 101, 1);
    for (int i = 2; i <= 100; i++) if (pr[i]) {
        for (int j = i + i; j <= 100; j += i) pr[j] = 0;
    }
    cin >> T;
    while (T--) {
        cin >> n >> s;
        bool flag = 0;
        for (int i = 0; i < n; i++) if (!pr[s[i] - '0']) {
            printf("1\n%d\n", s[i] - '0');
            flag = 1; break;
        }
        if (!flag) {
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int x = (s[i] - '0') * 10 + s[j] - '0';
                    if (!pr[x]) { printf("2\n%d\n", x); goto nxt; }
                }
            }
            assert(0);
            nxt:;
        }
    }
    return 0;
}