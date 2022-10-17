#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 300500, inf = 1e9, mod = 998244353;

int sum(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0)
        a += mod;
    return a;
}

int mult(int a, int b) {
    return 1ll * a * b % mod;
}

int bp(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}

int inv(int x) {
    return bp(x, mod - 2);
}

int n;
vector<int> a, b[4];

int cnt = 0;

bool ask(vector<int> a, vector<int> b) {
    cnt++;
    cout << "? " << a.size() + b.size() << " ";
    for (auto x: a)
        cout << x << " ";
    for (auto x: b)
        cout << x << " ";
    cout << endl;
    string s;
    cin >> s;
    return s == "YES";
}

bool ask(int x) {
    return ask({x}, {});
}

void answer(int x) {
    cout << "! " << x << endl;
    string s;
    cin >> s;
    if (s == ":)")
        exit(0);
}

void solve() {
    cin >> n;
    if (n == 1) {
        answer(1);
        return;
    }
    if (n == 2) {
        answer(1);
        answer(2);
        return;
    }

    for (int i = 1; i <= n; i++)
        a.pb(i);
    while (a.size() > 3) {
        for (int i = 0; i < 4; i++)
            b[i].clear();
        for (int i = 0; i < a.size(); i++)
            b[i % 4].pb(a[i]);
        int mask = 0;
        {
            bool res = ask(b[0], b[1]);
            if (res)
                mask = mask | (1 << 0) | (1 << 1);
            else
                mask = mask | (1 << 2) | (1 << 3);
        }
        {
            bool res = ask(b[0], b[2]);
            if (res)
                mask = mask | (1 << 0) | (1 << 2);
            else
                mask = mask | (1 << 1) | (1 << 3);
        }
        a.clear();
        for (int i = 0; i < 4; i++)
            if ((mask >> i) & 1)
                for (auto x: b[i])
                    a.pb(x);
    }
    if (ask(a[0])) {
        answer(a[0]);
        if (ask(a[1]))
            answer(a[1]);
        else
            answer(a[2]);
    } else {
        if (ask(a[0])) {
            answer(a[0]);
            if (ask(a[1]))
                answer(a[1]);
            else
                answer(a[2]);
        } else {
            answer(a[1]);
            answer(a[2]);
        }
    }
}

int main() {
//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}