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

int cnt[100000];
int sum[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> u(n);
    for(int i = 0; i < n; i++) {
        cin >> u[i]; u[i]--;
    }
    int tp = 0;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(cnt[u[i]] == 0){
            tp++;
        }else{
            sum[cnt[u[i]]]--;
        }
        cnt[u[i]]++;
        sum[cnt[u[i]]]++;
        bool ok = false;
        if(sum[1] == i+1){
            ok = true;
        }
        if(tp > 1 && (i%(tp-1)) == 0){ // 1
            int x = i/(tp-1);
            if(sum[1] == 1 && sum[x] == tp-1) ok = true;
        }
        if(tp != 0 && (i%tp) == 0){ // x+1
            int x = i/tp;
            if(sum[x+1] == 1 && sum[x] == tp-1) ok = true;
        }
        if(ok) ans = i+1;
    }
    cout << ans << endl;
}