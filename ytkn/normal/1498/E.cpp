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
using T = tuple<int, int, int>;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> k(n);
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }
    vector<bool> ng(n, false);
    int rem = n;
    while(true){
        int x = -1;
        for(int i = 0; i < n; i++){
            if(ng[i]) continue;
            if(k[i] == 0){
                x = i;
                break;
            }
        }
        if(x != -1){
            ng[x] = true;
            for(int i = 0; i < n; i++){
                if(!ng[i]) k[i]--;
            }
            rem--;
            continue;
        }

        x = -1;
        for(int i = 0; i < n; i++){
            if(ng[i]) continue;
            if(k[i] == rem-1){
                x = i;
                break;
            }
        }
        if(x == -1) break;
        ng[x] = true;
        rem--;
    }
    for(int i = 0; i < n; i++){
        if(ng[i]) k[i] = 0;
    }
    int k_sum = accumulate(k.begin(), k.end(), 0);
    if(k_sum <= 0){
        cout << "! " << 0 << ' ' << 0 << endl;
        return 0;
    }
    int max_k = *max_element(k.begin(), k.end());
    if(max_k == 1){
        vector<int> v;
        for(int i = 0; i < n; i++){
            if(!ng[i]) v.push_back(i);
        }
        cout << "! " << v[0]+1 << ' ' << v[1]+1 << endl;
        return 0;
    }
    vector<T> vt;
    for(int i = 0; i < n; i++){
        if(ng[i]) continue;
        for(int j = 0; j < n; j++){
            if(ng[j]) continue;
            if(i == j) continue;
            if(k[j] <= k[i]) vt.push_back(T(k[i]-k[j], i, j));
        }
    }
    sort(vt.begin(), vt.end(), greater<T>());
    for(auto [d, i, j]: vt){
        cout << "? " << i+1 << ' ' << j+1 << endl;
        string ans; cin >> ans;
        if(ans == "Yes"){
            cout << "! " << j+1 << ' ' << i+1 << endl;
            return 0;
        }
    }
}