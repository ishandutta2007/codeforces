#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int n, p;
int a[2000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n >> p;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a+n);
    vector<int> ans;
    // x > 2000OK
    for(int x = 1; x <= 2000; x++){
        bool ok = true;
        ll tmp = 1;
        for(int i = 0; i < n; i++){
            int y = x+i+1;
            auto ptr = lower_bound(a, a+n, y);
            int d = ptr-a-i;
            if(d <= 0 || d%p == 0){
                ok = false;
                // break;
            }
            tmp *= d;
        }
        if(ok) ans.push_back(x);
    }
    cout << ans.size() << endl;
    for(int i : ans) cout << i << ' ';
    cout << endl;
}