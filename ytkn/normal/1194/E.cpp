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

//1-indexed
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

const int N = 10005;
using P = pair<int, int>;
using T = tuple<int, int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<T> h, v;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        if(x1 == x2){
            if(y1 > y2) swap(y1, y2);
            h.push_back(T(x1, y1, y2));
        }else{
            if(x1 > x2) swap(x1, x2);
            v.push_back(T(y1, x1, x2));
        }
    }
    sort(h.begin(), h.end());
    bit<int> bt(N);
    vector<vector<int>> erase(N);
    ll ans = 0;
    for(auto [x, ly, ry]: h){
        for(auto [y, lx, rx]: v){
            if(y < ly || y > ry) continue;
            if(x < lx || x > rx) continue;
            int xx = rx-x;
            int yy = y-ly+1;
            bt.add(yy, 1);
            erase[xx].push_back(yy);
        }
        int cur_x = x;
        for(auto [x2, ly2, ry2]: h){
            if(x2 <= x) continue;
            int ly1 = max(ly, ly2);
            int ry1 = min(ry, ry2);
            if(ly1 >= ry1) continue;
            while(cur_x < x2){
                int xx = cur_x-x;
                for(int i: erase[xx]) {
                    bt.add(i, -1);
                }
                cur_x++;
            }
            int lyy = ly1-ly+1;
            int ryy = ry1-ly+1;
            ll sum = bt.sum(ryy) - bt.sum(lyy-1);
            ans += (sum*(sum-1))/2;
        }

        while(cur_x-x < N){
            int xx = cur_x-x;
            for(int i: erase[xx]) {
                bt.add(i, -1);
            }
            cur_x++;
        }
        for(auto [y, lx, rx]: v){
            if(y < ly || y > ry) continue;
            if(x < lx || x > rx) continue;
            int xx = rx-x;
            erase[xx].clear();
        }
    }
    cout << ans << endl;
}