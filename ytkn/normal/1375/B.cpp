#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int n, m;
int a[300][300];

void solve(){
    cin >> n >> m;
    bool ok = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
            int cnt = 0;
            if(i > 0 && i < n-1) cnt += 2;
            else cnt++;
            if(j > 0 && j < m-1) cnt += 2;
            else cnt++;
            if(a[i][j] > cnt) ok = false;
        }
    }
    if(!ok){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int cnt = 0;
                if(i > 0 && i < n-1) cnt += 2;
                else cnt++;
                if(j > 0 && j < m-1) cnt += 2;
                else cnt++;
                cout << cnt << ' ';
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
    for(int i = 0; i < t; i++){
        solve();
    }
}