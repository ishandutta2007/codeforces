#include <bits/stdc++.h>
using namespace std;
int n;
int a[301];
int ans_size;
void solve() {
    cin >> n;
    ans_size = n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    set<int> s;
    for (int i = 1; i <= n; i++) s.insert(a[i]);
    for (int i = 1; i <= ans_size; i++)
        for (int j = 1; j <= ans_size; j++) {
            if (i == j) continue;
            int add = abs(a[i] - a[j]);
            if (s.find(add) == s.end()) {
                ans_size++;
                if (ans_size > 300) {
                    cout << "No\n";
                    return;
                }
                a[ans_size] = add;
                s.insert(add);
            }
        }
    cout << "Yes\n";
    cout << ans_size << '\n';
    for (int i = 1; i <= ans_size; i++) cout << a[i] << " \n"[i == ans_size];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}