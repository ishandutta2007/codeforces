#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1005, mod = 998244353;

int n, m;

string s, t;

void work_() {
    cin>>n>>m>>s>>t;
    //n = s.size(), m = t.size();

    for (int i = 1; i < m; i++) {
        if (t[i] != s[n - m + i]) {
            cout<<"No"<<'\n';
            return;
        }
    }

    for (int i = 0; i <= n - m; i++) {
        if (s[i] == t[0]) {
            cout<<"Yes"<<'\n';
            return;
        }
    }

    cout<<"No"<<'\n';
}

int main() {
    ios :: sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin>>T;

    while (T--) {
        work_();
    }
}