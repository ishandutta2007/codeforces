#include <bits/stdc++.h>
using namespace std;

const int N = 200006;
int a[N];

bool fixed[N];

int u[N], v[N];

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    set<int> all;
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        all.insert(i);
    }
    all.erase(a[1]);
    int last = a[1];
    int last_id = -1;
    for (int i = 1; i < n; ++i) {
        int gao = a[i];
        if (all.find(gao) == all.end()) {
            int x = *(--all.end());
            all.erase(x);
            u[i] = gao;
            v[i] = x;
            //if (gao == last) {
                last = x;
                last_id = i;
            //}
        }
        else {
            all.erase(gao);
            v[last_id] = gao;
            u[i] = gao;
            v[i] = last;
            last_id = i;
        }
    }
    cout << a[1] << endl;
    for (int i = 1; i < n; ++i) {
        cout << u[i] << ' ' << v[i] << endl;
    }
}