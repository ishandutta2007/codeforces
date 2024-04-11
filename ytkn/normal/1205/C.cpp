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

class Simulator{
    public:
    int n;
    Simulator(int n): n(n) {

    }
    private:
    vector<vector<int>> data;
};

#define DEBUG

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    auto ask = [&](int x1, int y1, int x2, int y2){
        if(x1 > x2 || y1 > y2){
            swap(x1, x2);
            swap(y1, y2);
        }
        cout << "? " << x1+1 << ' ' << y1+1 << ' ' << x2+1 << ' ' << y2+1 << endl;
        int ans; cin >> ans;
        return ans;
    };
    auto verify = [&](vector<vector<int>> ans){
        cout << "!" << endl;
        for(auto v: ans){
            for(int x: v) cout << x;
            cout << endl;
        }
    };
    int n; cin >> n;
    auto ans = vec2d(n, n, 0);
    ans[0][0] = 1;
    ans[n-1][n-1] = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((i+j)%2 == 1) continue;
            if(i == 0 && j == 0) continue;
            int ii = -1, jj = -1;
            if(i == 0){
                ii = i; jj = j-2;
            }else if(j == 0){
                ii = i-2; jj = j;
            }else{
                ii = i-1; jj = j-1;
            }
            if(ask(ii, jj, i, j) == 1){
                ans[i][j] = ans[ii][jj];
            }else{
                ans[i][j] = ans[ii][jj]^1;
            }
        }
    }

    for(int i = 0; i < n; i++){
        vector<int> v;
        if(i == 0){
            for(int j = 0; j < n; j++) v.push_back(j);
        }else{
            for(int j = n-1; j >= 0; j--) v.push_back(j);
        }
        for(int j: v){
            if((i+j)%2 == 0) continue;
            if(i == 0 && j == 1) continue;
            int ii = -1, jj = -1;
            if(i == 0){
                ii = i; jj = j-2;
            }else if(j+2 >= n){
                ii = i-1; jj = j-1;
            }else{
                ii = i; jj = j+2;
            }
            if(ask(ii, jj, i, j) == 1){
                ans[i][j] = ans[ii][jj];
            }else{
                ans[i][j] = ans[ii][jj]^1;
            }
        }
    }

    auto ok = [&](int i, int j, int s){
        vector<int> v = {ans[i][j]};
        for(int k = 0; k < 3; k++){
            if(s&(1<<k)) i++;
            else j++;
            if(i >= n || j >= n) return false;
            v.push_back(ans[i][j]);
        }
        if(v[0] != v[2] && v[1] != v[3]) return true;
        if(v[0] == v[2] && v[1] == v[3]) return true;
        return false;
    };
    auto flip = [&](){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int s = 0; s < 8; s++){
                    if(ok(i, j, s)){
                        int ii = i, jj = j;
                        for(int k = 0; k < 3; k++){
                            if(s&(1<<k)) ii++;
                            else jj++;
                        }
                        bool should_flip = (ans[i][j] == ans[ii][jj]) != (ask(i, j, ii, jj) == 1);
                        return should_flip;
                    }
                }
            }
        }
    }();
    if(flip){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if((i+j)%2 == 0) continue;
                ans[i][j] = ans[i][j]^1;
            }
        }
    }
    verify(ans);
}