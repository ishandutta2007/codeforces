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

void solve(){
    int n; cin >> n;
    vector<int> a(n);
    vector<vector<int>> indices(n);
    map<int, int> count;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        if(count.count(a[i]) == 0){
            count[a[i]] = 1;
        }else{
            count[a[i]]++;
        }
        indices[a[i]].push_back(i);
    }
    vector<int> ans(n);
    while(!count.empty()){
        vector<int> iv;
        vector<int> erased;
        for(auto [x, c]: count){
            assert(indices[x].size() == c);
            iv.push_back(indices[x].back());
            indices[x].pop_back();
            if(c == 1){
                erased.push_back(x);
            }
        }
        for(int x: erased) count.erase(x);
        for(auto [x, c]: count) count[x]--;
        int m = iv.size();
        for(int i = 0; i < m; i++){
            int ii = iv[i];
            int jj = iv[(i+1)%m];
            ans[ii] = a[jj]+1;
        }
    }
    print_vector(ans);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}