#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

void solve(){
    int n;
    string a, b;
    cin >> n >> a >> b;
    vector<int> ans;
    int sum = 0;
    int l = 0, r = n-1;
    for(int i = n-1; i >= 0; i--){
        if(sum%2 == 0){
            if(a[r] == b[i]) {
                r--;
                continue;
            }
            if(a[l] != b[i]){
                ans.push_back(i);
            }else{
                ans.push_back(0);
                ans.push_back(i);
            }
            l++;
            sum++;
        }else{
            if(a[l] != b[i]) {
                l++;
                continue;
            }
            if(a[r] == b[i]){
                ans.push_back(i);
            }else{
                ans.push_back(0);
                ans.push_back(i);
            }
            r--;
            sum++;
        }
    }
    cout << ans.size() << ' ';
    for(int i : ans) cout << i+1 << ' ';
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}