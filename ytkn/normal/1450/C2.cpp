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

void solve(){
    int n; cin >> n;
    vector<string> s(n);
    vector<string> t(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
        for(int j = 0; j < n; j++) t[i] += s[i][j];
    }
    int k = 0;
    for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
        if(s[i][j] != '.') k++;
    }
    for(int a = 0; a < 3; a++)for(int b = 0; b < 3; b++){
        if(a == b) continue;
        // a => , b => 
        int cnt = 0;
        for(int i = 0; i < n; i++)for(int j = 0; j < n; j++){
            if((i+j)%3 == a){
                if(s[i][j] == '.') t[i][j] = '.';
                else{
                    if(s[i][j] == 'X') cnt++;
                    t[i][j] = 'O';
                }
            }else if((i+j)%3 == b){
                if(s[i][j] == '.') t[i][j] = '.';
                else{
                    if(s[i][j] == 'O') cnt++;
                    t[i][j] = 'X';
                }
            }else{
                t[i][j] = s[i][j];
            }
        }
        if(cnt <= k/3) {
            for(int i = 0; i < n; i++) cout << t[i] << endl;
            return;
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