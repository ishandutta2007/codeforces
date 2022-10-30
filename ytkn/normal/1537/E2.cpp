#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
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

vector<int> z_algorithm(string s){
    int n = s.size();
    vector<int> ans(n);
    ans[0] = n;
    int i = 1, j = 0;
    while(i < s.size()){
        while(i+j < s.size() && s[i+j] == s[j]) j++;
        if(j == 0) {
            i++;
            continue;
        }
        ans[i] = j;
        int k = 1;
        while(k < j && ans[k]+k < j){
            ans[i+k] = ans[k];
            k++;
        }
        i += k;
        j -= k;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string t;
    while(t.size() < k) t += s;
    while(t.size() > k) t.pop_back();
    auto v = z_algorithm(t);
    // cout << v.size() << ' ' <<  k << endl;
    for(int i = 0; i < k; i++){
        int x = v[i];
        if(i+x == k) continue;
        // cout << i << ' ' << x << endl;
        if(t[i+x] > t[x]){
            string ans;
            string p;
            for(int j = 0; j < i; j++) p += t[j];
            while(ans.size() < k) ans += p;
            while(ans.size() > k) ans.pop_back();
            cout << ans << endl;
            return 0;
        }
    }
    cout << t << endl;
}