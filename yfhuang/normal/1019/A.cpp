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

int n, m;
const int maxn = 3005;

typedef pair<int, int> pii;

vector<int> c[maxn];

long long check(int cnt){
    long long ans = 0;
    int cur = c[1].size();
    vector<int> all;
    for(int i = 2;i <= m;i++){
        for(int j = cnt - 1;j < c[i].size();j++){
            ans -= c[i][j]; 
            //cout << ans << endl;
            cur++;
        } 
        for(int j = 0;j < min(cnt - 1, (int) c[i].size());j++){
            all.push_back(c[i][j]);
        }
    }
    sort(all.begin(), all.end());
    //cout << cur << " " << cnt << " " << ans << endl;
    if(cur < cnt){
        for(int j = all.size() - (cnt - cur);j < all.size();j++){
            ans -= all[j];
            //cout << cnt << " " << all[j] << endl;
        }
    }
    return ans;
}

int main(){
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int a, b;
        scanf("%d%d", &a, &b);
        c[a].push_back(-b);
    } 
    for(int i = 1;i <= m;i++){
        sort(c[i].begin(), c[i].end());
    }
    long long ans = 1e18;
    for(int i = 1;i <= n;i++){
        ans = min(ans, check(i));
    }
    cout << ans << endl;
    return 0;
}