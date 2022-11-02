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
    string s;
    int n;
    cin >> n >> s;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != '0') break;
        cnt0++;
    }
    for(int i = n-1; i >= 0; i--){
        if(s[i] == '0') break;
        cnt1++;
    }
    if(cnt0+cnt1 == n){
        for(int i = 0; i < cnt0; i++) cout << '0';
        for(int i = 0; i < cnt1; i++) cout << '1';
    }else{
        for(int i = 0; i < cnt0+1; i++) cout << '0';
        for(int i = 0; i < cnt1; i++) cout << '1';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++){
        solve();
    }
}