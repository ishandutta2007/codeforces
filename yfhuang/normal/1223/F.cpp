#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
using namespace std;

int q;
int n;
const int maxn = 3e5 + 5;
int a[maxn];
map<int, int> mp[maxn]; //mp[pos][val] = r means a[r] == val and pos - (r - 1) is stack exterminable 
int r[maxn];
int dp[maxn];
int main(){
    cin >> q;
    while(q--){
        cin >> n;
        long long ans = 0;
        for(int i = 1;i <= n;i++){
            scanf("%d", &a[i]);
        }
        for(int i = 1;i <= n + 1;i++){
            mp[i].clear();
            r[i] = -1;
            dp[i] = 0;
        }
        for(int i = n;i >= 1;i--){
            int nxt;
            if(mp[i + 1].count(a[i])){
                nxt = mp[i + 1][a[i]];
                r[i] = nxt;
                swap(mp[i], mp[nxt + 1]);
                if(nxt + 1 <= n){
                    mp[i][a[nxt + 1]] = nxt + 1;
                }
            }
            mp[i][a[i]] = i;
            //cout << i << " " << r[i] << endl;
            if(r[i] != -1){
                dp[i] = 1 + dp[r[i] + 1];
            }
            ans += dp[i];
        }
        cout << ans << endl;
    } 
    return 0;
}