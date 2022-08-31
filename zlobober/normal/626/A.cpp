#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 205;

int X[N], Y[N];

pair<int, int> D[256];

char buf[N];


int main() {
    D['D'] = make_pair(0, -1);
    D['U'] = make_pair(0, 1);
    D['L'] = make_pair(-1, 0);
    D['R'] = make_pair(1, 0);
    int n;
    scanf("%d %s", &n, buf);
    for (int i = 0; i < n; i++) {
        X[i + 1] = X[i] + D[buf[i]].first;
        Y[i + 1] = Y[i] + D[buf[i]].second;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (X[i] == X[j] && Y[i] == Y[j])
                ans++;
        }
    }
    printf("%d\n", ans);
}