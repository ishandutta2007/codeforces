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

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, m; cin >> n >> m;
    auto s = vec2d(n, m, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> s[i][j];
        }
    }
    vector<int> diff(n);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] != s[0][j]) diff[i]++;
        }
    }
    int max_diff = *max_element(diff.begin(), diff.end());
    if(max_diff >= 5){
        cout << "No" << endl;
        return 0;
    }
    if(max_diff <= 2){
        cout << "Yes" << endl;
        print_vector(s[0]);
        return 0;
    }
    auto calc = [&](int idx, int p, int q) -> vector<int>{
        vector<int> rem(n, 2);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == p || j == q) continue;
                if(s[idx][j] != s[i][j]) rem[i]--;
            }
            if(rem[i] < 0) return {};
        }
        vector<int> ans = s[idx];
        vector<vector<int>> v(2);
        for(int i = 0; i < n; i++){
            if(rem[i] == 2) continue;
            v[rem[i]].push_back(i);
        }
        if(v[0].size() > 0){
            int ii = v[0][0];
            ans[p] = s[ii][p];
            ans[q] = s[ii][q];
            for(int i: v[0]){
                if(s[i][p] != ans[p]) return {};
                if(s[i][q] != ans[q]) return {};
            }
            for(int i: v[1]){
                if(s[i][p] != ans[p] && s[i][q] != ans[q]) return {};
            }
            return ans;
        }
        assert(!v[1].empty());
        int ii = v[1][0];
        ans[p] = s[ii][p];
        ans[q] = s[ii][q];
        // iip
        {
            vector<int> ng;
            for(int i: v[1]){
                if(s[i][p] != ans[p]){
                    ng.push_back(s[i][q]);
                }
            }
            if(!ng.empty()){
                int x = ng[0];
                bool ok = true;
                for(int y: ng){
                    if(x != y) ok = false;
                }
                if(ok){
                    ans[q] = x;
                    return ans;
                }
            }else{
                return ans;
            }
        }
        // iiq
        vector<int> ng;
        for(int i: v[1]){
            if(s[i][q] != ans[q]){
                ng.push_back(s[i][p]);
            }
        }
        if(!ng.empty()){
            int x = ng[0];
            for(int y: ng){
                if(x != y) return {};
            }
            ans[p] = x;
            return ans;
        }else{
            return ans;
        }
    };
    int idx = -1;
    for(int i = 0; i < n; i++){
        if(diff[i] == max_diff) idx = i;
    }
    vector<int> v;
    for(int i = 0; i < m; i++){
        if(s[idx][i] != s[0][i]) v.push_back(i);
    }
    if(max_diff == 3){
        for(int s = 0; s < 8; s++){
            vector<int> u;
            for(int i = 0; i < 3; i++){
                if(s&(1<<i)) u.push_back(v[i]);
            }
            if(u.size() == 2){
                for(int i: {0, idx}){
                    auto ans = calc(idx, u[0], u[1]);
                    if(!ans.empty()){
                        cout << "Yes" << endl;
                        print_vector(ans);
                        return 0;
                    }
                }
            }
        }
    }
    if(max_diff == 4){
        for(int s = 0; s < 16; s++){
            vector<int> u;
            for(int i = 0; i < 4; i++){
                if(s&(1<<i)) u.push_back(v[i]);
            }
            if(u.size() == 2){
                auto ans = calc(0, u[0], u[1]);
                if(!ans.empty()){
                    cout << "Yes" << endl;
                    print_vector(ans);
                    return 0;
                }
            }
        }
    }
    cout << "No" << endl;
}