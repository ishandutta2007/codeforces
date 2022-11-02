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
    int q; cin >> q;
    int last = 0;
    map<int, int> to_idx;
    vector<int> root;
    vector<int> cum_xor;
    vector<vector<int>> components;

    function<int(int)> get_root = [&](int idx){
        return root[idx];
    };

    function<int(int)> get_size = [&](int idx){
        return components[get_root(idx)].size();
    };

    while(q--){
        int t; cin >> t;
        if(t == 1){
            int l, r, x; cin >> l >> r >> x;
            l ^= last;
            r ^= last;
            x ^= last;
            if(l > r) swap(l, r); r++;
            if(to_idx.count(l) && to_idx.count(r)){
                int li = to_idx[l], ri = to_idx[r];
                int rl = get_root(li), rr = get_root(ri);
                if(rl == rr) continue;
                if(get_size(rl) < get_size(rr)){
                    swap(l, r);
                    swap(li, ri);
                    swap(rl, rr);
                }
                // r
                int xor_offset = cum_xor[li]^x^cum_xor[ri];
                for(int x: components[rr]){
                    cum_xor[x] ^= xor_offset;
                    components[rl].push_back(x);
                    root[x] = rl;
                }
                components[rr].clear();
                continue;
            }
            if(to_idx.count(l) == 0 && to_idx.count(r) == 0){
                int li = to_idx.size(); to_idx[l] = li;
                int ri = to_idx.size(); to_idx[r] = ri;
                root.push_back(li);
                root.push_back(li);
                cum_xor.push_back(0);
                cum_xor.push_back(x);
                components.push_back({li, ri});
                components.push_back({});
            }else{ // 
                if(to_idx.count(l) == 0){
                    swap(l, r);
                }
                // r
                int li = to_idx[l];
                int ri = to_idx.size(); to_idx[r] = ri;
                int rt = get_root(li);
                int xx = cum_xor[li]^x;
                components[rt].push_back(ri);
                components.push_back({{}});
                root.push_back(rt);
                cum_xor.push_back(xx);
            }
        }else{
            int l, r; cin >> l >> r;
            l ^= last;
            r ^= last;
            if(l > r) swap(l, r); r++;
            int ans = -1;
            if(to_idx.count(l) && to_idx.count(r)){
                int li = to_idx[l];
                int ri = to_idx[r];
                if(get_root(li) == get_root(ri)) ans = cum_xor[li]^cum_xor[ri];
            }
            cout << ans << '\n';
            if(ans == -1) last = 1;
            else last = ans;
        }
    }
}