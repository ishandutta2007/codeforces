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

using namespace std;

int k;
const int maxn = 20;
map<long long, int> id;
vector<int> a[maxn];

int dp[(1 << maxn)];
long long pre[maxn];
int vis[maxn];

vector<pair<int, pair<int, long long> > > path[(1 << maxn)];

int main(){
    cin >> k;
    long long sum = 0;
    for(int i = 1;i <= k;i++){
        int n;
        scanf("%d", &n);
        pre[i] = 0;
        for(int j = 1;j <= n;j++){
            int num;
            scanf("%d", &num);
            a[i].push_back(num);
            sum += num;
            id[num] = i;
            pre[i] += num;
        }
    }
    if(sum % k){
        puts("No");
        return 0;
    }
    memset(dp, 0, sizeof(dp));
    sum /= k;
    for(int i = 1;i <= k;i++){
        for(int j = 0;j < a[i].size();j++){
            long long num = a[i][j];
            vector<long long> tmp;
            vector<int> ID;
            memset(vis, -1, sizeof(vis));
            bool flag = true;
            int now = i;
            int timestamp = 0;
            while(true){
                vis[now] = ++timestamp;
                long long nxt = sum - (pre[now] - num); 
                tmp.push_back(num);
                ID.push_back(now);
                int nxtid = id[nxt];
                if(vis[nxtid] != -1){
                    if(vis[nxtid] != 1){
                        flag = false;
                    }else{
                        if(nxt != tmp[0]){
                            flag = false;
                        }
                    }
                    break;
                }
                now = nxtid;
                num = nxt;
            }
            if(!flag){
                continue;
            }
            vector<pair<int, pair<int, long long> > > haha;
            for(int l = 0;l < ID.size();l++){
                int now = ID[l];
                int nxt = ID[(l - 1 + ID.size()) % ID.size()];
                long long val = tmp[l]; 
                haha.push_back(make_pair(now, make_pair(nxt, val)));
            }
            int state = 0;
            for(int l = 1;l <= k;l++){
                if(vis[l] != -1){
                    state |= (1 << (l - 1));
                } 
            }
            dp[state] = 1;
            path[state] = haha;
        }
    }  
    dp[0] = 1;
    path[0] = vector<pair<int, pair<int, long long> > >(0);
    for(int i = 0;i < (1 << k);i++){
        if(dp[i] != 0)
            continue;
        for(int S = i; S != 0; S = i & (S - 1)){
            if(dp[S] and dp[i ^ S]){
                dp[i] = 1;
                path[i] = path[S];
                for(auto v : path[i ^ S]){
                    path[i].push_back(v);
                }
                break;
            } 
        }
    }
    //cout << dp[(1 << k) - 1] << endl;
    if(dp[(1 << k) - 1]){
        puts("Yes");
        int mask = (1 << k) - 1;
        sort(path[mask].begin(), path[mask].end());
        for(int i = 0;i < k;i++){
            printf("%lld %d\n", path[mask][i].second.second, path[mask][i].second.first);
        }
    }else{
        puts("No");
    }
    return 0;
}