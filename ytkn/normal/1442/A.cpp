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

int a[30005];

const int INF = 1e9;

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int pl = 0, pr = INF;
    for(int i = 0; i < n; i++){
        if(pl > a[i]){
            cout << "NO" << endl;
            return;
        }
        pr = min(pr, a[i]-pl);
        pl = a[i]-pr;
    } 
    cout << "YES" << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}