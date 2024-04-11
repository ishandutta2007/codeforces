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
#include <random>
#include <chrono>
using namespace std;

const int maxn = 1e5 + 5;

int n, q;
int v[maxn], c[maxn];
typedef long long LL;
//LL pre[2][maxn];
LL dp[maxn];
bool vis[maxn];
//void add(int id, int pos, LL val){
//    for(int i = pos;i < maxn;i += i & -i){
//        pre[id][i] = max(pre[id][i], val);
//    }
//} 
//
//LL sum(int id, int pos){
//    LL res = -1e18;
//    for(int i = pos;i > 0;i -= i & -i){
//        res = max(res, pre[id][i]);
//    }
//    return res;
//}

LL query(int a, int b){
    memset(vis, false, sizeof(vis));
    //memset(pre, 0, sizeof(pre));
    for(int i = 1;i <= n;i++){
        dp[i] = -1e18;
    }
    pair<int, LL> mx1, mx2;
    mx1 = mx2 = make_pair(0, 0);
    for(int i = 1;i <= n;i++){
        if(vis[c[i]]){
            LL same = dp[c[i]];
            LL tmp = 1LL * v[i] * a;
            dp[c[i]] = max(dp[c[i]], tmp + same); 
        }
        dp[c[i]] = max(dp[c[i]], 1LL * v[i] * b);
        //LL pref = sum(0, c[i] - 1);
        //LL suff = sum(1, n - c[i]);
        LL diff;
        if(mx1.first == 0){
            diff = 0;
        }else{
            if(mx1.first != c[i]){
                diff = mx1.second;
            }else{
                if(mx2.first == 0){
                    diff = 0;
                }else{
                    diff = mx2.second;
                }
            }
        }
        dp[c[i]] = max(dp[c[i]], diff + 1LL * v[i] * b);
        vis[c[i]] = true;
        if(mx1.first == 0){
            mx1 = make_pair(c[i], dp[c[i]]);
        }else{
            if(c[i] == mx1.first){
                mx1 = make_pair(c[i], dp[c[i]]); 
            }
            else{
                if(dp[c[i]] > mx1.second){
                    mx2 = mx1;
                    mx1 = make_pair(c[i], dp[c[i]]);
                }else{
                    if(mx2.first == 0){
                        mx2 = make_pair(c[i], dp[c[i]]);
                    }else{
                        if(dp[c[i]] > mx2.second){
                            mx2 = make_pair(c[i], dp[c[i]]);
                        }
                    }
                }
            }
        }
    }
    LL ans = 0;
    for(int i = 1;i <= n;i++){
        ans = max(ans, dp[i]);
    }
    return ans;
}

int main(){
    cin >> n >> q;
    for(int i = 1;i <= n;i++){
        scanf("%d", &v[i]);
    }
    for(int i = 1;i <= n;i++){
        scanf("%d", &c[i]);
    }
    for(int i = 1;i <= q;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        LL ans = query(a, b);
        printf("%lld\n", ans);
    }
    return 0;
}