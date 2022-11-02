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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    string s; cin >> s;
    auto diff = vec2d(6, n, 0);
    string t = "abc";
    int i = 0;
    do{
        for(int j = 0; j < n; j++){
            char c = t[j%3];
            if(c != s[j]) diff[i][j] = 1;
            // cout << (char)c;
        }
        i++;
        // cout << endl;
        // print_vector(diff[i]);
    }while(next_permutation(t.begin(), t.end()));

    auto c = vector<Cumsum<int>>(6, Cumsum<int>({}));
    for(int i = 0; i < 6; i++) c[i] = Cumsum<int>(diff[i]);
    while(m--){
        int l, r; cin >> l >> r; l--;
        if(r-l == 1){
            cout << 0 << endl;
            continue;
        }
        if(r-l == 2){
            if(s[l] == s[l+1]) cout << 1 << endl;
            else cout << 0 << endl;
            continue;
        }
        int ans = n*2;
        for(int i = 0; i< 6; i++) chmin(ans, c[i].sum(l, r));
        // cout << "===" << endl;
        // cout << c[0].sum(l, r) << endl;
        // cout << c[1].sum(l, r) << endl;
        // cout << c[2].sum(l, r) << endl;
        cout << ans << endl;
    }
}