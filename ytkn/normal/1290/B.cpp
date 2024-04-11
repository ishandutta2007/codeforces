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


template<typename T>
class Cumsum{
    public:
    Cumsum(vector<T> v): v(v){
        n = v.size();
        v_cumsum = vector<T>(n+1, T(0));
        for(int i = 0; i < n; i++) v_cumsum[i+1] = v_cumsum[i]+v[i];
    }
    /**
     * v[l] + ... + v[r-1]
     */ 
    T sum(int l, int r){
        if(r <= l) return T(0);
        if(r > n) r = n;
        if(l < 0) l = 0;
        return v_cumsum[r]-v_cumsum[l];
    }
    private:
    int n;
    vector<T> v;
    vector<T> v_cumsum;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string s; cin >> s;
    int q; cin >> q;
    int n = s.size();
    auto cnt = vec2d(26, n, 0);
    for(int i = 0; i < n; i++){
        cnt[s[i]-'a'][i]++;
    }
    vector<Cumsum<int>> cumsum(26, Cumsum<int>({0}));
    for(int i = 0; i < 26; i++){
        cumsum[i] = Cumsum<int>(cnt[i]);
    }
    while(q--){
        int l, r; cin >> l >> r; l--; r--;
        if(l == r){
            cout << "Yes" << endl;
            continue;
        }
       if(s[l] != s[r]){
           cout << "Yes" << endl;
           continue;
       }
       vector<int> v;
        for(int i = 0; i < 26; i++){
           int x = cumsum[i].sum(l, r+1);
           if(x > 0) v.push_back(x);
        }
        if(v.size() == 1){
            cout << "No" << endl;
            continue;
        }
        if(v.size() >= 3){
            cout << "Yes" << endl;
            continue;
        }
        cout << "No" << endl;
    }
}