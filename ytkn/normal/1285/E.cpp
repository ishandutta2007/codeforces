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
class Compress{
    public:
    vector<T> data;
    int offset;
    Compress(vector<T> data_, int offset=0): offset(offset){
        set<T> st;
        for(T x: data_) st.insert(x);
        for(T x: st) data.push_back(x);
    };
    int operator[](T x) {
        auto p = lower_bound(data.begin(), data.end(), x);
        assert(x == *p);
        return offset+(p-data.begin());
	}
    T inv(int x){
        return data[x-offset];
    }
    int size(){
        return data.size();
    }
};

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
    int n; cin >> n;
    vector<int> l(n), r(n);
    vector<int> v;
    for(int i = 0; i < n; i++){
        cin >> l[i] >> r[i];
        v.push_back(l[i]);
        v.push_back(r[i]);
    }
    auto cp = Compress<int>(v);
    for(int i = 0; i < n; i++){
        l[i] = cp[l[i]];
        r[i] = cp[r[i]];
    }
    int m = cp.size();
    vector<int> imos(m);
    vector<int> cnt(m);
    for(int i = 0; i < n; i++){
        imos[l[i]]++;
        imos[r[i]]--;
        cnt[l[i]]++;
        cnt[r[i]]++;
    }
    for(int i = 1; i < m; i++){
        imos[i] += imos[i-1];
    }
    int cnt_zero = 0;
    vector<int> count_one(m-1);
    for(int i = 0; i < m-1; i++){
        if(imos[i] == 1) count_one[i] = 1;
        if(imos[i] == 0) cnt_zero++;
    }
    auto cumsum_one = Cumsum<int>(count_one);
    int ans = 1;
    for(int i = 0; i < n; i++){
        cnt[l[i]]--;
        cnt[r[i]]--;
        int tmp = 1+cumsum_one.sum(l[i], r[i])+cnt_zero;
        if(l[i] == r[i]){
            if(cnt[r[i]] == 0 && r[i] != m-1 && imos[r[i]] == 0){
                tmp--;
            }
        }else{
            if(cnt[l[i]] == 0 && l[i] != m-1 && imos[l[i]] == 1){
                tmp--;
            }
            if(cnt[r[i]] == 0 && r[i] != m-1 && imos[r[i]] == 0){
                tmp--;
            }
        }
        if(l[i] == r[i]){
            if(m != 1 && r[i] == m-1 && cnt[m-1] == 0 && imos[m-2] == 0) tmp--;
        }else{
            if(m != 1 && r[i] == m-1 && cnt[m-1] == 0 && imos[m-2] == 1) tmp--;
        }
        if(l[i] != r[i]){
            
        }
        // cout << i << ':' << tmp << endl;
        chmax(ans, tmp);
        cnt[l[i]]++;
        cnt[r[i]]++;
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