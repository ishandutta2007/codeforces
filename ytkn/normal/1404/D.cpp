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
    if(n%2 == 0){
        cout << "First" << endl;
        vector<int> ans(2*n);
        for(int i = 0; i < 2*n; i++){
            ans[i] = (i%n)+1;
        }
        print_vector(ans);
        return 0;
    }
    cout << "Second" << endl;
    vector<vector<int>> v(n);
    for(int i = 1; i <= 2*n; i++){
        int a; cin >> a; a--;
        v[a].push_back(i);
    }
    vector<int> p(2*n+1);
    for(int i = 0; i < n; i++){
        p[v[i][0]] = v[i][1];
        p[v[i][1]] = v[i][0];
    }
    vector<bool> seen(n+1);
    vector<int> ans;
    for(int x = 1; x <= n; x++){
        if(seen[x]) continue;
        int cur = x;
        while(!seen[cur%n]){
            ans.push_back(cur);
            seen[cur%n] = true;
            if(p[cur] <= n){
                cur = p[cur]+n;
            }else{
                cur = p[cur]-n;
            }
        }
    }
    ll sum = accumulate(ans.begin(), ans.end(), 0ll);
    if(sum%(2*n) == 0){
        print_vector(ans);
    }else{
        for(int x: ans){
            if(x <= n) cout << x+n << ' ';
            else cout << x-n << ' ';
        }
        cout << endl;
    }
}