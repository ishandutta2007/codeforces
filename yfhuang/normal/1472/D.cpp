#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cassert>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int t;

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        for(int i = 0;i < n;i++){
            if((i & 1) and (a[n-1-i] & 1)){
               ans -= a[n-1-i]; 
            }
            if((i % 2 == 0) and (a[n-1-i] % 2 == 0)){
                ans += a[n-1-i];
            }
        }
        if(ans > 0){
            cout << "Alice" << endl;
        }else if(ans == 0){
            cout << "Tie" << endl;
        }else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}