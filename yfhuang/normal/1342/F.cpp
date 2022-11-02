#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

int n;
int a[20];
int dp[20][(1 << 15) + 1][20];
pair<int, int> pre[20][(1 << 15) + 1][20];
int sum[(1 << 15) + 1];

const int INF = 0x3f3f3f3f;

void solve(){
    int S = (1 << n);
    for(int s = 0;s < S;s++){
        sum[s] = 0;
        for(int i = 0;i < n;i++){
            if(s & (1 << i)){
                sum[s] += a[i];
            }
        }
    }
    for(int cnt = 0;cnt <= n;cnt++){
        for(int s = 0;s < S;s++){
            for(int pos = 0;pos <= n;pos++){
                dp[cnt][s][pos] = INF;
            }
        }
    }
    dp[0][0][0] = 0;
    for(int cnt = 0;cnt <= n;cnt++){
        for(int s = 0;s < S;s++){
            for(int pos = 0;pos <= n;pos++){
                if(dp[cnt][s][pos] == INF)
                    continue;
                int rmask = (S - 1) ^ s;
                for(int s1 = rmask;s1;s1 = (s1 - 1) & rmask){
                    if(sum[s1] <= dp[cnt][s][pos])
                        continue;
                    if((s1 >> pos) == 0)
                        continue;
                    int pos1 = pos + __builtin_ctz(s1 >> pos) + 1;
                    if(dp[cnt + 1][s | s1][pos1] > sum[s1]){
                        dp[cnt + 1][s | s1][pos1] = sum[s1];
                        pre[cnt + 1][s | s1][pos1] = mp(s, pos);
                    }
                }
            }
        }
    }
    int ansc = 0, ansp = 0;
    for(int cnt = 0; cnt <= n;cnt++){
        for(int pos = 0;pos <= n;pos++){
            if(dp[cnt][S - 1][pos] < INF){
                ansc = cnt, ansp = pos;
            }
        }
    }
    vector<pair<int, int> > ans; 
    int mask = S - 1, p1 = ansp;
    for(int cnt = ansc;cnt > 0;cnt--){
        int nmask = pre[cnt][mask][p1].fi;
        int np = pre[cnt][mask][p1].se;
        for(int i = 0;i < n;i++){
            if((mask ^ nmask) & (1 << i)){
                if(i != p1 - 1){
                    ans.eb(i, p1 - 1);
                }
            }
        }
        mask = nmask;
        p1 = np;
    }
    bool vis[20];
    memset(vis, 0, sizeof(vis));
    cout << ans.size() << endl;
    for(int i = 0;i < ans.size();i++){
        int x = ans[i].fi;
        int x1 = 0;
        for(int j = 0;j < x;j++){
            if(!vis[j])
                x1++;
        }
        int y = ans[i].se;
        int y1 = 0;
        for(int j = 0;j < y;j++){
            if(!vis[j])
                y1++;
        } 
        vis[x] = true;
        cout << x1 + 1 << " " << y1 + 1 << endl;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        solve();
    }
    return 0;
}