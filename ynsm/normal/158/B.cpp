#include <bits/stdc++.h>
 
using namespace std;
 
int n, cnt[5], ans;
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    ans = cnt[4];
    ans += cnt[3];
    cnt[1] -= min(cnt[1], cnt[3]);
    ans += cnt[2] / 2;
    if(cnt[2] % 2 == 1){
         ans ++;
        cnt[1] -= min(cnt[1], 2);
    }
    ans += (cnt[1] + 3) / 4;
    cout << ans;
}