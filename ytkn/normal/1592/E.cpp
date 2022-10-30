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

vector<int> slice(vector<int> v, int l, int r){
    vector<int> ans;
    for(int i = l; i < r; i++) ans.push_back(v[i]);
    return ans;
}

bool is_good(vector<int> v){
    int mask = (1<<20)-1;
    int v_and = accumulate(v.begin(), v.end(), mask, [](int x, int y){ return x&y; });
    int v_xor = accumulate(v.begin(), v.end(), 0, [](int x, int y){ return x^y; });
    return v_and > v_xor;
}

int naive(vector<int> a){
    int n = a.size();
    int ans = 0;
    for(int l = 0; l < n; l++){
        for(int r = l+1; r <= n; r++){
            if(is_good(slice(a, l, r))) chmax(ans, r-l);
        }
    }
    return ans;
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

template<typename T>
class Cumxor{
    public:
    Cumxor(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]^v[i];
    }
    /**
     * v[l] ^ ... ^ v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]^v_cumsum[l];
    }
    // private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

const int MAX_BIT = 20;

int solve(vector<int> a){
    int n = a.size();
    int ans = 0;
    auto buf = vec2d(2, 1<<MAX_BIT, vector<int>());
    auto run_bit = [&](int target){
        int mask = 0;
        vector<int> used;
        for(int i = target; i < MAX_BIT; i++) mask += (1<<i);
        vector<int> v(n);
        vector<int> xo(n);
        for(int i = 0; i < n; i++){
            if(a[i]&(1<<target)) v[i] = 1;
            xo[i] = mask&a[i];
        }

        auto cumsum = Cumsum<int>(v);
        auto cumxor = Cumxor<int>(xo);
        for(int i = n; i >= 0; i--){
            buf[i%2][cumxor.sum(0, i)].push_back(i);
            used.push_back(cumxor.sum(0, i));
        }
        auto idx = vec2d(2, 1<<MAX_BIT, 0);
        for(int r = 1; r <= n; r++){
            int j = r%2;
            int xorr = cumxor.sum(0, r);
            while(!buf[j][xorr].empty()){
                int l = buf[j][xorr].back();
                if(cumsum.sum(l, r) != r-l) buf[j][xorr].pop_back();
                else break;
            }
            if(!buf[j][xorr].empty()){
                int l = buf[j][xorr].back();
                chmax(ans, r-l);
            }
        }
        for(int x: used){
            buf[0][x].clear();
            buf[1][x].clear();
        }
    };
    for(int i = 0; i < MAX_BIT; i++) run_bit(i);
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    // cout << naive(a) << endl;
    cout << solve(a) << endl;
}