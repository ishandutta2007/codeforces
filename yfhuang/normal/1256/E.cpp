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

int n;

const int maxn = 2e5 + 5;
typedef long long LL;
typedef pair<LL, int> pii;
pii a[maxn];

int pre[maxn];

LL dp[maxn];
set<pii> s;

int tid[maxn];

int main(){
    cin >> n;
    for(int i = 1;i <= n;i++){
        scanf("%lld", &a[i].first);
        a[i].second = i;
        dp[i] = 1e18;
    }
    sort(a + 1, a + 1 + n);
    dp[0] = 0;
    pre[0] = 0;
    s.clear();
    for(int i = 1;i <= n;i++){
        if(i >= 3){
            s.insert(make_pair(dp[i - 3] - a[i - 2].first, i - 3));
        }
        if(!s.empty()){
            pii small = *s.begin();
            dp[i] = small.first + a[i].first;
            pre[i] = small.second;
        }
    }
    int now = n;
    int count = 0;
    while(now != 0){
        int p = pre[now];
        ++count;
        for(int j = p + 1;j <= now;j++){
            tid[a[j].second] = count;
        }
        now = pre[now];
    }
    cout << dp[n] << " " << count << endl;
    for(int i = 1;i <= n;i++){
        printf("%d%c", tid[i], i == n ? '\n' : ' ');
    }
    return 0;
}