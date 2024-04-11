#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int level_size = 1;
    int next_level_size = 0;
    int current_last = 0;
    int depth = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > current_last) {
            current_last = a[i];
            next_level_size++;
        } else {
            level_size--;
            current_last = a[i];
            if (level_size == 0) {
                depth++;
                level_size = next_level_size;
                next_level_size = 1;
            } else {
                next_level_size++;
            }
        }
    }
    cout << depth << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}