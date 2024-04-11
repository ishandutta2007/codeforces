#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500;

struct kek{
    int mod, root, root_1, root_pw;
    kek(int lol){
        if(lol){
            mod = 998244353;
            root = 646;
            root_1 = 208611436;
            root_pw = 1 << 20;
        }else{
            mod = 7340033;
            root = 5;
            root_1 = 4404020;
            root_pw = 1 << 20;
        }
    }
    int mult(int a, int b) { return (1LL * a * b) % mod; }

    int pw(int a, int b)
    {
        if (b == 0)
            return 1;
        if (b & 1)
            return mult(a, pw(a, b - 1));
        int res = pw(a, b / 2);
        return mult(res, res);
    }
    int inv(int x) { return pw(x, mod - 2); }

    int sub(int a, int b)
    {
        int s = a - b;
        if (s < 0)
            s += mod;
        return s;
    }

    int sum(int a, int b)
    {
        int s = a + b;
        if (s >= mod)
            s -= mod;
        return s;
    }

    void fft(vector<ll> &a, bool invert)
    {
        int n = (int)a.size();

        for (int i = 1, j = 0; i < n; ++i)
        {
            int bit = n >> 1;
            for (; j >= bit; bit >>= 1)
                j -= bit;
            j += bit;
            if (i < j)
                swap(a[i], a[j]);
        }

        for (int len = 2; len <= n; len <<= 1)
        {
            int wlen = invert ? root_1 : root;
            for (int i = len; i < root_pw; i <<= 1)
                wlen = int(wlen * 1ll * wlen % mod);
            for (int i = 0; i < n; i += len)
            {
                int w = 1;
                for (int j = 0; j < len / 2; ++j)
                {
                    int u = a[i + j], v = int(a[i + j + len / 2] * 1ll * w % mod);
                    a[i + j] = u + v < mod ? u + v : u + v - mod;
                    a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + mod;
                    w = int(w * 1ll * wlen % mod);
                }
            }
        }
        if (invert)
        {
            int nrev = pw(n, mod - 2);
            for (int i = 0; i < n; ++i)
                a[i] = int(a[i] * 1ll * nrev % mod);
        }
    }

    vector< ll > poly_mult(vector<ll> a, vector<ll> b)
    {
        int s = a.size() + b.size();
        int r = 1;
        while (r < s)
            r *= 2;
        vector< ll > c(r);
        a.resize(r);
        b.resize(r);
        fft(a, false);
        fft(b, false);
        for (int j = 0; j < r; j++)
            c[j] = mult(a[j], b[j]);
        fft(c, true);
        return c;
    }
};


ll get(ll l,ll r, ll k){
    if(r < l)
        return 0;
    ll res = 0;
    ll cnt = (r - l) / k + 1;
    res += l * cnt;
    res += cnt * (cnt - 1) / 2 * k;
    return res;
}
ll get_mn(ll b, ll a){
    b = (a + 1) / 2 - b;
    return get(1, a, 2) - get(a - b + 1, a, 1);
}
ll get_mx(ll b, ll a){
    b = (a + 1) / 2 - b;
    return get(1, a, 2) - get(1, b, 1);
}

void solve() {
    int n, m;

    cin >> n;
    vector< ll > a(n);
    for(int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    vector< ll > b(m);
    for(int i = 0; i < m; i++)
        cin >> b[i];

    vector< bool > was( n - m + 1, 0);

    if(m > 2) {
        vector< ll > A(n - 2), B(m - 2);
        for (int i = 0; i + 2 < n; i++)
            A[i] = a[i] + 2 * a[i + 1] + a[i + 2];
        for (int i = 0; i + 2 < m; i++)
            B[i] = b[i] + 2 * b[i + 1] + b[i + 2];
        reverse(B.begin(), B.end());

        vector< ll > c;
        for (auto x: A)
            c.pb(x);
        for (auto x: B)
            c.pb(x);
        for (auto x: B)
            c.pb(x - 1);
        sort(c.begin(), c.end());
        c.resize(unique(c.begin(), c.end()) - c.begin());

        for (auto &x: A)
            x = lower_bound(c.begin(), c.end(), x) - c.begin() + 1;
        for (auto &x: B)
            x = lower_bound(c.begin(), c.end(), x) - c.begin() + 1;

        for (int i = 0; i < 1; i++) {
            kek f(i);
            auto C = f.poly_mult(A, B);

            ll s = 0;
            for(int j = 0; j < m - 2; j++) {
                s = f.sum(s, f.mult(A[j], A[j] + 1));
                s = f.sum(s, f.mult(B[j], B[j] - 1));
            }

            for (int j = 0; j < n - m + 1; j++) {
                int p = m - 3 + j;
                if (s != f.sum(C[p], C[p]))
                    was[j] = 1;
                s = f.sub(s, f.mult(A[j], A[j] + 1));
                if(j < n - m)
                    s = f.sum(s, f.mult(A[j + m - 2], A[j + m - 2] + 1));
            }
        }
    }

    for(int i = 0; i < n - m + 1; i++){
        if(was[i])
            continue;
        for(int j = 0; j < 2; j++) {
            ll bal = a[i] - b[0] + a[i + 1] + j - b[1];
            if(bal > (i + 2) / 2)
                continue;
            if(bal < -(i + 1) / 2)
                continue;
            if(a[i] + get_mn(bal, i + 1) > b[0])
                continue;
            if(a[i] + get_mx(bal, i + 1) < b[0])
                continue;

            for(int q = 0; q + 2 < m; q++)
                if(a[i + q] + 2 * a[i + q + 1] + a[i + q + 2] == b[q] + 2 * b[q + 1] + b[q + 2]
                   ||
                   a[i + q] + 2 * a[i + q + 1] + a[i + q + 2] + 1== b[q] + 2 * b[q + 1] + b[q + 2]
                        );
                else
                    was[i] = 1;
            if(was[i])
                continue;

            vector< int > ans;
            if(j)
                ans.pb(i + 1);
            for(int q = 0; q + 2 < m; q++)
                if(a[i + q] + 2 * a[i + q + 1] + a[i + q + 2] != b[q] + 2 * b[q + 1] + b[q + 2])
                    ans.pb(i + q + 2);

            ll dif = b[0] - a[i];

            for(int q = i + 1; q >= 1; q--){
                ll dc = ((q & 1) ? q : -q);
                ll dd = ((q & 1) ? 1 : -1);

                if(get_mn(bal, q - 1) <= dif && dif <= get_mx(bal, q - 1)){

                } else {
                    ans.pb(i - q + 1);
                    dif -= dc;
                    bal -= dd;
                }
            }
            cout << ans.size() << '\n';
            for(auto x : ans)
                cout << x + 1 << ' ';
            cout << '\n';
            return;
        }
    }
    cout << -1 << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}