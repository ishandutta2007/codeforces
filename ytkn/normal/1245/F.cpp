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

ll solve_naive(int l, int r){
    ll ans = 0;
    for(int a = l; a <= r; a++){
        for(int b = l; b <= r; b++){
            if((a^b) == a+b) ans++;
        }
    }
    return ans;
}

ll pow3[31];

void init(){
    pow3[0] = 1;
    for(int i = 1; i <= 30; i++) pow3[i] = pow3[i-1]*3;
}

/**
 * 0 <= a < l, 0 <= b < r
 */ 
ll sub_solve(int l, int r){
    if(l > r) swap(l, r);
    if(l == 0) return 0;
    ll ans = 0;
    int m = 0;
    for(int i = 29; i >= 0; i--){
        if(l&(1<<i)){
            m = i;
            break;
        }
    }
    int x = 1<<m;
    int lm = l/x, lr = l%x;
    int rm = r/x, rr = r%x;
    ans += pow3[m]*lm*rm;
    if(rm%2 == 0){
        ans += sub_solve(lr, rr);
    }
    ans += sub_solve(x, rr);
    ans += sub_solve(x, lr)*((rm+1)/2);
    return ans;
}

ll solve(int l, int r){
    return sub_solve(r+1, r+1) - sub_solve(l, r+1)*2 + sub_solve(l, l);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    init();
    int t; cin >> t;
    while(t--){
        int l, r; cin >> l >> r;
        cout << solve(l, r) << endl;
    }
}