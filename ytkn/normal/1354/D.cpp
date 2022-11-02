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



int randint(const int l, const int r){
    std::random_device rnd;
    std::mt19937 mt(rnd());
    return mt()%(r - l) + l;
}

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    bit<int> bt(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        // a = randint(1, n+1);
        bt.add(a, 1);
    }
    auto kth = [&](int k){
        int l = 0, r = n;
        while(r-l > 1){
            int x = (l+r)/2;
            if(bt.sum(x) >= k) r = x;
            else l = x;
        }
        return r;
    };
    while(q--){
        int x; cin >> x;
        if(x < 0){
            x *= -1;
            int a = kth(x);
            bt.add(a, -1);
        }else{
            bt.add(x, 1);
        }
    }
    for(int i = 1; i <= n; i++){
        if(bt.sum(i) > 0){
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
}