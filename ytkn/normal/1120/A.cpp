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

using P = pair<int, int>;
const int M = 500000;
vector<int> indices[M+1];
vector<int> used[M+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int m, k, n, s; cin >> m >> k >> n >> s;
    vector<int> a(m), b(s);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        indices[a[i]].push_back(i);
    }
    for(int i = 0; i < s; i++) cin >> b[i];
    vector<int> ans;
    map<int, int> mp;    
    auto add = [&](int x){
        if(mp.count(x)) mp[x]++;
        else mp[x] = 1;
    };
    for(int x: b) add(x);
    auto rem = mp;
    auto del = [&](int x){
        rem[x]--;
        if(rem[x] == 0) rem.erase(x);
    };
    int idx = 0;
    int l = -1;
    while(!rem.empty() && idx < m){
        if(rem.count(a[idx])){
            if(l == -1) l = idx;
            del(a[idx]);
            used[a[idx]].push_back(idx);
        }
        idx++;
    }
    if(!rem.empty()){
        cout << -1 << endl;
        return 0;
    }
    auto ok = [&](int l, int r){
        if(r-l < k) r = l+k;
        int extra = (r-l)-k + l%k + (m-r)%k;
        return extra <= m-n*k;
    };
    auto make_ans = [&](int l, int r){
        if(r-l < k) r = l+k;
        vector<bool> used(m);
        int rem_xx = n-1;
        for(int i = 0; i < l; i+=k) {
            if(rem_xx > 0){
                rem_xx--;
                for(int j = i; j < i+k; j++) used[j] = true;
            }
        }
        auto rem = mp;
        auto del = [&](int x){
            rem[x]--;
            if(rem[x] == 0) rem.erase(x);
        };
        int cnt_extra = 0;
        for(int i = l; i < r; i++){
            if(rem.count(a[i])){
                del(a[i]);
                used[i] = true;
            }else{
                if(cnt_extra+s < k) {
                    used[i] = true;
                    cnt_extra++;
                }
            }
        }
        for(int i = r; i < m; i+=k) {
            if(rem_xx > 0){
                rem_xx--;
                for(int j = i; j < i+k; j++) used[j] = true;
            }
        }
        assert(rem_xx == 0);
        vector<int> ans;
        for(int i = 0; i < m; i++) {
            if(!used[i]) ans.push_back(i);
        }
        return ans;
    };
    int r = idx;
    for(int i = 0; i < m; i++){
        if(ok(i, r)){
            auto ans = make_ans(i, r);
            cout << ans.size() << endl;
            for(int idx: ans) cout << idx+1 << ' ';
            cout << endl;
            return 0;
        }
        if(mp.count(a[i])){
            int nx = [&](){
                if(used[a[i]].empty()){
                    auto p = upper_bound(indices[a[i]].begin(), indices[a[i]].end(), i);
                    return p == indices[a[i]].end() ? -1 : *p;
                }else{
                    auto p = upper_bound(indices[a[i]].begin(), indices[a[i]].end(), used[a[i]].back());
                    return p == indices[a[i]].end() ? -1 : *p;
                }
            }();
            if(nx == -1) break;
            used[a[i]].push_back(nx);
            chmax(r, nx+1);
        }
    }
    cout << -1 << endl;
}