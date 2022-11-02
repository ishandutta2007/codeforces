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

const ll MX = 1e12;
vector<ll> fib;

void init(){
    fib.push_back(1);
    fib.push_back(1);
    for(int i = 2;;i++){
        ll x = fib[i-1]+fib[i-2];
        if(x > MX) break;
        fib.push_back(x);
    }
}

vector<ll> f(ll x){
    int cur = fib.size()-1;
    vector<ll> ans;
    while(x > 0){
        while(fib[cur] > x) cur--;
        ans.push_back(x);
    }
    return ans;
}

using P = pair<ll, int>;

void solve(){
    int k; cin >> k;
    vector<ll> c(k);
    for(int i = 0; i < k; i++) cin >> c[i];
    ll c_sum = accumulate(c.begin(), c.end(), 0ll);
    if(k == 1){
        if(c[0] == 2){
            cout << "NO" << endl;
            return;
        }
    }
    ll sum = 0;
    int idx = -1;
    for(int i = 0; i < fib.size(); i++){
        sum += fib[i];
        if(sum == c_sum){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        cout << "NO" << endl;
        return;
    }
    vector<int> v(idx+1);
    priority_queue<P> que;
    for(int i = 0; i < k; i++) que.push(P(c[i], i));
    for(int i = idx; i >= 0; i--){
        auto p = que.top(); que.pop();
        ll x = p.first, j = p.second;
        if(i != idx && v[i+1] == j){
            if(que.empty()){
                cout << "NO" << endl;
                return;
            }
            auto p = que.top(); que.pop();
            que.push(P(x, j));
            j = p.second;
            x = p.first;
        }
        if(x < fib[i]){
            cout << "NO" << endl;
            return;
        }
        v[i] = j;
        x -= fib[i];
        que.push(P(x, j));
    }
    if(v.size() <= 2){
        cout << "YES" << endl;
        return;
    }
    if(v[0] == v[1]){
        cout << "NO" << endl;
        return;
    }
    if(v[1] == v[2]) swap(v[0], v[1]);
    for(int i = 0; i < idx; i++){
        if(v[i] == v[i+1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--) solve();
}