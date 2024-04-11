//In the name of Allah

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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <assert.h>
using namespace std;

int n, s, a[2005], dp[2005][2], ti[2005][2];
vector < pair <int, int> > v;
pair <int, int> nxt[2005][2];

int solve(int i, bool start){
    if(dp[i][start] != -1)return dp[i][start];
    
    int t;
    if(start)t = v[0].first;
    else{
        if(a[i] == v.back().first)return 0;
        int ind = upper_bound(v.begin(), v.end(), make_pair(a[i], 1 << 30)) - v.begin();
        t = v[ind].first;
    }
    ti[i][start] = t;

    vector <int> c;
    for(int j = 0; j < n; j++)
        if((a[j] == t) || (j == i))c.push_back(j);
    
    int ret = 1 << 30;
    for(int j = 0; j < c.size(); j++){
        int x = c[j], y = c[(j + c.size() - 1) % c.size()];
        int L = ((i - x + n) % n) + ((y - x + n) % n);
        int R = ((y - i + n) % n) + ((y - x + n) % n);

        if(a[y] == t){
            if(solve(y, false) + L < ret){
                ret = solve(y, false) + L;
                
                nxt[i][start].first = j;
                nxt[i][start].second = 0;
            }
        }
        if(a[x] == t){
            if(solve(x, false) + R < ret){
                ret = solve(x, false) + R;
                
                nxt[i][start].first = j;
                nxt[i][start].second = 1;
            }
        }
    }
    return dp[i][start] = ret;
}
int main(){
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        v.push_back(make_pair(a[i], i));
    }
    sort(v.begin(), v.end());

    s--;

    memset(dp, -1, sizeof dp);
    printf("%d\n", solve(s, true));

    int i = s, start = true;
    while(true){
        if((!start) && (a[i] == v.back().first))break;
        
        int t = ti[i][start];

        vector <int> c; int ci;
        for(int j = 0; j < n; j++){
            if(j == i){
                c.push_back(j);
                ci = c.size() - 1;
            }
            else if(a[j] == t)c.push_back(j);
        }
        
        int j = nxt[i][start].first, dir = nxt[i][start].second;
        int x = c[j], y = c[(j + c.size() - 1) % c.size()];
        
        /*cout << i << ' ' << dir << ' ' << j << ' ' << x << ',' << y << endl;
        for(int k = 0; k < c.size(); k++)
            cout << c[k] << ' ';
        cout << endl;*/

        if(dir == 0){
            if(a[i] == t)printf("+0\n");
            for(int k = ci; c[k] != x; ){
                int k_ = (k + c.size() - 1) % c.size();
                
                int d = (c[k] - c[k_] + n) % n;
                printf("-%d\n", d);
                
                k = k_;
            }
            for(int k = ci; c[k] != y; ){
                int k_ = (k + 1) % c.size();
                
                int d = (c[k_] - c[k] + n) % n;
                if(k == ci)printf("+%d\n", (c[k_] - x + n) % n);
                else printf("+%d\n", d);

                k = k_;
            }
            i = y;
            start = false;
        }else{
            if(a[i] == t)printf("+0\n");
            for(int k = ci; c[k] != y; ){
                int k_ = (k + 1) % c.size();
                
                int d = (c[k_] - c[k] + n) % n;
                printf("+%d\n", d);

                k = k_;
            }
            for(int k = ci; c[k] != x; ){
                int k_ = (k + c.size() - 1) % c.size();
                
                int d = (c[k] - c[k_] + n) % n;
                if(k == ci)printf("-%d\n", (y - c[k_] + n) % n);
                else printf("-%d\n", d);
                
                k = k_;
            }
            i = x;
            start = false;
        }
    }
    return 0;
}