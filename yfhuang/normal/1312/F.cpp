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

int t;

int n;
typedef long long LL;
const int maxn = 3e5 + 5;
LL a[maxn];

int sg[maxn][3];
int cnt[3];
void cal(){
    memset(sg[0], 0, sizeof(sg[0]));
    for(int i = 1;i <= 250;i++){
        bool vis[5];
        for(int j = 0;j < 3;j++){
            memset(vis, 0, sizeof(vis));
            for(int k = 0;k < 3;k++){
                if(j > 0 and k == j)
                    continue;
                int to = max(0, i - cnt[k]);
                vis[sg[to][k]] = 1;
            }
            for(int k = 0;k < 4;k++){
                if(!vis[k]){
                    sg[i][j] = k;
                    break;
                }
            }
        }
    }
}

pair<int, int> find_circle(){
    int mx = max(cnt[0], max(cnt[1], cnt[2]));
    for(int st = 0;st <= 250;st++){
        for(int j = st+1;j <= 250;j++){
            for(int k = 0;;k++){
                if(k >= mx){
                    return make_pair(st, j - st);
                }
                if(j + k > 250)
                    break;
                bool flag = true;
                for(int i = 0;i < 3;i++){
                    if(sg[st+k][i] != sg[j+k][i])
                        flag = false;
                }
                if(!flag){
                    break;
                }
            }
        }
    }
    return make_pair(-1, -1);
}

pair<int, int> circle[250];

void init(){
    for(int x = 1;x <= 5;x++){
        cnt[0] = x;
        for(int y = 1;y <= 5;y++){
            cnt[1] = y;
            for(int z = 1;z <= 5;z++){
                cnt[2] = z;
                cal();
                int mask = x * 25 + y * 5 + z;
                circle[x * 25 + y * 5 + z] = find_circle();
                //cout << circle[mask].first << " " << circle[mask].second << endl;
                //cout << circle[mask].second << endl;
            }
        }
    }
}

int main(){
    //freopen("output1.txt", "w", stdout);
    init();
    cin >> t;
    while(t--){
        int x, y, z;
        scanf("%d%d%d%d", &n, &x, &y, &z);
        for(int i = 1;i <= n;i++){
            scanf("%lld", &a[i]);
        }
        int mask = x * 25 + y * 5 + z;
        pair<int, int> T = circle[mask];
        LL res = 0;
        cnt[0] = x, cnt[1] = y, cnt[2] = z;
        cal();
        for(int i = 1;i <= n;i++){
            if(a[i] > 100){
                a[i] = 100 + (a[i] - 100) % T.second;
            }
            res ^= sg[a[i]][0];
        }
        int sol = 0;
        for(int i = 1;i <= n;i++){
            int now = a[i];
            for(int j = 0;j < 3;j++){
                int to = max(0, now - cnt[j]);
                if((sg[to][j] ^ sg[now][0]) == res)
                    sol++;
            }
        }
        if(res == 0){
            printf("%d\n", 0);
        }else{
            printf("%d\n", sol);
        }
    }
    return 0;
}