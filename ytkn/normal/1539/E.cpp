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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    vector<int> k(n), al(n), bl(n), ar(n), br(n);
    cin >> k[0] >> al[0] >> bl[0] >> ar[0] >> br[0];
    auto ok = [&](int l, int r, int i){
        return al[i] <= l && l <= bl[i] && ar[i] <= r && r <= br[i];
    };
    set<P> l_latest, r_latest; // (, index)
    map<P, P> prev_state; // (index, index)
    if(ok(k[0], 0, 0)){
        l_latest.insert(P(0, -1));
        prev_state[P(0, -1)] = P(-1, -1);
    }
    if(ok(0, k[0], 0)){
        r_latest.insert(P(0, -1));
        prev_state[P(-1, 0)] = P(-1, -1);
    }
    for(int i = 1; i < n; i++){
        cin >> k[i] >> al[i] >> bl[i] >> ar[i] >> br[i];
        bool ok_lr = false;
        P lr_prev;
        // l => r
        if(ok(k[i-1], k[i], i) && !l_latest.empty()){
            ok_lr = true;
            lr_prev = P(i-1, l_latest.begin()->second);
        }
        // l => l
        if(al[i] <= k[i] && k[i] <= bl[i]){
            while(!l_latest.empty()){
                int r_val = l_latest.begin()->first;
                if(!ok(k[i], r_val, i)){
                    l_latest.erase(l_latest.begin());
                }else{
                    break;
                }
            }
            while(!l_latest.empty()){
                auto p = l_latest.end(); p--;
                int r_val = p->first;
                if(!ok(k[i], r_val, i)){
                    l_latest.erase(p);
                }else{
                    break;
                }
            }
        }else{ // l
            l_latest.clear();
        }
        
        // r => l
        bool ok_rl = false;
        P rl_prev;
        if(ok(k[i], k[i-1], i) && !r_latest.empty()){
            ok_rl = true;
            rl_prev = P(r_latest.begin()->second, i-1);
        }
        // r => r
        if(ar[i] <= k[i] && k[i] <= br[i]){
            while(!r_latest.empty()){
                int l_val = r_latest.begin()->first;
                if(!ok(l_val, k[i], i)){
                    r_latest.erase(r_latest.begin());
                }else{
                    break;
                }
            }
            while(!r_latest.empty()){
                auto p = r_latest.end(); p--;
                int l_val = p->first;
                if(!ok(l_val, k[i], i)){
                    r_latest.erase(p);
                }else{
                    break;
                }
            }
        }else{ // r
            r_latest.clear();
        }

        // 
        if(ok_lr){
            prev_state[P(i-1, i)] = lr_prev;
            // cout << lr_prev.first << ',' << lr_prev.second << endl;
            r_latest.insert(P(k[i-1], i-1));
        }
        if(ok_rl){
            // cout << rl_prev.first << '-' << rl_prev.second << endl;
            prev_state[P(i, i-1)] = rl_prev;
            l_latest.insert(P(k[i-1], i-1));
        }
    }
    vector<int> ans(n);
    auto make_answer = [&](P last){
        auto cur = last;
        while(true){
            auto [l, r] = cur;
            // cout << l << ' ' << r << endl;
            if(l == -1 && r == -1) break;
            if(r > l){
                ans[r] = 1;
                if(r == l+1){
                    cur = prev_state[cur];
                }else{
                    cur = P(l, r-1);
                }
            }else{
                ans[l] = 0;
                assert(r < l);
                if(l == r+1){
                    cur = prev_state[cur];
                }else{
                    cur = P(l-1, r);
                }
            }
        }
        // int l = 0, r = 0;
        // for(int i = 0; i < n; i++){
        //     if(ans[i] == 0) l = k[i];
        //     else r = k[i];
        //     cout << al[i] << "<=" << l << "<=" << bl[i] << " && " << ar[i] << "<=" << r << "<=" << br[i] << endl;
        // }
    };
    if(!l_latest.empty()){
        cout << "Yes" << endl;
        int r = l_latest.begin()->second;
        make_answer(P(n-1, r));
        print_vector(ans);
        return 0;
    }
    if(!r_latest.empty()){
        cout << "Yes" << endl;
        int l = r_latest.begin()->second;
        make_answer(P(l, n-1));
        print_vector(ans);
        return 0;
    }
    cout << "No" << endl;
}