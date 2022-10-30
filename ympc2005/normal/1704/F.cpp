#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 5e5 + 10, mod = 998244353;

int n, sg[N], c[N];

string s;

void work_() {
    cin>>n>>s;
    int R = 0, B = 0;

    for (int i = 0; i < n; i++) {
        R += s[i] == 'R';
        B += s[i] == 'B';
    }

    if (R > B) {
        cout<<"Alice"<<'\n';
        return;
    }

    if (R < B) {
        cout<<"Bob"<<'\n';
        return;
    }

    int ans = 0;

    vector <int> tmp;

    for (int l = 0, r; l < n; l = r + 1) {
        r = l;

        while (r + 1 < n && s[r] != s[r + 1]) {
            r++;
        }

        ans ^= sg[r - l + 1];
    }

    if (ans) {
        cout<<"Alice"<<'\n';
    } else {
        cout<<"Bob"<<'\n';
    }
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    for (int i = 2; i <= 5e5; i++) {
        if (i > 2000) {
            sg[i] = sg[i - 34];
            continue;
        }
        
        for (int j = 1; j < i; j++) {
            c[sg[j - 1]^sg[i - j - 1]] = 1;
        }

        while (c[sg[i]]) {
            sg[i]++;
        }

        for (int j = 1; j < i; j++) {
            c[sg[j - 1]^sg[i - j - 1]] = 0;
        }
    }

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}