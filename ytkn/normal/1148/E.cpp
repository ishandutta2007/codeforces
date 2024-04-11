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

using P = pair<ll, int>;
using T = tuple<int, int, ll>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<P> s(n), t(n);
    ll s_sum = 0, t_sum = 0;
    for(int i = 0; i < n; i++){
        cin >> s[i].first; s[i].second = i;
        s_sum += s[i].first;
    }
    for(int i = 0; i < n; i++){
        cin >> t[i].first; t[i].second = i;
        t_sum += t[i].first;
    }
    if(s_sum != t_sum){
        cout << "NO" << endl;
        return 0;
    }
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    ll diff_sum = 0;
    for(int i = 0; i < n; i++){
        ll diff = t[i].first-s[i].first;
        diff_sum += diff;
        if(diff_sum < 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    vector<T> ans;
    vector<P> st;
    for(int j = 0; j < n; j++){
        ll diff = t[j].first-s[j].first;
        int i = s[j].second;
        if(diff > 0){
            st.push_back(P(diff, i));
        }
        if(diff < 0){
            while(true){
                auto [d, idx] = st.back(); st.pop_back();
                if(d >= -diff){
                    ans.push_back(T(idx, i, -diff));
                    ll rem = d+diff;
                    if(rem > 0) st.push_back(P(rem, idx));
                    break;
                }else{
                    ans.push_back(T(idx, i, d));
                    diff += d;
                }
            }
        }
    }
    cout << "YES\n";
    cout << ans.size() << '\n';
    for(auto [i, j, d]: ans) cout << i+1 << ' ' << j+1 << ' ' << d << '\n';
}