#include <bits/stdc++.h>
using namespace std;
int d, s;
int f[5001][500];  // sum = i, mod = j, what is the shortest number
pair<int, int> trace[5001][500];
bool done[5001][500];
int weight[5001];
queue<pair<int, int>> q;
string ans;

void output(int a, int b) {
    if ((a == 0) && (b == 0)) return;
    output(a - trace[a][b].first, trace[a][b].second);
    cout << trace[a][b].first;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> d >> s;
    q.emplace(0, 0);
    done[0][0] = 1;
    while (!q.empty()) {
        auto [sum, mod] = q.front();
        q.pop();
        for (int i = 0; i < 10; i++) {
            int n_sum = sum + i;
            if (n_sum > s) continue;
            int n_mod = (mod * 10 + i) % d;
            if (done[n_sum][n_mod]) continue;
            done[n_sum][n_mod] = 1;
            f[n_sum][n_mod] = f[sum][mod] + 1;
            q.emplace(n_sum, n_mod);
            trace[n_sum][n_mod] = {i, mod};
        }
    }
    if (!done[s][0]) {
        cout << "-1\n";
        return 0;
    }
    int a = s, b = 0;
    output(a, b);
}