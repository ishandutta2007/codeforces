#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <queue>
#include <map>
#include <set>
#include <limits.h>
#include <limits>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <sstream>
using namespace std;
int n, m, ret[100005], a[100005], lj, rj;
vector < pair < pair <int, int>, int> > q[100005];
pair <int, int> b[100005];
int mp[100005], h[100005];
int main(){
    scanf("%d %d", &n, &m);
    int p = sqrt(n);

    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        b[i].first = a[i], b[i].second = i;
    }
    sort(b, b + n);
    for(int i = 0; i < n; i++){
        if(i > 0 && b[i].first == b[i - 1].first)h[b[i].second] = h[b[i - 1].second];
        else h[b[i].second] = i;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &lj, &rj);
        lj--, rj--;
        q[lj / p].push_back(make_pair(make_pair(rj, lj), i));
    }
    for(int i = 0; i < (n / p); i++){
        sort(q[i].begin(), q[i].end());

        int L = i * p, R = L - 1, ans = 0;
        for(int j = 0; j < q[i].size(); j++){
            int L2 = q[i][j].first.second, R2 = q[i][j].first.first;
            while(R < R2){
                mp[h[R + 1]]++;

                int cur = mp[h[R + 1]];
                if(cur == a[R + 1])ans++;
                else if(cur - 1 == a[R + 1])ans--;

                R++;
            }
            while(L < L2){
                mp[h[L]]--;
                int cur = mp[h[L]];

                if(cur == a[L])ans++;
                else if(cur + 1 == a[L])ans--;

                L++;
            }
            while(L > L2){
                mp[h[L - 1]]++;

                int cur = mp[h[L - 1]];
                if(cur == a[L - 1])ans++;
                else if(cur - 1 == a[L - 1])ans--;

                L--;
            }
            ret[q[i][j].second] = ans;
        }
        memset(mp, 0, sizeof mp);
    }
    for(int i = 0; i < m; i++)
        printf("%d\n", ret[i]);
    return 0;
}