#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

int a[200000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int dum = 0; dum < t; dum++){
        int n, k, d;
        cin >> n >> k >> d;
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        map<int, int> mp;
        int cnt = 0;
        
        for(int i = 0; i < d; i++){
            if(mp.count(a[i]) == 0){
                mp[a[i]] = 1;
                cnt++;
            }else{
                mp[a[i]]++;
            }
        }
        int ans = cnt;
        for(int i = d; i < n; i++){
            if(mp.count(a[i]) == 0){
                mp[a[i]] = 1;
                cnt++;
            }else{
                mp[a[i]]++;
            }
            if(mp[a[i-d]] == 1){
                mp.erase(a[i-d]);
                cnt--;
            }else{
                mp[a[i-d]]--;
            }
            ans = min(ans, cnt);
        }
        cout << ans << endl;
    }
}