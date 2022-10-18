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

int n, e, a[MAXN], xi, yi;
vector <int> g[MAXN];

int m[MAXN], s[MAXN];
bool marked[MAXN];

int findpar(int x){
    if(m[x] == x)return x;
    return m[x] = findpar(m[x]);
}
void unionpar(int x, int y){
    s[findpar(y)] += s[findpar(x)];
    m[findpar(x)] = findpar(y);
}


int main(){
    scanf("%d %d", &n, &e);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    while(e--){
        scanf("%d %d", &xi, &yi);
        xi--, yi--;
        
        g[xi].push_back(yi);
        g[yi].push_back(xi);
    }
    
    vector < pair <int, int> > v;
    for(int i = 0; i < n; i++)
        v.push_back(make_pair(a[i], i));
    sort(v.rbegin(), v.rend());
    
    for(int i = 0; i < n; i++){
        m[i] = i;
        s[i] = 1;
    }
    
    int i = 0;
    
    double total_res = 0;
    
    while(i < n){
        int j = i;
        while(j < n){
            if(v[j].first == v[i].first){
                marked[v[j].second] = true;
                j++;
            }else break;
        }
        double cur_res = 0;
        for(int k = i; k < j; k++){
            for(int u = 0; u < g[v[k].second].size(); u++){
                int ui = g[v[k].second][u];
                
                if(!marked[ui])continue;
                
                if(findpar(v[k].second) == findpar(ui))continue;
                
                cur_res += (long long)s[findpar(v[k].second)] * s[findpar(ui)] * 2;
                unionpar(v[k].second, ui);
            }
        }
        total_res += cur_res * v[i].first;
        i = j;
    }

    total_res /= n;
    total_res /= n - 1;
    
    printf("%.6f\n", total_res);
    
    return 0;
}