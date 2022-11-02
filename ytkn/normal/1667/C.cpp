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
using T = tuple<int, int>;

void verify(int n, vector<int> ans){
    auto ok = vec2d(n, n, false);
    int k = ans.size();
    for(int ii = 0; ii < k; ii++){
        int jj = ans[ii];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == ii) ok[i][j] = true;
                if(j == jj) ok[i][j] = true;
                if(i-j == ii-jj) ok[i][j] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!ok[i][j]){
                cout << "NOOOOO!" << endl;
                return;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    int k = (2*n+1)/3;
    int m = n-k;
    vector<int> ans(k, -1);
    if(k == 2*(n-k)-1){
        for(int i = 0; i < k; i++){
            ans[i] = (2*i)%k;
        }
    }else if(k == 2*(n-k)){
        for(int i = 0; i < k; i++){
            ans[i] = (2*i);
            if(ans[i] >= k){
                ans[i] -= k-1;
            }
        }
    }else{
        assert(k == 2*(n-k)+1);
        for(int i = 0; i < k; i++){
            ans[i] = (2*i);
            if(i == n-k) ans[i] += 2;
            ans[i] %= k;
        }
    }
    cout << k << endl;
    for(int i = 0; i < k; i++){
        cout << i+1 << ' ' << ans[i]+1 << endl;
    }
    // verify(n, ans);
}