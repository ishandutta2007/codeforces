#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 200500, inf = 1e9, mod = 998244353;

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

int n, q;

int k, d[500];

const int M = 5e6;

ll a[N], b[M];

struct kek{
    priority_queue<ll> a, b;
    void insert(ll x){
        a.push(x);
    }
    void pop(ll x){
        b.push(x);
    }
    ll get(){
        while(!b.empty() && b.top() == a.top()) {
            a.pop();
            b.pop();
        }
        return a.top();
    }
    void clear(){
        while(!b.empty())
            b.pop();
        while(!a.empty())
            a.pop();
    }
} st[500];


void upd(int p, int x){

    x = x - a[p];
    a[p] += x;

    for(int i = 0, j = 0; i < k; i++){
        int pp = j + p % d[i];
        st[i].pop(b[pp]);
        b[pp] += x;
        st[i].insert(b[pp]);
        j += d[i];
    }

}
ll get(){
    ll res = 0;
    for(int i = 0; i < k; i++)
        res = max(res, 1ll * d[i] * st[i].get());
    return res;
}
void solve() {
    cin >> n >> q;

    {
        ll x = n;
        k = 0;
        for (int i = 2; i <= x; i++)
            if (x % i == 0) {
                while(x % i == 0)
                    x /= i;
                d[k++] = n / i;
            }
    }
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ll x = a[i], p = i;
        for(int i = 0, j = 0; i < k; i++){
            int pp = j + p % d[i];
            b[pp] += x;
            j += d[i];
        }
    }

    for(int i = 0, j = 0; i < k; i++){
        for(int q = 0; q < d[i]; q++)
            st[i].insert(b[j + q]);
        j += d[i];
    }

    cout << get() << endl;
    while(q--){
        ll p, x;
        cin >> p >> x;
        --p;
        upd(p, x);
        cout << get() << endl;
    }

    for(int i = 0, j = 0; i < k; i++){
        st[i].clear();
        for(int q = 0; q < d[i]; q++)
            b[j + q] = 0;
        j += d[i];
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}