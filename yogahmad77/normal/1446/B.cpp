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




const int mx = 5e3 + 10;

int n, m;
string s, t;

int dp[mx][mx];

void solve(int tc){
    cin >> n >> m >> s >> t;
    set<int> v1[26], v2[26];
    for(int i = 0; i < n; i++) v1[s[i] - 'a'].insert(i);
    for(int i = 0; i < m; i++) v2[t[i] - 'a'].insert(i);
    for(int i = n; i >= 0; i--){
        for(int j = m; j >= 0; j--){
            int &ret = dp[i][j];
            ret = 0;
            if(i == n || j == m){
                ret = 0;
                continue;
            }            
            ret = max(ret, dp[i][j + 1] - 1);
            ret = max(ret, dp[i + 1][j] - 1);
            if(s[i] == t[j]){
                ret = max(ret, dp[i + 1][j + 1] + 2);
            }
            // auto it = v2[s[i] - 'a'].lower_bound(j);
            // if(it != v2[s[i] - 'a'].end()){
            //     ret = max(ret, dp[i + 1][*it + 1] + 4 - 1 - (*it + 1 - j));
            // }
            // it = v1[t[j] - 'a'].lower_bound(i);
            // if(it != v1[t[j] - 'a'].end()){
            //     ret = max(ret, dp[*it + 1][j + 1] + 4 - 1 - (*it + 1 - i));
            // }
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << '\n';
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