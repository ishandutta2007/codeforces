#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
int n;
int a[1000];
int ans[1000];
int p[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int _ = 0; _ < t; _++){
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        map<int, int> mp;
        int cnt = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < 11; j++){
                if(a[i]%p[j] == 0){
                    if(mp.count(j) == 0){
                        mp[j] = cnt;
                        cnt++;
                    }
                    ans[i] = mp[j];
                    break;
                }
            }
        }
        cout << cnt-1 << endl;
        for(int i = 0; i < n; i++){
            cout << ans[i];
            if(i == n-1) cout << endl;
            else cout <<  ' ';
        }
    }
}