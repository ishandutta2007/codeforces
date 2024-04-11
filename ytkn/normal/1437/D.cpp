#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>

#define debug_value(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << #x << "=" << x << endl;
#define debug(x) cerr << "line" << __LINE__ << ":<" << __func__ << ">:" << x << endl;

using namespace std;
typedef long long ll;

int n;
int a[200000];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
    }
    vector<int> par(n);
    vector<int> d(n);
    int cur = 0;
    for(int i = 1; i < n; i++){
        if(i != 1 && a[i] < a[i-1]){
            cur++;
        }
        par[i] = cur;
        d[i] = d[par[i]]+1;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, d[i]);
    cout << ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}