#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int a[100000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        int n;
        cin >> n;
        int ans = 0;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 1; i < n; i++){
            if(a[i] < a[i-1]){
                int d = a[i-1]-a[i];
                int tmp;
                for(int j = 0; j < 100; j++){
                    ll m = (ll)1<<j;
                    if(m > d) {
                        tmp = j;
                        break;
                    }
                }
                ans = max(ans, tmp);
                a[i] += d;
            }
        }
        cout << ans << endl;
    }
}