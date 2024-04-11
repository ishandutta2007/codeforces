#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

int T, n, m;

vector <int> a[N], b[N];

int main() {
    cin>>T;

    while (T--) {
        cin>>n>>m;
        int p1 = -1, p2 = -1;

        for (int i = 0; i < n; i++) {
            a[i].resize(m);
            b[i].resize(m);
            
            for (int j = 0; j < m; j++) {
                cin>>a[i][j];
                b[i][j] = a[i][j];
            }

            sort(b[i].begin(), b[i].end());

            for (int j = 0; j < m; j++) {
                if (b[i][j] != a[i][j]) {
                    if (p1 == -1) {
                        p1 = j;
                    } else {
                        p2 = j;
                    }
                }
            }
        }

        bool tag = 1;

        if (p1 == -1) {
            p1 = p2 = 0;
        }

        for (int i = 0; i < n; i++) {
            swap(a[i][p1], a[i][p2]);

            for (int j = 0; j < m; j++) {
                if (b[i][j] != a[i][j]) {
                    tag = 0;
                }
            }
        }

        if (!tag) {
            puts("-1");
        } else {
            printf("%d %d\n", p1 + 1, p2 + 1);
        }
    }
}