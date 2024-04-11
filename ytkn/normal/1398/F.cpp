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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    string s; cin >> s;
    auto left_len = vec2d(n, 2, 0);
    auto right_len = vec2d(n, 2, 0);
    vector<vector<int>> indices(2);
    indices[0] = {-1};
    indices[1] = {-1};
    for(int i = 0; i < n; i++){
        if(s[i] == '0') indices[0].push_back(i);
        if(s[i] == '1') indices[1].push_back(i);
    }
    indices[0].push_back(n);
    indices[1].push_back(n);
    for(int i = 0; i < n; i++){
        if(s[i] == '0' || s[i] == '?'){
            auto p = lower_bound(indices[1].begin(), indices[1].end(), i);
            int l = *prev(p);
            int r = *p;
            left_len[i][0] = i-l;
            right_len[i][0] = r-i;
        }
        if(s[i] == '1' || s[i] == '?'){
            auto p = lower_bound(indices[0].begin(), indices[0].end(), i);
            int l = *prev(p);
            int r = *p;
            left_len[i][1] = i-l;
            right_len[i][1] = r-i;
        }
    }
    for(int x = 1; x <= n; x++){
        int ans = 0;
        int idx = 0;
        while(idx < n){
            bool ok = false;
            int nx = n;
            for(int a = 0; a < 2; a++){
                int len = left_len[idx][a]+right_len[idx][a]-1;
                if(len < x) continue;
                ok = true;
                if(left_len[idx][a] >= x){
                    chmin(nx, idx+x);
                }else{
                    chmin(nx, idx+2*x-left_len[idx][a]);
                }
            }
            if(ok) {
                ans++;
                idx = nx;
            }else{
                idx += x;
            }
        }
        cout << ans << ' ';
    }
    cout << endl;
}