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
#include <random>

std::random_device rnd;
std::mt19937 mt(rnd());

int randint(const int l, const int r){
    return mt()%(r - l) + l;
}

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

const int MX = 100000;
vector<int> x(31), y(31);


vector<vector<int>> calc(int n){
    if(n == 1){
        return {{0}};
    }
    auto ans = vec2d(n, n, 0);
    int m = n/2;
    auto a = calc(m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < m; j++){
            ans[i][j] = a[i][j];
            ans[i][n-j-1] = a[i][j]+m*m;
            ans[n-i-1][j] = a[i][j]+2*m*m;
            ans[n-i-1][n-j-1] = a[i][j]+3*m*m;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    const int M = 32;
    auto h = calc(M);
    int sum = 0;
    int n, k; cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n-1; j++) {
            int ans = h[i][j]^h[i][j+1];
            cout << ans << ' ';
            sum += ans;
        }
        cout << endl;
    }
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n; j++) {
            int ans = h[i][j]^h[i+1][j];
            cout << ans << ' ';
            sum += ans;
        }
        cout << endl;
    }
    int prev_xor = 0;
    while(k--){
        int xo; cin >> xo;
        int cur_xor = prev_xor^xo;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(h[i][j] == cur_xor){
                    cout << i+1 << ' ' << j+1 << endl;
                }
            }
        }
        prev_xor = cur_xor;
    }
}