#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int ans[300][300];

void reset(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            ans[i][j] = 0;
        }
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    reset(n);
    if(k%n == 0){
        cout << 0 << endl;
    }else{
        cout << 2 << endl;
    }
    int x = 0, y = 0;
    for(int i = 0; i < k; i++){
        ans[x][y] = 1;
        x++; y++;
        if(x == n){
            y++;
        }
        x %= n; y %= n;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j];
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}