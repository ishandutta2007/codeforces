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
#include <complex>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
using namespace std;

int n, a[100005], ui, vi;
vector <int> g[100005];

long long dp[100005][3][2];
long long solve(int i, int rem, int path, int parent = -1){
    if(dp[i][rem][path] != -1)return dp[i][rem][path];
    
    long long r = -1LL << 55;
    if(path == 0){
        if(rem == 0)r = 0;
        else if(rem == 1){
            vector <long long> options;
            for(int j = 0; j < g[i].size(); j++){
                int u = g[i][j];
                if(u == parent)continue;
                
                r = max(r, solve(u, rem, path, i));
                options.push_back(solve(u, 0, 1, i));
            }
            
            sort(options.rbegin(), options.rend());
            r = max(r, (long long)a[i]);
            if(options.size() >= 1)r = max(r, a[i] + options[0]);
            if(options.size() >= 2)r = max(r, a[i] + options[0] + options[1]);
        }else{
            vector <long long> options_1;
            multiset <long long> options;
            for(int j = 0; j < g[i].size(); j++){
                int u = g[i][j];
                if(u == parent)continue;
                
                r = max(r, solve(u, rem, path, i));
                options_1.push_back(solve(u, 1, 0, i));
                options.insert(solve(u, 0, 1, i));
            }
            
            sort(options_1.rbegin(), options_1.rend());
            if(options_1.size() >= 2)r = max(r, options_1[0] + options_1[1]);
            
            for(int j = 0; j < g[i].size(); j++){
                int u = g[i][j];
                if(u == parent)continue;
                
                options.erase(options.lower_bound(solve(u, 0, 1, i)));
                
                long long r1 = 0, r2 = 0;
                multiset <long long> :: iterator d = options.end();
                if(options.size() >= 1){
                    d--;
                    r1 = *d;
                }
                if(options.size() >= 2){
                    d--;
                    r2 = *d;
                }
                
                options.insert(solve(u, 0, 1, i));
                
                r = max(r, a[i] + solve(u, 1, 1, i) + r1);
                r = max(r, a[i] + solve(u, 1, 0, i) + r1 + r2);
            }
        }
    }else{
        r = max(r, solve(i, rem, 0, parent));
        
        if(rem == 0){
            r = max(r, (long long)a[i]);
            for(int j = 0; j < g[i].size(); j++){
                int u = g[i][j];
                if(u == parent)continue;
                
                r = max(r, a[i] + solve(u, rem, 1, i));
            }
        }else{
            multiset <long long> options;
            for(int j = 0; j < g[i].size(); j++){
                int u = g[i][j];
                if(u == parent)continue;
                
                r = max(r, a[i] + solve(u, 1, 1, i));
                options.insert(solve(u, 1, 0, i));
            }
            
            for(int j = 0; j < g[i].size(); j++){
                int u = g[i][j];
                if(u == parent)continue;
                
                options.erase(options.lower_bound(solve(u, 1, 0, i)));
                
                multiset <long long> :: iterator d = options.end();
                if(options.size() >= 1){
                     d--;
                     r = max(r, a[i] + solve(u, 0, 1, i) + (*d));
                }
                options.insert(solve(u, 1, 0, i));
            }
        }
    }
    return dp[i][rem][path] = r;
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for(int e = 0; e < (n - 1); e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    
    memset(dp, -1, sizeof dp);
    printf("%I64d\n", solve(0, 2, 0));
    
    return 0;
}