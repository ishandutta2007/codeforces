#include <bits/stdc++.h>
using namespace std;

int f[1000], g[1000], h[1000];

void init() {
    int n = 500;
    for (int i = 1; i <= n; i++) {
        set<int> S;
        for (int j = 1; j < i; j++) {
            S.insert(f[j - 1] ^ f[i - j - 1]);
        }
        while (S.count(f[i])) f[i]++;
        if (i > 100) assert(f[i] == f[i - 34]);
    }
    for (int i = 1; i <= n; i++) {
        set<int> S;
        S.insert(f[i - 1]);
        for (int j = 1; j < i; j++) {
            S.insert(g[j - 1] ^ f[i - j - 1]);
        }
        while (S.count(g[i])) g[i]++;
        if (i > 100) assert(g[i] == g[i - 34]);
    }
    for (int i = 1; i <= n; i++) {
        set<int> S;
        S.insert(g[i - 1]);
        for (int j = 1; j < i; j++) {
            S.insert(g[j - 1] ^ g[i - j - 1]);
        }
        while (S.count(h[i])) h[i]++;
        if (i > 100) assert(h[i] == h[i - 34]);
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    init();
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s;
        cin >> n >> s;
        int r = count(s.begin(), s.end(), 'R');
        int b = count(s.begin(), s.end(), 'B');
        if (r > b) {
            cout << "Alice\n";
        } else if (r < b) {
            cout << "Bob\n";
        } else {
            vector<int> a;
            for (int i = 0, j; i < n; i = j) {
                for (j = i; j < s.size() && s[i] == s[j]; j++);
                a.push_back(j - i);
            }
            int xors = 0;
            for (int i = 0, j; i < a.size(); i++) if (a[i] == 1) {
                for (j = i; j < a.size() && a[j] == 1; j++);
                int num = (i > 0) + (j < a.size());
                int cnt = j - i;
                while (cnt > 500) cnt -= 34;
                if (!num) xors ^= f[cnt];
                else if (num == 1) xors ^= g[cnt];
                else xors ^= h[cnt];
                i = j - 1;
            }
            for (int i = 0; i < a.size() - 1; i++) {
                if (a[i] > 1 && a[i + 1] > 1) xors ^= 1;
            }
            cout << (xors ? "Alice" : "Bob") << "\n";
        }
    }
    return 0;
}