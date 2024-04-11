#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

bool used[10000005];
int idx[10000005];
ll ans = 1e+15;
int n;
int l, r;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        if(used[a]) {
            if(ans > a){
                l = idx[a];
                r = i+1;
                ans = a;
            }
        }
        idx[a] = i+1;
        used[a] = true;
    }
    for(int i = 1; i <= 10000000; i++){
        int cnt = 0;
        ll cur;
        for(int j = 1; i*j <= 10000000; j++){
            if(used[i*j]) {
                cnt++;
                if(cnt >= 2){
                    ll tmp = cur*j;
                    if(tmp < ans){
                        l = idx[cur];
                        r = idx[i*j];
                        ans = tmp;
                    }
                    break;
                }
                cur = i*j;
            }
        }
    }
    cout << min(l, r) << ' ' << max(l, r) << endl;
}