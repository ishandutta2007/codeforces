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

using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;

void solve(){
    int n; ll m, c, c0; cin >> n >> m >> c >> c0;
    vector<T> waters;
    for(int i = 0; i < n; i++){
        ll t, a, b; cin >> t >> a >> b;
        waters.push_back(T(t, a, b));
    }
    sort(waters.begin(), waters.end());
    multiset<P> stored;
    stored.insert(P(0, c0));
    ll sum = c0;
    auto dispose = [&](){
        while(sum > c){
            auto p = *prev(stored.end());
            auto [price, volume] = p;
            stored.erase(stored.find(P(p)));
            if(sum-volume > c){
                sum -= volume;
                continue;
            }
            if(volume-(sum-c) > 0) stored.insert(P(price, volume-(sum-c)));
            sum = c;
            break;
        }
    };
    ll ans = 0;
    auto consume = [&](ll amount) -> bool{
        while(amount > 0 && !stored.empty()){
            auto p = *stored.begin();
            auto [price, volume] = p;
            stored.erase(stored.find(P(p)));
            if(volume >= amount){
                if(volume > amount) stored.insert(P(price, volume-amount));
                ans += price*amount;
                sum -= amount;
                amount = 0;
                break;
            }
            ans += price*volume;
            amount -= volume;
            sum -= volume;
        }
        return amount == 0;
    };
    ll prev_time = 0;
    for(auto [t, a, b]: waters){
        if(!consume(t-prev_time)){
            cout << -1 << '\n';
            return;
        }
        stored.insert(P(b, a));
        sum += a;
        dispose();
        prev_time = t;
    }
    if(!consume(m-prev_time)){
        cout << -1 << '\n';
    }else{
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}