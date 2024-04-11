# include <bits/stdc++.h>
using namespace std;
const int MN = 2e5 + 44;
#define col kol
int col[MN];
vector <int> graph[MN];
int nr[MN];
vector <int> colors[MN];
queue <int> stos;
int cou(vector <int> & a) {
    sort(a.begin(), a.end());
    int curr = 0, opt = 0;
    for (int i = 0; i < a.size(); ++i) {
        if (i == 0 || a[i] == a[i - 1]) {
            curr++;
        }
        else {
            opt = max(opt, curr);
            curr = 1;
        }
    }
    opt = max(opt, curr);
    return a.size() - opt;
}
int main() {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", kol + i);
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        scanf("%d%d", &a, &b);
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i)
        if (nr[i] == 0) {
            stos.push(i);
            while (!stos.empty()) {
                int x = stos.front();
                nr[x] = i;
                stos.pop();
                for (auto y : graph[x]) {
                    if (nr[y] == 0)
                        stos.push(y);
                }
            }
        }
    for (int i = 1; i <= n; ++i) {
        colors[nr[i]].push_back(col[i]);
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += cou(colors[i]);
    }
    printf("%d\n", res);
}