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

int n, m, Q;
const int maxn = (1 << 12) + 5;

int pre[maxn][105];

int w[maxn];

char s[maxn];

int cnt[maxn];
vector<pair<int, int> > q[maxn];
int sum[maxn];
const int N = 5e5 + 5;
pair<int, int> ans[N];
int main(){
    cin >> n >> m >> Q;
    for(int i = 0;i < n;i++){
        cin >> w[i];
    }
    for(int mask = 0;mask < (1 << n);mask++){
        int res = 0;
        for(int j = 0;j < n;j++){
            if(!(mask & (1 << j))){
                res += w[j];
            }
        }
        sum[mask] = res;
    }
    for(int i = 1;i <= m;i++){
        scanf("%s", s);
        int mask = 0;
        for(int j = 0;j < n;j++){
            if(s[j] == '1'){
                mask = mask | (1 << j) ;
            }
        }
        cnt[mask]++;
    }
    for(int i = 1;i <= Q;i++){
        scanf("%s", s);
        int mask = 0;
        for(int j = 0;j < n;j++){
            if(s[j] == '1'){
                mask = mask | (1 << j);
            }
        }
        int k;
        scanf("%d", &k);
        q[mask].emplace_back(i, k);
    }
    for(int mask1 = 0;mask1 < (1 << n);mask1++){
        if(q[mask1].size() == 0)
            continue;
        for(int mask2 = 0;mask2 < (1 << n);mask2++){
            if(cnt[mask2] == 0)
               continue; 
            int mask3 = mask1 ^ mask2;
            int res = sum[mask3];
            if(res <= 100){
                pre[mask1][res] += cnt[mask2];
            }
        }
    }
    for(int mask1 = 0;mask1 < (1 << n);mask1++){
        for(int j = 1;j <= 100;j++){
            pre[mask1][j] += pre[mask1][j - 1];
        }
    }
    int tot = 0;
    for(int mask1 = 0;mask1 < (1 << n);mask1++){
        for(int j = 0;j < q[mask1].size();j++){
            pair<int, int> p = q[mask1][j];
            ans[++tot] = make_pair(p.first, pre[mask1][p.second]);
        }
    }
    sort(ans + 1,ans + 1 + tot);
    for(int i = 1;i <= Q;i++){
        printf("%d\n", ans[i].second);
    }
    return 0;
}