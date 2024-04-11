#include <bits/stdc++.h>
using namespace std;

const int N = 506;

int a[N];
int p[N];

vector<int> pos[N];

int count_inversion(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (p[i] > p[j]) {
                ++ans;
            }
        }
    }
    return ans;
}

void go() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 500; ++i) {
        pos[i].clear();
    }
    for (int i = 1; i <= n; ++i) {
        pos[ a[i] ].push_back(i);
    }
    int ptr = 0;
    bool flag = false;
    for (int i = 1; i <= 500; ++i) {
        for (int j: pos[i]) {
            p[j] = (++ptr);
        }
        if (pos[i].size() >= 2) {
            flag = true;
        }
    }
    if (count_inversion(n) % 2 == 1) {
        if (!flag) {
            puts("-1");
            return;
        }
        for (int i = 1; i <= 500; ++i) {
            if (pos[i].size() >= 2) {
                swap(p[ pos[i][0] ], p[ pos[i][1] ]);
                break;
            }
        }
        assert(count_inversion(n) % 2 == 0);
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        int tar;
        for (tar = i; tar <= n; ++tar) {
            if (p[tar] == i) break;
        }
        if (tar == i) continue;
        // cerr << "tar = " << tar << endl;
        while (tar != i) {
            if (tar - i == 1) {
                ans.push_back(i); swap(p[i], p[i + 1]); swap(p[i], p[i + 2]);
                ans.push_back(i); swap(p[i], p[i + 1]); swap(p[i], p[i + 2]);
                tar -= 1;
            }
            else {
                ans.push_back(tar - 2); swap(p[tar - 2], p[tar - 1]); swap(p[tar - 2], p[tar]);
                tar -= 2;
            }
        }
        // for (int i = 1; i <= n; ++i) cout << p[i] << ' '; cout << endl;
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < (int)ans.size(); ++i) {
        printf("%d%c", ans[i], " \n"[i == (int)ans.size() - 1]);
    }
    if (ans.empty()) puts("");
}

int main () {
    int T; scanf("%d", &T);
    while (T--) {
        go();
    }
}