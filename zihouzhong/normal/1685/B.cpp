#include <bits/stdc++.h>
using namespace std;

int T, a, b, c, d;
string s;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> d >> s;
        if (count(s.begin(), s.end(), 'A') != a + c + d) {
            cout << "NO\n"; continue;
        }
        int cnt = 0;
        vector<int> V[2];
        for (int i = 0, j; i < s.size(); i = j) {
            for (j = i + 1; j < s.size() && s[j] ^ s[j - 1]; j++);
            cnt += (j - i - 1) / 2;
            if ((j - i) % 2 == 0) V[s[i] - 'A'].push_back((j - i) / 2);
        }
        sort(V[0].begin(), V[0].end());
        int cur = c;
        for (int x : V[0]) if (cur >= x) cur -= x, cnt++;
        sort(V[1].begin(), V[1].end()), cur = d;
        for (int x : V[1]) if (cur >= x) cur -= x, cnt++;
        cout << (cnt >= c + d ? "YES\n" : "NO\n");
    }
    return 0;
}