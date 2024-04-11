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
    int n, m; cin >> n >> m;
    vector<int> x(n), y(n), prev_event(n, -1);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    int sq = sqrt(m)/2;
    auto add_small = vec2d(sq+1, sq, 0);
    
    vector<int> op(m), k(m);
    for(int i = 0; i < m; i++){
        cin >> op[i] >> k[i]; k[i]--;
    }
    vector<int> add(m);
    int ans = 0;
    for(int i = 0; i < m; i++){
        int cycle = x[k[i]]+y[k[i]];
        // print_vector(add);
        if(op[i] == 1){
            if(cycle <= sq){
                add_small[cycle][(i+x[k[i]])%cycle]++;
                add_small[cycle][i%cycle]--;
                // print_vector(add_small[cycle]);
                ans++;
            }else{
                for(int j = 1; i+j*cycle < m; j++) add[i+j*cycle]--;
                for(int j = 0; i+j*cycle+x[k[i]] < m; j++) add[i+j*cycle+x[k[i]]]++;
            }
        }else{
            int pe = prev_event[k[i]];
            if(pe != -1 && op[pe] == 1){
                if((i-pe-1)%cycle >= x[k[i]]){ // 
                    ans--;
                }
            }
            if(cycle <= sq){
                add_small[cycle][(pe+x[k[i]])%cycle]--;
                add_small[cycle][pe%cycle]++;
            }else{
                for(int j = 1; pe+j*cycle < m; j++) add[pe+j*cycle]++;
                for(int j = 0; pe+j*cycle+x[k[i]] < m; j++) add[pe+j*cycle+x[k[i]]]--;
            }
        }
        // print_vector(add);
        ans += add[i];
        for(int j = 2; j <= sq; j++){
            int r = i%j;
            ans += add_small[j][r]; 
        }
        cout << ans << endl;
        prev_event[k[i]] = i;
    }
}