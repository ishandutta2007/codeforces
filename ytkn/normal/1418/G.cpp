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

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;
using ul = uint_fast64_t;

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
        data = data_;
        sort(data.begin(), data.end());
        data.erase(unique(data.begin(), data.end()), data.end());
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

queue<int> dq[500005];
vector<int> mp[500005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    auto mt = mt19937_64((ul)0);
    int n; cin >> n;
    vector<int> a(n);
    vector<ul> x(n), y(n);
    for(int i = 0; i < n; i++){
        x[i] = mt();
        y[i] = mt();
    }
    vector<int> cnt(n);
    vector<ul> xo(n+1);
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        if(cnt[a[i]]%3 == 0){
            xo[i+1] = xo[i]^x[a[i]];
        }else if(cnt[a[i]]%3 == 1){
            xo[i+1] = xo[i]^y[a[i]];
        }else{
            xo[i+1] = xo[i]^x[a[i]]^y[a[i]];
        }
        cnt[a[i]]++;
    }
    x.clear(); y.clear();
    auto cp = Compress<ul>(xo);
    int m = cp.size();
    ll ans = 0;
    int mx = n+1;
    vector<int> idx(n+1);
    for(int i = 0; i <= n; i++) {
        xo[i] = cp[xo[i]];
        idx[i] = mp[xo[i]].size();
        mp[xo[i]].push_back(i);
    }
    for(int i = n-1; i >= 0; i--){
        dq[a[i]].push(i+1);
        if(dq[a[i]].size() >= 5) {
            dq[a[i]].pop();
        }
        if(dq[a[i]].size() == 4){
            chmin(mx, dq[a[i]].front());
        }
        while(mp[xo[i]].back() >= mx) mp[xo[i]].pop_back();
        ans += mp[xo[i]].size()-1-idx[i];
    }
    cout << ans << endl;
}