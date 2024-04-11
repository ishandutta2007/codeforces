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
#include <stack>
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

using P = pair<int, int>;

void solve(){
    int n; ll m; cin >> n >> m;
    vector<ll> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    vector<int> direction(n);
    vector<P> op, ep;
    for(int i = 0; i < n; i++){
        char c; cin >> c;
        if(c == 'L') direction[i] = -1;
        else direction[i] = 1;
        if(x[i]%2 == 0){
            ep.push_back(P(x[i], i));
        }else{
            op.push_back(P(x[i], i));
        }
    }
    vector<int> odd, even;
    sort(ep.begin(), ep.end());
    sort(op.begin(), op.end());
    for(auto [_, i]: ep) even.push_back(i);
    for(auto [_, i]: op) odd.push_back(i);
    vector<ll> ans(n, -1);
    auto process = [&](vector<int> v){
        stack<int> st;
        for(int i: v){
            if(st.empty()){
                st.push(i);
            }else{
                int j = st.top();
                if(direction[i] == -1){
                    st.pop();
                    if(direction[j] == -1){
                        ll t = (x[i]+x[j])/2;
                        ans[i] = t;
                        ans[j] = t;
                    }else{
                        ll t = (x[i]-x[j])/2;
                        ans[i] = t;
                        ans[j] = t;
                    }
                }else{
                    st.push(i);
                }
            }
        }
        v.clear();
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        int sz = v.size();
        for(int idx = 0; idx+1 < sz; idx+=2){
            int i = v[idx], j = v[idx+1];
            if(direction[i] == 1 && direction[j] == 1){
                ll t = (m-x[i]+m-x[j])/2;
                ans[i] = t;
                ans[j] = t;
            }else{
                ll t = (2*m-abs(x[i]-x[j]))/2;
                assert(direction[i] == 1);
                assert(direction[j] == -1);
                ans[i] = t;
                ans[j] = t;
            }
        }
    };
    process(odd);
    process(even);
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}