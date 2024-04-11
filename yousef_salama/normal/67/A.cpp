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

const int MAXN = 1005;

int n;
char s[MAXN];

vector <int> g[MAXN];
int Gtoffees[MAXN], indegree[MAXN];

int main(){
    scanf("%d %s", &n, s);

    memset(indegree, 0, sizeof indegree);
    
    int ncomponent = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] == 'L'){
            ncomponent++;
            
            indegree[ncomponent - 1]++;
            g[ncomponent].push_back(ncomponent - 1);
        }
        if(s[i] == 'R'){
            indegree[ncomponent + 1]++;
            
            g[ncomponent].push_back(ncomponent + 1);
            ncomponent++;
        }
    }
    ncomponent++;
    
    memset(Gtoffees, 0, sizeof Gtoffees);
    
    queue <int> q;
    for(int i = 0; i < ncomponent; i++){
        if(indegree[i] == 0){
            Gtoffees[i] = 1;
            q.push(i);
        }
    }
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < g[u].size(); i++){
            int v = g[u][i];
            indegree[v]--;
            
            if(indegree[v] == 0){
                Gtoffees[v] += Gtoffees[u] + 1;
                q.push(v);
            }
        }
    }
    
    int ccomponent = 0;

    printf("%d", Gtoffees[0]);
    for(int i = 0; i < n - 1; i++){
        if(s[i] == '=')printf(" %d", Gtoffees[ccomponent]);
        else printf(" %d", Gtoffees[++ccomponent]);
    }
    printf("\n");
    
    return 0;
}