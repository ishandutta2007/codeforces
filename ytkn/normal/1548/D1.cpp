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

ll comb3(ll x){
    if(x <= 2) return 0;
    return (x*(x-1)*(x-2))/6;
}

ll comb2(ll x){
    if(x <= 1) return 0;
    return (x*(x-1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    auto cnt = vec2d(2, 2, 0ll);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y; x /= 2; y /= 2;
        cnt[x%2][y%2]++;
    }
    ll ans = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ans += comb3(cnt[i][j]);
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    if(i == k && j == l) continue;
                    ans += comb2(cnt[i][j])*cnt[k][l];
                }
            }
        }
    }
    cout << ans << endl;
}