#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pi;

int T, n;

string t, s[20];

int dp[105];
const int INF = 0x3f3f3f3f;
int w[105], p[105]; 

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> T;
    while(T--){
        cin >> t;
        cin >> n;
        int N = t.length();
        for(int i = 1;i <= n;i++){
            cin >> s[i];
        }
        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        for(int i = 1;i <= N;i++){
            for(int j = 1;j <= n;j++){
                int len = s[j].length();
                if(i >= len){
                    if(t.substr(i - len, len) == s[j]){
                        for(int k = i - len;k < i;k++){
                            if(dp[k] + 1 < dp[i]){
                                dp[i] = dp[k] + 1;
                                w[i] = j;              
                                p[i] = k;
                            }
                        }
                    }  
                }
            }
        }
        if(dp[N] == INF){
            cout << -1 << endl;
        }else{
            int now = N;
            vector<pi> ans;
            while(now != 0){
                int pre = p[now];
                ans.push_back(mp(w[now], now - s[w[now]].length() + 1));
                now = pre;
            }
            cout << ans.size() << endl;
            for(auto v : ans){
                cout << v.fi << " " << v.se << endl;
            }
        }
    }
    return 0;
}