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

char to_char(int i){
    if(i < 10) return i+'0';
    if(i < 36) return i-10+'a';
    return i-36+'A';
}

void solve(){
    int r, c, k; cin >> r >> c >> k;
    vector<string> s(r);
    for(int i = 0; i < r; i++) cin >> s[i];
    int cnt = 0;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(s[i][j] == 'R') cnt++;
        }
    }
    auto nx = [&](int i, int j){
        if(i%2 == 0){
            j++;
            if(j == c){
                j--;
                i++;
            }
            return P(i, j);
        }else{
            j--;
            if(j == -1){
                j++;
                i++;
            }
            return P(i, j);
        }
    };
    vector<string> ans(r, string(c, '*'));
    int ii = 0, jj = 0;
    for(int i = 0; i < k-1; i++){
        int x = cnt/k;
        if(i < cnt%k) x++;
        while(true){
            ans[ii][jj] = to_char(i);
            if(s[ii][jj] == 'R') x--;
            auto [i, j] = nx(ii, jj);
            ii = i; jj = j;
            if(x == 0) break;
        }
    }
    while(true){
        ans[ii][jj] = to_char(k-1);
        auto [i, j] = nx(ii, jj);
        if(i == r) break;
        ii = i; jj = j;
    }
    print_vector(ans, '\n');
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}