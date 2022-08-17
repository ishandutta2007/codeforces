#include <cstdio>
#include <set>
using namespace std;
 
const int N = 150500;

int T[N];

bool in_window[N];

int main() {
    int n, k, q;
    scanf("%d %d %d", &n, &k, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }
    set<pair<int, int>> S;
    for (int i = 0; i < q; i++) {
        int t, x;
        scanf("%d %d", &t, &x);
        --x;
        if (t == 1) {
            S.insert(make_pair(-T[x], x));
            in_window[x] = true;
            while (S.size() > k) {
                pair<int, int> lst = *(--S.end());
                in_window[lst.second] = false;
                S.erase(--S.end());
            }
        } else {
            puts(in_window[x] ? "YES" : "NO");
        }
    }
}