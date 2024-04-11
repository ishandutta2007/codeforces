#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

const int N = 500500, K = 550, inf = 1e9, mod = 998244353;

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

int dp[K];
int get(int x){
    if(x < K)
        return dp[x];
    return dp[x % 34 + 34 * 10];
}
void solve() {
    int n;
    string s;
    cin >> n;
    cin >> s;

    int bal = 0, kek = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == 'R')
            bal++;
        else
            bal--;
    }
    for(int i = 0, j = 0; i + 1 < n; i = j){
        while(j + 1 < n && s[j] != s[j + 1])
            j++;
        kek ^= get(j - i);
//        cout << j - i << "-" << get(j - i) << endl;
        j = max(j, i + 1);
    }
//    cout << kek << " " << bal << endl;
    if(kek)
        bal++;
    if(bal > 0)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    dp[1] = 1;
    for(int i = 2; i < K; i++){
        set< int > st;
        st.insert(dp[i - 2]);
        for(int j = 0; j <= i - 3; j++)
            st.insert(dp[j] ^ dp[i - 3 - j]);
        for(int q = 0; ; q++)
            if(st.find(q) == st.end()){
                dp[i] = q;
                break;
            }
    }

    int t = 1;
    cin >> t;
    for(int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}