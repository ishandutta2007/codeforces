#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    vector<string> s(3);
    for(int i = 0; i < 3; i++) cin >> s[i];
    vector<vector<int>> cnt(3, vector<int>(2));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2*n; j++) {
            cnt[i][s[i][j]-'0']++;
        }
    }
    string ans;
    for(int i = 0; i < 3; i++){
        for(int j = i+1; j < 3; j++){
            for(int k = 0; k < 2; k++){
                if(cnt[i][k] >= n && cnt[j][k] >= n){
                    char t = '0'+k;
                    vector<vector<int>> v(n+1);
                    int cnt = 0;
                    for(char c : s[i]){
                        if(c == t){
                            if(cnt == n) v[n].push_back(k);
                            else cnt++;
                        }else{
                            v[cnt].push_back(k^1);
                        }
                    }
                    cnt = 0;
                    for(char c : s[j]){
                        if(c == t){
                            if(cnt == n) v[n].push_back(k);
                            else cnt++;
                        }else{
                            v[cnt].push_back(k^1);
                        }
                    }
                    for(int x : v[0]) ans += '0'+x;
                    for(int l = 1; l <= n; l++){
                        ans += '0'+k;
                        for(int x : v[l]) ans += '0'+x;
                    }
                    cout << ans << endl;
                    return;
                }
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}