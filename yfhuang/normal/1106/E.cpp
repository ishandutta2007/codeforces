#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;

int n, m, k;

const int maxn = 1e5 + 5;
struct event{
    int d, w, t;
    event(int _d = 0, int _w = 0, int _t = 0):d(_d), w(_w), t(_t){}
    bool operator < (const event & rhs) const{
        if(w == rhs.w)
            return d > rhs.d;
        else 
            return w > rhs.w;
    }
};

vector<event> G[maxn];
long long dp[2][maxn];
const long long INF = (long long)1e18;
event a[maxn];
int main(){
    cin >> n >> m >> k;
    for(int i = 1;i <= k;i++){
        int s, t, d, w;       
        scanf("%d%d%d%d", &s, &t, &d, &w);
        G[s].push_back(event(d, w, 1));
        G[t + 1].push_back(event(d, w, -1));
    }
    multiset<event> s;
    for(int i = 0;i < maxn;i++){
        dp[0][i] = dp[1][i] = INF;
    }
    dp[0][0] = 0;
    long long ans = (long long)1e19;
    for(int i = 1;i <= n;i++){
        for(int l = 0;l < G[i].size();l++){
            event temp = G[i][l];
            if(temp.t == 1){
                s.insert(temp);
            }else{
                event del = event(temp.d, temp.w, 1);
                multiset<event>::iterator it = s.lower_bound(del);
                s.erase(it);
            }
        }
        if(s.size() > 0){
            event tmp = *s.begin();
            a[i] = tmp;
        }else{
            a[i] = event(i, 0, 0);
        }
    }
    for(int i = 0;i <= m;i++){
        for(int j = 0;j < maxn;j++){
            dp[(i + 1) & 1][j] = INF;
        }
        for(int j = 1;j <= n;j++){
            dp[(i + 1) & 1][j] = min(dp[(i + 1) & 1][j], dp[i & 1][j - 1]);
            dp[i & 1][a[j].d] = min(dp[i & 1][a[j].d], dp[i & 1][j - 1] + a[j].w);
        }
        if(dp[i & 1][n] != -1){
            ans = min(ans, dp[i & 1][n]);
        }
    }
    cout << ans << endl;
    return 0;
}