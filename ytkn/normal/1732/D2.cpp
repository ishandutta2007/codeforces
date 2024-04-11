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

const int TH = 1000;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int q; cin >> q;
    string s;
    vector<ll> xs;
    set<ll> st;
    st.insert(0);
    set<ll> ks;
    for(int i = 0; i < q; i++){
        char c; cin >> c;
        s += c;
        ll x; cin >> x;
        xs.push_back(x);
        if(c == '+'){
            st.insert(x);
        }else if(c == '-'){
            
        }else{
            ks.insert(x);
        }
    }
    map<ll, vector<ll>> divisible;
    for(ll k: ks){
        int cur = 1;
        while(true){
            if(st.count(k*cur) == 0){
                break;
            }
            ll x = k*cur;
            cur++;
            divisible[x].push_back(k);
        }
    }
    set<ll> many;
    for(auto &[x, v]: divisible) {
        sort(v.begin(), v.end());
        if(v.size() > TH) many.insert(x);
    }
    auto is_many = [&](ll x){
        if(divisible.count(x) == 0) return false;
        return divisible[x].size() > TH;
    };
    map<ll, set<ll>> not_exist;
    for(ll k: ks){
        int cur = 1;
        while(true){
            ll x = k*cur;
            if(!is_many(x)) not_exist[k].insert(x);
            if(st.count(k*cur) == 0){
                break;
            }
            cur++;
        }
    }
    for(int i = 0; i < q; i++){
        char c = s[i];
        ll x = xs[i];
        if(c == '+'){
            if(is_many(x)){
                many.erase(x);
            }else{
                for(ll k: divisible[x]){
                    not_exist[k].erase(x);
                }
            }
        }else if(c == '-'){
            if(is_many(x)){
                many.insert(x);
            }else{
                for(ll k: divisible[x]){
                    not_exist[k].insert(x);
                }
            }
        }else{
            ll ans = *(not_exist[x].begin());
            for(ll y: many){
                if(y%x == 0) chmin(ans, y);
            }
            cout << ans << endl;
        }
    }
}