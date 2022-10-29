#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll mod = 1000000123;
const ll X = 890501;
const int N = 500006;

int pre_cnt[N];
int cnt_s[2];
ll pre_t[N];
ll ppow[N];

bool can(int L,int R) {
    int need1 = pre_cnt[R] - pre_cnt[L-1];
    int need0 = (R - L + 1) - need1;
    if (cnt_s[0] >= need0 && cnt_s[1] >= need1) return true;
    return false;
}

void yuuki() {
    while (cnt_s[0]--) cout << 0;
    while (cnt_s[1]--) cout << 1;
    cout << endl;
    exit(0);
}

ll hash_val(int L,int R) {
    return (pre_t[R] - pre_t[L-1] + mod) * ppow[N - L - 2] % mod;
}

string s,t;

void show(int L,int R) {
    for (int i=L;i<=R;++i) {
        cout << t[i];
        cnt_s[ t[i]-'0' ]--;
    }
}

int main () {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    ppow[0] = 1;
    for (int i = 1; i < N; ++i) {
        ppow[i] = ppow[i-1] * X % mod;
    }
    int n = (int)s.size() - 1;
    int m = (int)t.size() - 1;
    for (int i = 1;i <= m; ++i) {
        pre_cnt[i] = pre_cnt[i-1] + (t[i] - '0');
        pre_t[i] = (pre_t[i-1] + t[i] * ppow[i]) % mod;
    }
    for (char i:s) {
        cnt_s[i-'0']++;
    }
    int ptr = m;
    if (!can(1,m)) {
        yuuki();
    }
    show(1,m);
    int pre = m-1;
    while (true) {
        while (pre > 0 && hash_val(1,pre) != hash_val(m-pre+1,m)) {
            --pre;
        }
        if (!can(pre+1,m)) {
            yuuki();
        }
        show(pre+1,m);
        pre = m-1;
    }
}