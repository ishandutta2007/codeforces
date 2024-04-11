#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 10, b[5] = {1, 4, 6, 8, 9};

int T, n, a[10], c[N];

char s[N];

bool chk_(int x) {
    for (int i = 2; i*i <= x; i++)
        if (x%i == 0)
            return 1;
    
    return 0;
}

int main() {
    scanf("%d", &T);

    while (T--) {
        scanf("%d%s", &n, s + 1);
        memset(a, 0, sizeof(a));

        for (int i = 1; i <= n; i++)
            a[s[i] - '0']++, c[i] = s[i] - '0';
        
        vector <int> ans;

        for (int i = 0; i < 5; i++)
            if (a[b[i]]) {
                ans.push_back(b[i]);
                break;
            }
        
        if (ans.size()) {
            printf("1\n%d\n", ans[0]);
            continue;
        }

        for (int i = 1; i <= 9; i++)
            if (a[i] >= 2) {
                ans.push_back(i);
                break;
            }
        
        if (ans.size()) {
            printf("2\n%d%d\n", ans[0], ans[0]);
            continue;
        }

        bool ok = 1;

        for (int i = 2; i <= n && ok; i++)
            for (int j = 1; j < i && ok; j++)
                if (chk_(c[j]*10 + c[i])) {
                    ok = 0;
                    printf("2\n%d%d\n", c[j], c[i]);
                }
    }
}