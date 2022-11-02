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


const int N_MAX = 1000000;
int norm[N_MAX+1];

void init(){
    for(int i = 1; i <= N_MAX; i++){
        norm[i] = i;
    }
    for(int i = 2; i*i <= N_MAX; i++){
        int x = i*i;
        for(int j = 1; x*j <= N_MAX; j++){
            while(norm[x*j]%x == 0) norm[x*j] /= x;
        }
    }
}

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> cnt;
    cnt[1] = 0;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = norm[a[i]];
        if(cnt.count(b[i])) cnt[b[i]]++;
        else cnt[b[i]] = 1;
    }
    int mx = 0;
    int odd_max = 0;
    int cnt_even = 0;
    for(auto [x, c]: cnt){
        chmax(mx, c);
        if(c%2 == 0 && x != 1) cnt_even += c;
        if(c%2 == 1 && x != 1) chmax(odd_max, c);
    }
    int q; cin >> q;
    while(q--){
        ll w; cin >> w;
        if(w == 0){
            cout << mx << endl;
        }else{
            cout << max(cnt[1]+cnt_even, odd_max) << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--) solve();
}