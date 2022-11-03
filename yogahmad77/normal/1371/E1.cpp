#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define pb push_back
#define reset(a,b) memset(a,b,sizeof a);
#define ALL(x) x.begin(),x.end()
 
template <typename T>
void cetak(T t){cout << t << ')' << endl;}
template <typename T, typename... V>
void cetak(T t, V... v) {cout << t; if (sizeof...(v)) cout << ", "; cetak(v...);}
 
#define debug(x...) cout << '(' << #x << ") = ("; cetak(x) 
#define sz(x) (int)(x.size())
#define lt(x) (int)(x.length())
typedef int (*func)(int, int);


const int MOD = 1e9 + 7;

int add(int x, int y){
    int ret = x + y;
    if(ret >= MOD) ret -= MOD;
    return ret;
}
int sub(int x, int y){
    int ret = x - y;
    if(ret < 0) ret += MOD;
    return ret;
}
int mul(int x, int y){
    return (long long)x * y % MOD;
}


const int mx = 1e5 + 10;

const int oo = 2e9;

void solve(int tc){
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for(int &i : a) cin >> i;
    sort(ALL(a));
    vector<pair<int, int>> pp(n + 1);
    for(int i = 0; i <= n; i++){
        if(i == 0) pp[i] = make_pair(-oo, a[0] - 1);
        else if(i == n) pp[i] = make_pair(a[n - 1], oo);
        else pp[i] = make_pair(a[i - 1], a[i] - 1);
    }
    vector<int> ok(n + 1);
    for(int i = 0; i <= n; i++){
        if(pp[i].f <= pp[i].s) ok[i] = 1;
        else ok[i] = 0;
    }
    vector<int> nex(n + 1);
    int las = -1;
    for(int i = n; i >= 0; i--){
        if(ok[i]) las = i;
        nex[i] = las;
    }
    int lower = -oo;
    for(int i = 0; i < n; i++){
        lower = max(lower, a[i] - i);
    }
    int upper = oo;
    las = oo;
    for(int i = n; i > 0; i--){
        las -= 1;
        if(ok[i]) las = min(pp[i].f, las);
        if(i % p == 0) upper = min(upper, las - 1);
    }
    cout << max(0, upper - lower + 1) << '\n';
    for(int i = lower; i <= upper; i++) cout << i << ' ';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}