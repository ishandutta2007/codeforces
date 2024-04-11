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

void test(int n){
    set<vector<int>> seen;
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    queue<vector<int>> que;
    que.push(p);
    seen.insert(p);
    while(!que.empty()){
        auto q = que.front(); que.pop();
        for(int k = 1; k <= n/2; k++){
            auto r = q;
            for(int i = 0; i < n; i++){
                if(i < k){
                    r[i] = q[n-k+i];
                }else if(i >= n-k){
                    r[i] = q[i-(n-k)];
                }else{
                    r[i] = q[i];
                }
            }
            if(seen.count(r)) continue;
            seen.insert(r);
            que.push(r);
        }
    }
    cout << seen.size() << endl;
    for(auto v: seen) print_vector(v);
}

using P = pair<int, int>;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    if(n%2 == 1){
        int c = n/2;
        if(a[c] != b[c]){
            cout << "No" << endl;
            return;
        }
    }
    auto count_pairs = [&](vector<int> v){
        vector<P> ans;
        for(int i = 0; i < n/2; i++){
            int j = n-1-i;
            int x = v[i], y = v[j];
            if(x > y) swap(x, y);
            ans.push_back(P(x, y));
        }
        sort(ans.begin(), ans.end());
        return ans;
    };
    auto pa = count_pairs(a);
    auto pb = count_pairs(b);
    if(pa == pb){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) {
        solve();
        // int n; cin >> n;
        // test(n);
    }
}