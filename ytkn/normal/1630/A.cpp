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

using Pvv = pair<vector<int>, vector<int>>;

void solve(){
    int n, k; cin >> n >> k;
    if(n == 4 && k == 3){
        cout << -1 << endl;
        return;
    }
    int mask = n-1;
    if(k == n-1){
        cout << n-1 << ' ' << n-2 << endl;
        cout << n-3 << ' ' << 3 << endl;
        cout << n-4 << ' ' << 2 << endl;
        cout << 0 << ' ' << 1 << endl;
        int sum = 0;
        for(int x = 4; x < n/2; x++){
            cout << x << ' ' << n-1-x << endl;
            sum += x&(n-1-x);
        }
        sum += (n-1)&(n-2);
        sum += (n-3)&(3);
        sum += (n-4)&(2);
        // debug_value(sum);
    }else{
        vector<int> p(n);
        for(int i = 0; i < n/2; i++){
            p[i] = mask^i;
            p[mask^i] = i;
        }
        swap(p[0], p[k]);
        swap(p[mask], p[k^mask]);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            if(i < p[i]) {
                sum += (p[i]&i);
                cout << i << ' ' << p[i] << endl;
            }
        }
        // debug_value(sum)
    }
}

void test(int n){
    set<int> st;
    vector<int> v;
    for(int i = 0; i < n; i++) v.push_back(i);
    do{
        int sum = 0;
        for(int i = 0; i < n; i+=2){
            sum += v[i]&v[i+1];
        }
        if(sum < n) st.insert(sum);
    }while(next_permutation(v.begin(), v.end()));
    for(int x: st) cout << x << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}