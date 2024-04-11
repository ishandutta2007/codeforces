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

void solve(){
    int n, m; cin >> n >> m;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];
    int r = -1, w = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i][j] == 'W'){
                if(w < 0) w = (i+j)%2;
                else if(w != (i+j)%2){
                    cout << "No" << endl;
                    return;
                }
            }
            if(s[i][j] == 'R'){
                if(r < 0) r = (i+j)%2;
                else if(r != (i+j)%2){
                    cout << "No" << endl;
                    return;
                }
            }
        }
    }
    if(r >= 0 || w >= 0){
        if(w == r){
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;
        if(w == 0 || r == 1){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << ((i+j)%2 == 0 ? 'W' : 'R');
                }
                cout << endl;
            }
        }else{
            for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                    cout << ((i+j)%2 == 0 ? 'R' : 'W');
                }
                cout << endl;
            }
        }
    }else{
        cout << "Yes" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << ((i+j)%2 == 0 ? 'R' : 'W');
            }
            cout << endl;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    while(t--) solve();
}