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
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '0') cnt0++;
        else cnt1++;
    }
    int m = min(cnt1, cnt0);
    if(m%2 == 1){
        cout << "DA" << endl;
    }else{
        cout << "NET" << endl;
    }
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