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

template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

template <typename T>
struct bit{
    int n;
    vector<T> data;

    bit(int n_){
        n = 1;
        while(n < n_) n *= 2;
        data = vector<T>(n+1);
        for(int i = 0; i <= n; i++) data[i] = 0;
    }
    
    T sum(int i){
        T ret = 0;
        while(i > 0){
            ret += data[i];
            i -= i&-i;
        }
        return ret;
    }

    void add(int i, T x){
        while(i <= n){
            data[i] += x;
            i += i&-i;
        }
    }
};

int cnt_left[5005][5005];
int cnt_right[5005][5005];

void solve(){
    int n; cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cnt_right[i][j] = 0;
            cnt_left[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(p[0] < p[i]) cnt_left[i][0] = 1;
        for(int j = 1; j < i; j++){
            cnt_left[i][j] = cnt_left[i][j-1];
            if(p[j] < p[i]) cnt_left[i][j]++;
        }
    }
    for(int i = 0; i < n; i++){
        if(p[n-1] < p[i]) cnt_right[i][n-1] = 1;
        for(int j = n-2; j > i; j--){
            cnt_right[i][j] = cnt_right[i][j+1];
            if(p[j] < p[i]) cnt_right[i][j]++;
        }
    }
    ll ans = 0;
    for(int b = 1; b+2 < n; b++){
        for(int c = b+1; c+1 < n; c++){
            ans += (ll)cnt_left[c][b-1]*(ll)cnt_right[b][c+1];
        }
    }
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}