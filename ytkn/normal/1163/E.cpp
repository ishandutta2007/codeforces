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

int msb(int x){
    for(int i = 30; i >= 0; i--){
        if(x&(1<<i)) return i;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> s(n);
    int s_or = 0;
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        s_or |= s[i];
    }
    int m = msb(s_or);
    auto f = [&](int m) -> vector<int>{
        int mx = (1<<(m+1))-1;
        vector<bool> ok(mx+1);
        ok[0] = true;
        vector<int> basis;
        for(int i = 0; i < n; i++){
            if(s[i] > mx) continue;
            if(ok[s[i]]) continue;
            basis.push_back(s[i]);
            for(int x = 0; x <= mx; x++){
                if(ok[x]) ok[x^s[i]] = true;
            }
        }
        for(int x = 0; x <= mx; x++) {
            if(!ok[x]) return {};
        }
        vector<int> gray = {0};
        for(int i = 0; i <= m; i++){
            vector<int> uu = gray;
            reverse(gray.begin(), gray.end());
            for(int x: gray){
                uu.push_back(x^(1<<i));
            }
            gray = uu;
        }
        vector<int> ans(mx+1);
        for(int i = 0; i <= mx; i++){
            for(int j = 0; j <= m; j++){
                if(gray[i]&(1<<j)) ans[i] ^= basis[j];
            }
        }
        return ans;
    };
    for(int m = msb(s_or); m >= 0; m--){
        auto ans = f(m);
        if(ans.empty()) continue;
        cout << m+1 << endl;
        print_vector(ans);
        return 0;
    }
    cout << 0 << endl;
    cout << 0 << endl;
}