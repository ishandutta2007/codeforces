#include <bits/stdc++.h>
using namespace std;

const int maxn = 55;
int T, n;
char s[maxn], ans[maxn][maxn];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %s", &n, s + 1);
        vector<int> V;
        for (int i = 1; i <= n; i++) {
            if (s[i] == '2') V.push_back(i);
            for (int j = 1; j <= n; j++) {
                if (i ^ j) ans[i][j] = '=';
            }
        }
        if (!V.empty() && V.size() <= 2) { puts("NO"); continue; }
        for (int i = 0; i < V.size(); i++) {
            ans[V[i]][V[(i + 1) % V.size()]] = '+';
            ans[V[(i + 1) % V.size()]][V[i]] = '-';
        }
        puts("YES");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) ans[i][j] = 'X';
                putchar(ans[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}