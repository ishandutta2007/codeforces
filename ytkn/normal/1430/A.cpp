#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

void solve(){
    int n; cin >> n;
    for(int i = 0; i*3 <= n; i++){
        if((n-i*3)%5 == 0){
            cout << i << ' ' << (n-i*3)/5 << ' ' << 0 << endl;
            return;
        }
    }
    for(int i = 0; i*7 <= n; i++){
        if((n-i*7)%5 == 0){
            cout << 0 << ' ' << (n-i*7)/5 << ' ' << i << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}