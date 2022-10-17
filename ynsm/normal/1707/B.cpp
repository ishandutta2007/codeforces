#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 500500, inf = 1e9, mod = 998244353;

int sum(int a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
    return a;
}
int sub(int a, int b){
    a -= b;
    if(a < 0)
        a += mod;
    return a;
}
int mult(int a, int b){
    return 1ll * a * b % mod;
}
int bp(int a, int b){
    int res = 1;
    while(b){
        if(b & 1)
            res = mult(res, a);
        a = mult(a, a);
        b >>= 1;
    }
    return res;
}
int inv(int x){
    return bp(x, mod - 2);
}

int n, m, a[N], b[N], zeros;


void solve() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    zeros = 0;
    reverse(a, a + n);
    while(n && a[n - 1] == 0)
        n--, zeros++;
    reverse(a, a + n);

    while(zeros + n > 1){
        m = 0;
        if(zeros) {
            if(n)
                b[m++] = a[0];
            zeros--;
        }
        for(int i = 0; i + 1 < n; i++)
            if(a[i + 1] == a[i])
                zeros++;
            else
                b[m++] = a[i + 1] - a[i];
        sort(b, b + m);
        n = m;
        for(int i = 0; i < n; i++)
            a[i] = b[i];
    }

    if(zeros)
        cout << 0 << endl;
    else
        cout << a[0] << endl;
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