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
int a[300000];

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    if(a[0] > a[n-1]){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
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