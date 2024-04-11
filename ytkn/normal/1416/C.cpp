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

ll invs[30][2];

void solve(vector<int> a, int d){
    if(a.empty()) return;
    if(d == -1) return;
    vector<int> al, ar;
    int n = a.size();
    vector<int> cnt(2);
    for(int x: a){
        int y = x&(1<<d) ? 1 : 0;
        if(y == 1){
            invs[d][1] += cnt[0];
            ar.push_back(x);
        }else{
            invs[d][0] += cnt[1];
            al.push_back(x);
        }
        cnt[y]++;
    }
    // print_vector(cnt);
    solve(al, d-1);
    solve(ar, d-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    solve(a, 29);
    int ans = 0;
    ll inv = 0;
    for(int i = 0; i < 30; i++){
        if(invs[i][0] > invs[i][1]) ans += (1<<i);
        inv += min(invs[i][0], invs[i][1]);
    }
    cout << inv << ' ' << ans << endl;
}