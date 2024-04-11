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

void solve(){
    string s; cin >> s;
    vector<int> zeros;
    int n = s.size();
    vector<int> cnt(n);
    for(int i = 0; i < n; i++){
        if(s[i] == '0') zeros.push_back(i);
        else cnt[i] = 1;
    }
    auto cumsum = Cumsum<int>(cnt);
    auto ok = [&](int x){
        if(zeros.size() <= x){
            return true;
        }
        vector<int> r(n);
        int m = zeros.size();
        for(int i = m-1; i >= 0; i--){
            int idx = zeros[i];
            if(i+x >= m){
                r[idx] = n;
            }else{
                r[idx] = zeros[i+x];
            }
        }
        int pre = n;
        for(int i = n-1; i >= 0; i--){
            if(s[i] == '1'){
                r[i] = pre;
            }else{
                pre = r[i];
            }
        }
        for(int l = 0; l < n; l++){
            // [l, r)
            int ones = cumsum.sum(0, n)-cumsum.sum(l, r[l]);
            if(ones <= x) return true;
        }
        return false;
    };
    if(ok(0)){
        cout << 0 << endl;
        return;
    }
    int l = 0, r = n;
    while(r-l > 1){
        int x = (l+r)/2;
        if(ok(x)) r = x;
        else l = x;
    }
    cout << r << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}