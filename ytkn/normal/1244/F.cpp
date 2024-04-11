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

const int inf = 2e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<bool> is_fixed(n);
    for(int i = 0; i < n; i++){
        int l = (i+n-1)%n;
        int r = (i+n+1)%n;
        if(s[i] == s[l]) is_fixed[i] = true;
        if(s[i] == s[r]) is_fixed[i] = true;
    }
    if(!any_of(is_fixed.begin(), is_fixed.end(), [](bool x){ return x; })){
        if(k%2 == 0) cout << s << endl;
        else{
            string ans;
            for(int i = 0; i < n; i++){
                if(s[i] == 'W') ans += 'B';
                else ans += 'W';
            }
            cout << ans << endl;
        }
        return 0;
    }
    vector<int> dist(n, inf);
    string ans = s;
    queue<int> que;
    auto set_dist = [&](int i, int d){
        if(dist[i] == inf){
            dist[i] = d;
            que.push(i);
            return true;
        }
        return false;
    };
    for(int i = 0; i < n; i++){
        if(is_fixed[i]){
            set_dist(i, 0);
        }
    }
    while(!que.empty()){
        int i = que.front(); que.pop();
        if(dist[i] == k) continue;
        int l = (i-1+n)%n;
        int r = (i+1+n)%n;
        if(set_dist(l, dist[i]+1)) ans[l] = ans[i];
        if(set_dist(r, dist[i]+1)) ans[r] = ans[i];
    }
    for(int i = 0; i < n; i++){
        if(dist[i] == inf){
            if(k%2 == 1){
                ans[i] = s[i] == 'W' ? 'B' : 'W';
            }else{
                ans[i] = s[i];
            }
        }
    }
    cout << ans << endl;
}