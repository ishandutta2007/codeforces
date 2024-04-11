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
    int n, p; cin >> n >> p;
    string s; cin >> s;
    vector<vector<int>> indices(p);
    for(int i = 0; i < n; i++){
        indices[s[i]-'a'].push_back(i);
    }
    auto a = vec2d(p, p, 0);
    for(int i = 0; i < p; i++){
        for(int j = 0; j < p; j++){
            cin >> a[i][j];
        }
    }
    if(p <= 2){
        cout << 0 << endl;
        return 0;
    }
    auto nx = vec2d(n, p, n);
    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < p; j++){
            nx[i][j] = nx[i+1][j];
        }
        nx[i][s[i+1]-'a'] = i+1;
    }
    auto cumsum = vec2d(p, n+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++) cumsum[j][i+1] = cumsum[j][i];
        cumsum[s[i]-'a'][i+1]++;
    }
    auto sum = [&](int i, int l, int r){
        return cumsum[i][r]-cumsum[i][l];
    };
    vector<bool> ok(1<<p, true);
    vector<bool> ng(1<<(p-2));
    auto f = [&](int i, int j){
        for(int l: indices[i]){
            int r = nx[l][j];
            if(r == n) continue;
            assert(r > l);
            int idx = 0;
            int s = 0;
            for(int k = 0; k < p; k++){
                if(k == i || k == j) continue;
                if(sum(k, l, r) == 0){
                    s += 1<<idx;
                }
                idx++;
            }
            ng[s] = true;
        }
    };
    for(int i = 0; i < p; i++){
        for(int j = i+1; j < p; j++){
            if(a[i][j] == 1) continue;
            f(i, j);
            f(j, i);
            // print_vector(ng);
            for(int s = (1<<(p-2))-1; s >= 0; s--){
                if(!ng[s]) continue;
                for(int k = 0; k < p; k++){
                    if(s&(1<<k)) ng[s-(1<<k)] = true;
                }
            }
            vector<int> original_pos(p-2);
            int idx = 0;
            for(int k = 0; k < p; k++){
                if(k == i || k == j){
                    continue;
                }
                original_pos[idx] = k;
                idx++;
            }
            
            for(int s = 0; s < (1<<(p-2)); s++){
                if(ng[s]){
                    int t = (1<<i) + (1<<j);
                    for(int k = 0; k < p-2; k++){
                        if(s&(1<<k)) t += 1<<original_pos[k];
                    }
                    ok[t] = false;
                }
            }
            ng.assign(1<<(p-2), false);
        }
    }
    ng.assign(1<<(p-1), false);
    for(int i = 0; i < p; i++){
        if(a[i][i] == 1) continue;
        f(i, i);
        for(int s = (1<<(p-1))-1; s >= 0; s--){
            if(!ng[s]) continue;
            for(int k = 0; k < p; k++){
                if(s&(1<<k)) ng[s-(1<<k)] = true;
            }
        }
        vector<int> original_pos(p-1);
        int idx = 0;
        for(int k = 0; k < p; k++){
            if(k == i){
                continue;
            }
            original_pos[idx] = k;
            idx++;
        }
        for(int s = 0; s < (1<<(p-1)); s++){
            if(ng[s]){
                int t = (1<<i);
                for(int k = 0; k < p-1; k++){
                    if(s&(1<<k)) t += 1<<original_pos[k];
                }
                ok[t] = false;
            }
        }
        ng.assign(1<<(p-1), false);
    }
    vector<bool> dp(1<<p);
    dp.back() = true;
    int ans = n;
    for(int s = (1<<p)-1; s >= 0; s--){
        if(!dp[s]) continue;
        int len = 0;
        for(int i = 0; i < p; i++){
            if((s&(1<<i)) == 0) continue;
            len += indices[i].size();
            if(ok[s-(1<<i)]) dp[s-(1<<i)] = true;
        }
        chmin(ans, len);
    }
    cout << ans << endl;
}