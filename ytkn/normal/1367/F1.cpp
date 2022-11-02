#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int N;
int A[200000];

void solve(){
    cin >> N;
    map<int, int> mp;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]] = i;
    }
    int ans = 0;
    int cnt = 0;
    int prev = -1;
    for(auto i : mp){
        int m = i.first;
        int idx = i.second;
        if(idx > prev){
            prev = idx;
            cnt++;
        }else{
            ans = max(ans, cnt);
            prev = idx;
            cnt = 1;
        }
    }
    ans = max(ans, cnt);
    cout << N-ans << endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) solve();
}