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
    int n, k; cin >> n >> k;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];
    vector<int> ans(1<<20);
    auto ok = vec2d(30, 30, false);
    auto memo = vec2d(30, 30, 0);
    auto sub_solve = [&](int rem, int kk){
        int dn = n-rem;
        int dk = k-kk;
        if(ok[dn][dk]) return memo[dn][dk];
        for(int i = kk; i <= rem; i++){
            if((rem&i) == i) memo[dn][dk] ^= 1;
        }
        ok[dn][dk] = true;
        return memo[dn][dk];
    };
    for(int l = 0; l < n; l++){
        ll x = b[l];
        for(int r = l+1; r <= n; r++){
            int rem = n-1-(r-1-l);
            int kk = k;
            if(l != 0) {
                rem--;
                kk--;
            }
            if(r != n) {
                rem--;
                kk--;
            }
            if(kk < 0) kk = 0;
            if(sub_solve(rem, kk) == 1) {
                ans[x] ^= 1;
            }
            if(r != n) {
                for(int i = 0; i < b[r]; i++){
                    x *= 2;
                    if(x >= (1<<20)) break;
                }
            }
            if(x >= (1<<20)) break;
        }
    }
    while(ans.size() > 1 && ans.back() == 0){
        ans.pop_back();
    }
    reverse(ans.begin(), ans.end());
    for(int x: ans) cout << x;
    cout << endl;
}