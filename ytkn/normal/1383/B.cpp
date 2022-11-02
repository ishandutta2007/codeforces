#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;
ll a[100000];

void solve(){
    int n; cin >> n;
    ll x = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        x ^= a[i];
    }
    if(x == 0){
        cout << "DRAW" <<  endl;
        return;
    }
    int m;
    for(int i = 30; i >= 0; i--){
        if((x&(1<<i))){
            m = i;
            break;
        }
    }
    int k = 0;
    for(int i = 0; i < n; i++){
        if(a[i]&(1<<m))k++;
    }
    if(k%4 == 3 && n%2 == 1){
        cout << "LOSE" << endl;
    }else{
        cout << "WIN" << endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t; cin >> t;
    for(int i = 0; i < t; i++) solve();
}