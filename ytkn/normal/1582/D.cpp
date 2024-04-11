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
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    auto verify = [&](){
        ll sum = 0;
        for(int i = 0; i < n; i++) sum += a[i]*b[i];
        for(int i = 0; i < n; i++){
            assert(b[i] != 0);
        }
        assert(accumulate(b.begin(), b.end(), 0ll) <= (int)1e9);
        assert(sum == 0);
    };
    if(n%2 == 0){
        for(int i = 0; i < n; i+=2){
            b[i] = a[i+1];
            b[i+1] = -a[i];
        }
        print_vector(b);
        verify();
        return;
    }
    vector<bool> used(n);
    vector<int> pos, neg;
    for(int i = 0; i < n; i++){
        if(a[i] < 0) neg.push_back(i);
        else pos.push_back(i);
    }
    int i = -1, j = -1, k = -1;
    if(pos.size() >= 2){
        i = pos[0], k = pos[1];
        j = neg.empty() ? pos[2] : neg[0];
    }else{
        i = neg[0], k = neg[1];
        j = pos.empty() ? neg[2] : pos[0];
    }
    used[i] = true; used[j] = true; used[k] = true;
    if(a[i] == a[k]){
        if(a[j] == -1){
            b[i] = a[j]+2; b[j] = -a[i]; b[k] = -2;
        }else{
            b[i] = a[j]+1; b[j] = -a[i]; b[k] = -1;
        }
    }else{
        b[i] = a[j]; b[j] = a[k]-a[i]; b[k] = -a[j];
    }
    vector<int> indices;
    for(int i = 0; i < n; i++){
        if(!used[i]) indices.push_back(i);
    }
    int m = indices.size();
    for(int i = 0; i < m; i+=2){
        int j = indices[i], k = indices[i+1];
        b[j] = a[k];
        b[k] = -a[j];
    }
    verify();
    print_vector(b);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}