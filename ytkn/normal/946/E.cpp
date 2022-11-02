#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <tuple>
#include <cmath>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

template<typename T>
vector<vector<T>> vec2d(int n, int m, T v){
    return vector<vector<T>>(n, vector<T>(m, v));
}

template<typename T>
vector<vector<vector<T>>> vec3d(int n, int m, int k, T v){
    return vector<vector<vector<T>>>(n, vector<vector<T>>(m, vector<T>(k, v)));
}

template<typename T>
void print_vector(vector<T> v, char delimiter=' '){
    if(v.empty()) {
        cout << endl;
        return;
    }
    for(int i = 0; i+1 < v.size(); i++) cout << v[i] << delimiter;
    cout << v.back() << endl;
}

void solve(){
    string s; cin >> s;
    int n = s.size();
    string mn = "1" + string(n-2, '0') + "1";
    vector<int> cnt(10);
    for(int i = 0; i < n; i++) cnt[s[i]-'0']++;
    for(int i = n-1; i >= 0; i--){
        int x = s[i]-'0';
        cnt[x]--;
        for(int a = x-1; a >= 0; a--){
            if(i == 0 && a == 0) break;
            cnt[a]++;
            int odd = 0;
            for(int b = 0; b < 10; b++){
                if(cnt[b]%2 == 1) odd++;
            }
            if((n-1-i) >= odd){
                string ans = s.substr(0, i);
                ans += a+'0';
                string tail;
                for(int b = 9; b >= 0; b--){
                    if(cnt[b]%2 == 1) tail += b+'0';
                }
                int rem_len = n-ans.size()-tail.size();
                ans += string(rem_len, '9');
                ans += tail;
                cout << ans << endl;
                return;
            }
            cnt[a]--;
        }
    }
    cout << string(n-2, '9') << '\n';
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}