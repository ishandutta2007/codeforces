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

int n, p[N], asd[N];
string s;
int pp(int v){
    return p[v] == v ? v : p[v] = pp(p[v]);
}
void unite(int v, int u){
    p[pp(v)] = pp(u);
}
void solve() {
    cin >> n;
    cin >> s;
    n *= 2;
    for(int i = 0; i < n; i++) {
        p[i] = i;
        asd[i] = -1;
    }
    stack< int > st;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            st.push(i);
        }else{
            if(!st.empty()){
                int j = st.top();
                asd[i] = j;
                unite(i, j);
                if(j && asd[j - 1] != -1)
                    unite(i, asd[j - 1]);
                st.pop();
            }
        }
    }
    int k = 0;
    for(int i = 0; i < n; i++)
        if(pp(i) == i)
            k++;
    cout << k << endl;
}

int main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
//        cout << "Case #" << i << endl;
        solve();
    }
}