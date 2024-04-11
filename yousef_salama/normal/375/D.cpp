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

const int MAXN = 100005;
const int MAXS = 305;

int n, m, c[MAXN], ai, bi, ans[MAXN];
vector <int> g[MAXN];
vector < pair <int, int> > Q[MAXN];

struct RETURN{
    multiset <int> heavy;
    map <int, int> mp;
    int light[MAXS];
    
    RETURN(){
        mp.clear();
        heavy.clear();
        memset(light, 0, sizeof light);
    }
    
    void add(int c){
        int t = mp[c];
        if(t > 0){
            if(t < MAXS)light[t]--;
            else heavy.erase(heavy.lower_bound(t));
        }
            
        if(t + 1 < MAXS)light[t + 1]++;
        else heavy.insert(t + 1);
        
        mp[c]++;
    }
};

RETURN* solve(int i, int parent = -1){
    RETURN* ret = new RETURN();
    ret->add(c[i]);

    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u == parent)continue;
        
        RETURN* cur = solve(u, i);
        
        if(cur->mp.size() > ret->mp.size())swap(ret, cur);

        for(map <int, int> :: iterator i = cur->mp.begin(); i != cur->mp.end(); i++){
            int t = ret->mp[(*i).first];
            if(t > 0){
                if(t < MAXS)ret->light[t]--;
                else ret->heavy.erase(ret->heavy.lower_bound(t));
            }
                
            if(t + (*i).second < MAXS)ret->light[t + (*i).second]++;
            else ret->heavy.insert(t + (*i).second);
            
            ret->mp[(*i).first] += (*i).second;
        }
    }
    
    for(int j = 0; j < Q[i].size(); j++){
        int qi = Q[i][j].first, index = Q[i][j].second;
        
        for(multiset <int> :: iterator it = ret->heavy.begin(); it != ret->heavy.end(); it++)
            if((*it) >= qi)ans[index]++;
        
        for(int i = 0; i < MAXS; i++)
            if(i >= qi)ans[index] += ret->light[i];
    }
    
    return ret;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &c[i]);
    
    for(int e = 0; e < n - 1; e++){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    
    for(int i = 0; i < m; i++){
        scanf("%d %d", &ai, &bi);
        ai--;
        
        Q[ai].push_back(make_pair(bi, i));
    }
    
    solve(0);
    
    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
    
    return 0;
}