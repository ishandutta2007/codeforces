#include <bits/stdc++.h>
using namespace std;
int n;
int p[200001];
int q[200001];
vector<int> up;
vector<int> down;
string s;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    cin >> s;
    s = '0' + s;
    up.clear();
    down.clear();
    for (int i = 1; i <= n; i++)
        if (s[i] == '1')
            up.push_back(i);
        else
            down.push_back(i);
    int rate = 1;
    sort(up.begin(), up.end(), [](const int &a, const int &b) { return p[a] < p[b]; });
    sort(down.begin(), down.end(), [](const int &a, const int &b) { return p[a] < p[b]; });
    for (auto &&x : down) q[x] = rate++;
    for (auto &&x : up) q[x] = rate++;
    for (int i = 1; i <= n; i++) cout << q[i] << " \n"[i == n];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}