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

ll ans;

void solve(vector<ll> a, int msb){
    int n = a.size();
    if(n <= 2) return;
    vector<int> msb_indices = {-1};
    for(int i = 0; i < n; i++){
        if(a[i]&(1<<msb)) msb_indices.push_back(i);
    }
    msb_indices.push_back(n);
    auto cumsum = Cumsum<ll>(a);
    auto ok = [&](int l, int r){
        if(l+1 == r) return false;
        // if((a[l]^a[r]) == cumsum.sum(l+1, r)){
        //     cout << a[l] << ' ' << a[r] << endl;
        // }
        return (a[l]^a[r]) == cumsum.sum(l+1, r);
    };

    // msb2
    for(int i = 1; i+2 < msb_indices.size(); i++){
        int l = msb_indices[i], r = msb_indices[i+1];
        if(ok(l, r)) ans--;
    }

    // msb
    for(int i = 1; i+1 < msb_indices.size(); i++){
        int l = msb_indices[i];
        int r = i+2 < msb_indices.size() ? msb_indices[i+2] : msb_indices[i+1];
        for(int j = l+1; j < r; j++){
            if(ok(l, j)) ans++;
        }
    }

    // msb
    for(int i = 1; i+1 < msb_indices.size(); i++){
        int r = msb_indices[i];
        int l = i >= 2 ? msb_indices[i-2] : msb_indices[i-1];
        for(int j = l+1; j < r; j++){
            if(ok(j, r)) ans++;
        }
    }

    if(msb == 0) return;
    for(int i = 0; i+1 < msb_indices.size(); i++){
        int l = msb_indices[i]+1, r = msb_indices[i+1];
        vector<ll> b;
        for(int j = l; j < r; j++){
            b.push_back(a[j]);
        }
        solve(b, msb-1);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    solve(a, 29);
    cout << ans << endl;
}