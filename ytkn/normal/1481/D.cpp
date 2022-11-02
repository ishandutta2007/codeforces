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
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    if(m%2 == 1){
        vector<int> v = {1, 2};
        cout << "YES" << endl;
        for(int k = 0; k <= m; k++){
            cout << v[k%2] << ' ';
        }
        cout << endl;
        return;
    }
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(s[i][j] == s[j][i]){
                vector<int> v = {i+1, j+1};
                cout << "YES" << endl;
                for(int k = 0; k <= m; k++){
                    cout << v[k%2] << ' ';
                }
                cout << endl;
                return;
            }
        }
    }
    for(int i = 0; i < n; i++){
        vector<int> in, out;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(s[i][j] == 'a') out.push_back(j);
            if(s[j][i] == 'a') in.push_back(j);
        }
        if(in.size() > 0 && out.size() > 0){
            cout << "YES" << endl;
            int x = m/2;
            int s = in[0], t = out[0];
            for(int k = 0; k < x; k++){
                if(k%2 == x%2) cout << i+1 << ' ';
                else cout << s+1 << ' ';
            }
            cout << i+1 << ' ';
            for(int k = x+1; k <= m; k++){
                if(k%2 == x%2) cout << i+1 << ' ';
                else cout << t+1 << ' ';
            }
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}