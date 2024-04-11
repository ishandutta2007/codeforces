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

void solve(int tc){
    int n, k;
    cin >> n >> k;
    int K = k;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    for(int x = 0; x < n; x++){
        for(int i = 0; i < n; i++){
            int j = (i + x) % n;
            if(k){
                ans[i][j] = 1;
                k--;
            }
        }
    }
    if(K % n == 0) cout << 0 << '\n';
    else cout << 2 << '\n';
    for(auto i : ans){
        for(int j : i) cout << j;
        cout << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}