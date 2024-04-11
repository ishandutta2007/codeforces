#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <numeric>
#include <functional>
#include <cassert>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

using namespace std;
typedef long long ll;

void solve(vector<int> x, vector<int> y){
    int n = x.size();
    vector<int> v(n);
    vector<int> cnt(4);
    for(int i = 0; i < n; i++){
        v[i]= 2*((x[i]%2+2)%2)+(y[i]%2+2)%2;
        cnt[v[i]]++;
    }
    for(int k = 0; k < 4; k++){
        if(cnt[k] == n){
            for(int i = 0; i < n; i++){
                if(x[i]%2 == 1) x[i]++;
                if(y[i]%2 == 1) y[i]++;
                x[i] /= 2;
                y[i] /= 2;
            }
            solve(x, y);
            return;
        }
    }
    // for(int x : cnt) cout << x << ' ';
    // cout << endl;
    vector<int> ans;
    if(cnt[0]+cnt[3] == n){
        for(int i = 0; i < n; i++){
            if(v[i] == 0) ans.push_back(i);
        }
    }else if(cnt[1]+cnt[2] == n){
        for(int i = 0; i < n; i++){
            if(v[i] == 1) ans.push_back(i);
        }
    }else{
        for(int i = 0; i < n; i++){
            if(v[i] == 1 || v[i] == 2) ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(int x : ans) cout << x+1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int n; cin >> n;
    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
    solve(x, y);
}