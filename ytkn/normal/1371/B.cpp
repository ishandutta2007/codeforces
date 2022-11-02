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
    ll n, r; cin >> n >> r;
    if(r >= n){
        cout << (n*(n-1))/2+1 << endl;
    }else{
        cout << (r*(r+1))/2 << endl;
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