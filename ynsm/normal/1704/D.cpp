#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 1000500, inf = 1e9, mod = 998244353;

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

int n, m;
ll a[N], b[N];
void solve() {
    cin >> n >> m;
    for(int i = 0; i < n * m; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++){
        b[i] = 0;
        for(int j = 0; j < m; j++)
            b[i] += 1ll * a[i * m + j] * (j + 1);
    }
    if(b[0] == b[1]){
        for(int i = 0; i < n; i++)
            if(b[i] != b[0])
                cout << i + 1 <<  " " <<  b[i] - b[0] << endl;
    }else{
        if(b[0] == b[2])
            cout << 2 << " " << b[1] - b[0] << endl;
        else
            cout << 1 << " " << b[0] - b[1] << endl;
    }
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