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

int n, q, a[N], b[N];

void solve() {
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    int need = 0;
    for(int i = n - 1; i >= 0; i--){
        if(a[i] <= need){
            b[i] = 1;
        }else{
            if(need == q)
                b[i] = 0;
            else
                b[i] = 1, need++;
        }
    }
    for(int i = 0; i < n; i++)
        cout << b[i];
    cout << endl;
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