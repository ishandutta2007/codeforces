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




const int mx = 1e5 + 10;


void solve(int tc){
    int n, r;
    cin >> r >> n;
    int maks = r * 2 - 2;
    vector<int> x(n + 1, 2), y(n + 1, 0), t(n + 1, 0);
    for(int i = 1; i <= n; i++){
        int X, Y;
        cin >> t[i] >> X >> Y;
        x[i] = X + Y;
        y[i] = X - Y;
    }
    vector<int> pref(n + 1, 0), dp(n + 1, 0);
    for(int i = 0; i <= n; i++){
        if(i == 0){
            pref[i] = dp[i] = 0;
            continue;
        }
        dp[i] = -1;
        for(int j = i - 1; j >= 0; j--){
            if(t[i] - t[j] >= maks){
                dp[i] = max(dp[i], pref[j] + 1);
                break;
            }
            if(max(abs(x[i] - x[j]), abs(y[i] - y[j])) <= t[i] - t[j] && dp[j] != -1){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        pref[i] = max(pref[i - 1], dp[i]);
    }
    cout << pref[n] << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    int tc = 0;
    while(t--){
        solve(++tc);
    }
}