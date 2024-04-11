#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 200006;
const int K = 314;

int ss[N];
int pre[N];
ll L[N];
ll R[N];
ll sz[N];
ll val[N];

ll gao(ll x) {
    if (x <= 0) return 0;
    return x * (x + 1) / 2;
}

ll gogo(ll sz, ll len) {
    ll tmp = sz - len * K;
    if (tmp < 0) return 0;
    ll num = tmp / len + 1;
    ll mod = (tmp) % len;
    cout << "sz = " << sz << " , len = " << len << " , num = " << num << " , mid = " << mod << " , tmp = " << tmp << endl;
    return num + mod * num + gao(tmp / len);
}

int main () {
    string s; cin >> s;
    int n = (int)s.size();
    for (int i = 0; i < n; ++i) {
        ss[i + 1] = s[i] - '0';
    }
    vector<int> go;
    for (int i = 1; i <= n; ++i) {
        pre[i] = pre[i - 1] + ss[i];
        if (ss[i] == 1) {
            go.push_back(i);
            sz[i] = 1;
        }
    }
    ss[0] = ss[n + 1] = 1;
    for (int i = 1; i <= n; ++i) {
        if (ss[i - 1] == 1) L[i] = i;
        else L[i] = L[i - 1];
    }
    R[n + 1] = n + 1;
    for (int i = n; i >= 1; --i) {
        if (ss[i + 1] == 1) R[i] = i;
        else R[i] = R[i + 1];
    }
    for (int i = 1; i <= n; ++i) {
        R[i] = R[i] - i;
        L[i] = i - L[i];
    }
    ll ans = 0;
    for (int k = 1; k < K; ++k) {
        //unordered_map<int, int> mp;
        vector<ll> v;
        for (int i = 0; i <= n; ++i) {
            ll val = k * pre[i] - i;
            v.push_back(val);
            //ans += mp[val];
            //mp[val]++;
        }
        sort(v.begin(), v.end());
        v.push_back(v.back() + 1);
        ll last = (1ll << 60);
        ll pre = 0;
        for (ll i: v) {
            if (i == last) {
                ++pre;
            }
            else {
                ans += (pre) * (pre - 1) / 2;
                pre = 1;
                last = i;
            }
        }
    }
    /*for (int k = K; k <= n; ++k) {
        ;
    }*/
    //cout << ans << endl;
    for (int i = 1; i <= n / K; ++i) {
        for (int j: go) {
            /*cout << "answer before = " << ans << endl;
            ans += gogo(sz[j] + L[j] + R[j], i);
            ans -= gogo(L[j], i);
            ans -= gogo(R[j], i);
            //ans += max(0ll, (sz[j] + L[j] + R[j]) / i - K + 1 );
            //ans -= max(0ll, (L[j]) / i - K - 1);
            //ans -= max(0ll, (R[j]) / i - K - 1);
            cout << "i = " << i << " , sz = " << sz[j] << " , " << L[j] << " , " << R[j] << endl;
            cout << "answer after = " << ans << endl;*/
            for (int l = 0; l <= L[j]; ++l) {
                int now_len = l + sz[j];
                ll need = max(i * K - now_len, ((-now_len) % i + i) % i);
                //cout << "j = " << j << " , l = " << l << " , sz = " << sz[j] << " , i = " << i << endl;
                //cout << "need = " << need << endl;
                if (R[j] < need) continue;
                ans += (R[j] - need) / i + 1;
                //cout << "del = " << (R[j] - need) / i + 1 << endl;
            }
        }
        if (go.size() <= 1) break;
        for (int jj = (int)go.size() - 2; jj >= 0; --jj) {
            int j = go[jj];
            //R[j] = R[ go[jj + 1] ];
            sz[j] += go[jj + i] - go[jj + i - 1];
        }
        for (int jj = 0; jj <= (int)go.size() - 2; ++jj) {
            int j = go[jj];
            R[j] = R[ go[jj + 1] ];
        }
        go.pop_back();
    }
    cout << ans << endl;
}