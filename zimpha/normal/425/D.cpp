#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000 + 10;
typedef pair<int, int> PII;
typedef vector<int> VI;

map<int, VI> XS, YS;
int x[MAXN], y[MAXN], n;

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d%d", x + i, y + i);
        XS[x[i]].push_back(y[i]);
        YS[y[i]].push_back(x[i]);
    }
    for (map<int, VI>::iterator it = XS.begin(); it != XS.end(); ++ it) {
        sort(it->second.begin(), it->second.end());
    }
    for (map<int, VI>::iterator it = YS.begin(); it != YS.end(); ++ it) {
        sort(it->second.begin(), it->second.end());
    }
    int ret = 0;
    for (int i = 0; i < n; ++ i) {
        vector<int>::iterator ix, iy;
        vector<int> &A = XS[x[i]], &B = YS[y[i]];
        ix = upper_bound(B.begin(), B.end(), x[i]);
        iy = upper_bound(A.begin(), A.end(), y[i]);
        for (; ix != B.end() && iy != A.end(); ) {
            if (*ix - x[i] > *iy - y[i]) ++ iy;
            else if (*ix - x[i] < *iy - y[i]) ++ ix;
            else {
                ret += binary_search(XS[*ix].begin(), XS[*ix].end(), *iy);
                ++ ix, ++ iy;
            }
        }
    }
    cout << ret << endl;
}