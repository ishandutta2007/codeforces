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
#include <unordered_map>

using namespace std;

int n, a[200005], x[200005], d[200005];
bool isCycle[200005], vis[200005];

vector < vector <int> > cycles;
vector <int> cur_cycle;

void dfs(int i){
    cur_cycle.push_back(i);
    vis[i] = true;
    
    if(!vis[a[i]])dfs(a[i]);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i]--;
        
        x[a[i]] ^= i;
        d[a[i]]++;
        
        isCycle[i] = true;
    }
    
    queue <int> q;
    for(int i = 0; i < n; i++)
        if(d[i] == 0)q.push(i);
    
    while(!q.empty()){
        int t = q.front();
        q.pop();
        
        isCycle[t] = false;
        
        x[a[t]] ^= t;
        d[a[t]]--;
        
        if(d[a[t]] == 0)q.push(a[t]);
    }
    
    int f = -1;
    for(int i = 0; i < n; i++)if(isCycle[i]){
        if(!vis[i]){
            cur_cycle.clear();
            dfs(i);
            
            cycles.push_back(cur_cycle);
            
            if(f == -1)f = i;
            if(cur_cycle.size() == 1)f = i;
        }
    }
    
    int r = 0;
    for(int i = 0; i < cycles.size(); i++){
        if(cycles[i][0] != f){
            r++;
            a[cycles[i][0]] = f;
        }else{
            if(cycles[i].size() != 1){
                r++;
                a[cycles[i][0]] = f;
            }
        }
    }
    
    printf("%d\n", r);
    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", a[i] + 1);
    }
    printf("\n");
    
    return 0;
}