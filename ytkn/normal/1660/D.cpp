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
    int l = 0, r = n;
    int mx = 0;
    int pre = 0;
    for(int i = 0; i < n; i++){
        if((a[i] == 0 && i != pre) || i == n-1){
            int cnt = 0;
            int cnt2 = 0;
            vector<int> vl(2, -1);
            vector<int> cntl(2, 0);
            vl[0] = pre;
            int rr = a[i] == 0 ? i-1 : i;
            for(int j = pre; j <= rr; j++){
                if(a[j] < 0) cnt ^= 1;
                if(abs(a[j]) >= 2) cnt2++;
                if(vl[cnt] == -1) {
                    vl[cnt] = j+1;
                    cntl[cnt] = cnt2;
                }
                if(chmax(mx, cnt2-cntl[cnt])){
                    // cout << vl[cnt] << ',' << j << endl;
                    l = vl[cnt];
                    r = n-(j+1);
                }
            }
        }
        if(a[i] == 0){
            pre = i+1;
        }
    }
    cout << l << ' ' << r << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}