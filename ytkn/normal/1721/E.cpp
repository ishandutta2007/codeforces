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
    cout << v.back() << '\n';
}

/**
 * https://cp-algorithms.com/string/prefix-function.html#second-optimization
 */
vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// reference: https://potetisensei.hatenablog.com/entry/2017/07/10/174908
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string S; cin >> S;
    int n = S.size();
    vector<int> A(n+11);
    A[0] = -1;
    int j = -1;
    for (int i = 0; i < S.size(); i++) {
        while (j >= 0 && S[i] != S[j]) j = A[j];

        j++;
        if (S[i+1] == S[j]) A[i+1] = A[j]; 
        else A[i+1] = j;
    }
    int q; cin >> q;
    while(q--){
        string t; cin >> t;
        S += t;
        int jj = j;
        for(int i = n; i < S.size(); i++){
            while (j >= 0 && S[i] != S[j]) j = A[j];

            j++;
            if (S[i+1] == S[j]) A[i+1] = A[j]; 
            else A[i+1] = j;
        }
        
        int pre = 0;
        vector<int> ans;
        for(int i = n+t.size(); i >= n+1; i--) {
            pre = max(pre-1, A[i]);
            ans.push_back(pre);
        }
        reverse(ans.begin(), ans.end());
        print_vector(ans);
        for(int i = 0; i < t.size(); i++) S.pop_back();
        j = jj;
    }
}