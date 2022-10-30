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

const int N = 300005;
int a[N];
int next_nearest[N][20];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, q; cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 20; j++){
            next_nearest[i][j] = n;
        }
    }
    vector<int> nx(20, n);
    for(int i = 0; i < 20; i++){
        if(a[n-1]&(1<<i)) nx[i] = n-1;
    }

    for(int i = n-2; i >= 0; i--){
        for(int j = 0; j < 20; j++){
            if(a[i]&(1<<j)){
                int l = nx[j];
                if(l == n) continue;
                for(int k = 0; k < 20; k++){
                    if(a[l]&(1<<k)) {
                        chmin(next_nearest[i][k], l);
                    }else{
                        chmin(next_nearest[i][k], next_nearest[l][k]);
                    }
                }
            }
        }

        for(int j = 0; j < 20; j++){
            if(a[i]&(1<<j)) nx[j] = i;
        }
    }

    while(q--){
        int x, y; cin >> x >> y; x--; y--;
        bool ok = false;
        for(int i = 0; i < 20; i++){
            if((a[y]&(1<<i)) == 0) continue;
            if(next_nearest[x][i] <= y) ok = true;
        }
        if(ok) cout << "Shi" << '\n';
        else cout << "Fou" << '\n';
    }
}