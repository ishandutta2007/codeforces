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

ll tri(ll n){
    return (n*(n-1))/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    map<vector<int>, int> indices;
    auto c = vec2d(n, k, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            cin >> c[i][j];
        }
        indices[c[i]] = i;
    }
    vector<ll> cnt(n);
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            vector<int> v(k);
            for(int l = 0; l < k; l++){
                if(c[i][l] == c[j][l]){
                    v[l] = c[i][l];
                }else{
                    v[l] = 3-(c[i][l]^c[j][l]);
                }
            }
            if(indices.count(v)){
                int idx = indices[v];
                if(idx > j){
                    cnt[i]++;
                    cnt[j]++;
                    cnt[idx]++;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        ans += tri(cnt[i]);
    }
    cout << ans << endl;
}