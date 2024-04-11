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
    int k = -1, mx = -1;
    for(int l = 1; l <= n; l++){
        if(n%l == 0){
            int m = n/l;
            int tmp = (l-1)*(m-1);
            if(chmax(mx, tmp)) k = l;
        }else{
            int m = n/l;
            int r = (n%l)-1;
            int tmp = (l-1)*(m-1)+r;
            if(chmax(mx, tmp)) k = l;
        }
    }
    int cnt = 0;
    vector<bool> on(n, false);
    int prev_k = 0;
    auto turn_on = [&](vector<int> v){
        cout << v.size() << ' ';
        prev_k = v.size();
        for(int x: v) {
            cout << x+1 << ' ';
            if(!on[x]){
                on[x] = true;
                cnt++;
            }
        }
        cout << endl;
    };
    auto turn_off = [&](){
        int i; cin >> i; i--;
        for(int j = 0; j < prev_k; j++){
            int idx = (i+j)%n;
            if(on[idx]){
                on[idx] = false;
                cnt--;
            }
        }
    };
    vector<bool> should_flip(n, true);
    for(int i = 0; i < n; i++){
        if(i%k == 0) should_flip[i] = false;
    }
    while(cnt < mx){
        vector<int> v;
        for(int i = 0; i < n && v.size() < k; i++){
            if(should_flip[i] && !on[i]) v.push_back(i);
        }
        turn_on(v);
        turn_off();
    }
    cout << 0 << endl;
}