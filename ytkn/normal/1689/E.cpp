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

struct UnionFind {
    vector<int> data;
    UnionFind(int size) : data(size, -1) {}
    bool unionSet(int x, int y) {
        x = root(x); y = root(y);
        if (x != y) {
        if (data[y] < data[x]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        }
        return x != y;
    }
    bool findSet(int x, int y) {
        return root(x) == root(y);
    }
    int root(int x) {
        return data[x] < 0 ? x : data[x] = root(data[x]);
    }
    int size(int x) {
        return -data[root(x)];
    }
};

void solve(){
    int n; cin >> n;
    int ans = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0){
            ans++;
            a[i]++;
        }
    }
    auto cnt = vec2d(30, 30, 0);
    auto cnt_bit = vector<int>(30, 0);
    auto msb = [&](int x){
        for(int i = 29; i >= 0; i--){
            if(x&(1<<i)) return i;
        }
        assert(false);
    };
    auto add = [&](int x){
        int m = msb(x);
        cnt_bit[m]++;
        for(int i = 0; i < m; i++){
            if(x&(1<<i)){
                cnt[m][i]++;
                cnt_bit[i]++;
            }
        }
    };
    auto erase = [&](int x){
        int m = msb(x);
        cnt_bit[m]--;
        for(int i = 0; i < m; i++){
            if(x&(1<<i)){
                cnt[m][i]--;
                cnt_bit[i]--;
            }
        }
    };
    for(int i = 0; i < n; i++) add(a[i]);
    auto ok = [&](){
        UnionFind uf(30);
        int sum = 0;
        for(int i = 0; i < 30; i++){
            if(cnt_bit[i] > 0) sum++;
        }
        for(int i = 0; i < 30; i++){
            for(int j = 0; j < 30; j++){
                if(cnt[i][j] > 0) uf.unionSet(i, j);
            }
        }
        for(int i = 0; i < 30; i++){
            if(cnt_bit[i] == 0) continue;
            if(uf.size(i) != sum) return false;
        }
        return true;
    };
    if(ok()){
        cout << ans << endl;
        print_vector(a);
        return;
    }
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            erase(a[i]);
            a[i]++;
            add(a[i]);
            if(ok()){
                cout << ans+1 << endl;
                print_vector(a);
                return;
            }
            erase(a[i]);
            a[i]--;
            add(a[i]);
        }else{
            erase(a[i]);
            a[i]++;
            add(a[i]);
            if(ok()){
                cout << ans+1 << endl;
                print_vector(a);
                return;
            }
            erase(a[i]);
            a[i] -= 2;
            add(a[i]);
            if(ok()){
                cout << ans+1 << endl;
                print_vector(a);
                return;
            }
            erase(a[i]);
            a[i]++;
            add(a[i]);
        }
        
    }
    auto l_bit = [&](int x){
        for(int j = 0; j < 30; j++){
            if(x&(1<<j)) {
                return j;
            }
        }
        assert(false);
    };
    int mx = 0;
    for(int i = 0; i < n; i++){
        chmax(mx, l_bit(a[i]));
    }
    ans += 2;
    int c = 0;
    cout << ans << endl;
    for(int i = 0; i < n; i++){
        if(l_bit(a[i]) != mx) continue;
        if(c == 0){
            a[i]--;
            c++;
        }else if(c == 1){
            a[i]++;
            c++;
        }
    }
    
    print_vector(a);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}