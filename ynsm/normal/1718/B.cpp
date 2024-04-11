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

const ll LIM = 1e11;
int k;
ll f[N];

int n, a[N];
int cnt[N];
void kek(ll x, bool flag, int coef){
    x = a[x];
    for(int i = k - 1; i >= 0; i--){
        if(flag && x == f[i] && (i & 1) == 1){
            continue;
        }
        while(f[i] <= x){
            x -= f[i];
            cnt[i] += coef;
        }

    }
}
bool check(){
    bool res = true;
//    for(int i = 0; i < 5; i++)
//        cerr << cnt[i];
//    cerr << endl;
    res &= (cnt[0] + cnt[1] == 2);
    for(int i = 2; i < k; i++) {
        if(cnt[i] > 1)
            return false;
        if(cnt[i] == 0){
            for(int j = i; j < k; j++)
                res &= (cnt[j] == 0);
            break;
        }
    }
    return res;
}
void solve() {
    {
        k = 0;
        f[k++] = 1;
        f[k++] = 1;
        ll s = 2;
        while (true) {
            f[k] = f[k - 1] + f[k - 2];
            s += f[k];
            if (f[k] > LIM)
                break;
            k++;
        }
    }

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        kek(i, 0, 1);

    bool ans = false;
    if(n == 1 && a[0] == 1)
        ans = true;
    ans |= check();

    for(int i = 0; i < n; i++){
        kek(i, 0, -1);
        kek(i, 1, 1);
        ans |= check();
        kek(i, 1, -1);
        kek(i, 0, 1);
    }
    for(int i = 0; i < n; i++)
        kek(i, 0, -1);

    if(ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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