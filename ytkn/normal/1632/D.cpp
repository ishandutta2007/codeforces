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
#include <stack>

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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    stack<P> st;
    vector<int> ans;
    int cur = 0;
    auto ok = [&](int a) -> bool {
        assert(a != 1);
        int x = 1;
        vector<P> vp;
        while(!st.empty()){
            auto [cnt, v] = st.top(); st.pop();
            int g = gcd(v, a);
            int l = x+1;
            int r = l+cnt;
            if(l <= g && g < r) return false;
            x += cnt;
            vp.push_back(P(cnt, v));
        }
        while(!vp.empty()){
            auto p = vp.back(); vp.pop_back();
            st.push(p);
        }
        return true;
    };
    auto add = [&](int a) {
        assert(a != 1);
        int x = 1;
        vector<P> vp;
        vp.push_back(P(1, a));
        while(!st.empty()){
            auto [cnt, x] = st.top(); st.pop();
            vp.push_back(P(cnt, gcd(x, a)));
        }
        while(!vp.empty()){
            auto p = vp.back(); vp.pop_back();
            if(st.empty()){
                st.push(p);
                continue;
            }
            auto [c1, x1] = st.top();
            auto [c2, x2] = p;
            if(x1 == x2){
                st.pop();
                st.push(P(c1+c2, x1));
            }else{
                st.push(p);
            }
        }
    };
    for(int i = 0; i < n; i++){
        if(a[i] == 1){
            cur++;
            ans.push_back(cur);
            while(!st.empty()) st.pop();
            continue;
        }
        if(ok(a[i])){
            ans.push_back(cur);
            add(a[i]);
        }else{
            cur++;
            ans.push_back(cur);
            while(!st.empty()) st.pop();
        }
    }
    print_vector(ans);
}