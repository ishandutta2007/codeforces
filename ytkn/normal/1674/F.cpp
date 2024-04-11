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
    int n, m, q; cin >> n >> m >> q;
    vector<string> s(n);
    auto should_be_icon = vec2d(n, m, false);
    int icons = 0;
    int ans = 0;
    for(int i = 0; i < n; i++) cin >> s[i];
    auto to_index = [&](int i, int j){
        return j*n+i;
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == '*') icons++;
        }
    }
    auto ng = [&](int i, int j){
        return should_be_icon[i][j] && s[i][j] == '.';
    };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(to_index(i, j) < icons){
                should_be_icon[i][j] = true;
            }
            if(ng(i, j)) ans++;
        }
    }
    while(q--){
        int x, y; cin >> x >> y; x--; y--;
        if(s[x][y] == '*'){
            int j = (icons-1)/n, i = (icons-1)%n;
            if(i == x && j == y){
                if(ng(i, j)) ans--;
            }else{
                if(ng(i, j)) ans--;
                if(ng(x, y)) ans--;
            }
            icons--;
            s[x][y] = '.';
            should_be_icon[i][j] = false;
            if(i == x && j == y){
                if(ng(i, j)) ans++;
            }else{
                if(ng(i, j)) ans++;
                if(ng(x, y)) ans++;
            }
        }else{
            int j = (icons)/n, i = (icons)%n;
            if(i == x && j == y){
                if(ng(i, j)) ans--;
            }else{
                if(ng(i, j)) ans--;
                if(ng(x, y)) ans--;
            }
            icons++;
            s[x][y] = '*';
            should_be_icon[i][j] = true;
            if(i == x && j == y){
                if(ng(i, j)) ans++;
            }else{
                if(ng(i, j)) ans++;
                if(ng(x, y)) ans++;
            }
        }
        cout << ans << endl;
    }
}