#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 500500, inf = 1e9, mod = 1e9 + 7;

int sum(int a, int b){
    a += b;
    if(a >= mod)
        a -= mod;
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
int f[N];
int C(int k, int n){
    if(k < 0 || k > n)
        return 0;
    return mult(f[n], inv(mult(f[k], f[n - k])));
}

int g(int x, int y){
    if(x < 0 || y < 0)
        return 0;
//    cerr << x << " " << y << endl;
    return C(x, x + y);
}

void solve() {
    int n, last = -1;
    int ans = 0;
    cin >> n;
    n++;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        x--;
        if(i == 0 && x == -1){
            cout << 0 << endl;
            return;
        }

        ans = sum(ans, g(i, x));

        while(last > x){
            ans = sum(ans, g(i - 1, last));
            last--;
        }

        last = x;
    }
    while(last >= 0){
        ans = sum(ans, g(n - 1, last));
        last--;
    }
    ans = sum(ans, mod - 1);
    cout << ans << endl;
}


int main()
{
    ios_base::sync_with_stdio(false);
//    freopen("input.txt","r",stdin);
//        freopen("output.txt","w",stdout);
    f[0] = 1;
    for(int i = 1; i < N; i++)
        f[i] = mult(f[i - 1], i);
    int t = 1;
//    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}