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
#define MOD 1000000007
using namespace std;

int n, m, p, a[200005], b[200005];
int main(){
    scanf("%d %d %d", &n, &m, &p);
    for(int i = 0; i < n; i++)scanf("%d", &a[i]);
    
    map <int, int> cb;
    set <int> sb;
    for(int i = 0; i < m; i++){
        scanf("%d", &b[i]);
        cb[b[i]]++;
        sb.insert(b[i]);
    }
    
    vector <int> ans;
    
    for(int st = 0; (st < p) && (st < n); st++){
        vector <int> v;
        map <int, int> ca;
        for(int i = st; i < n; i += p)
            v.push_back(a[i]);
        
        if(v.size() < m)continue;
        
        int diff = sb.size();
        
        for(int i = 0; i < m; i++){
            if(ca[v[i]] == cb[v[i]])diff++;
            ca[v[i]]++;
            if(ca[v[i]] == cb[v[i]])diff--;
        }
        
        if(diff == 0)ans.push_back(st);
        
        for(int i = 1; i + m <= v.size(); i++){
            if(ca[v[i - 1]] == cb[v[i - 1]])diff++;
            ca[v[i - 1]]--;
            if(ca[v[i - 1]] == cb[v[i - 1]])diff--;
            
            if(ca[v[i + m - 1]] == cb[v[i + m - 1]])diff++;
            ca[v[i + m - 1]]++;
            if(ca[v[i + m - 1]] == cb[v[i + m - 1]])diff--;
            
            if(diff == 0)ans.push_back(st + i * p);
        }
    }
    
    sort(ans.begin(), ans.end());
    
    printf("%d\n", ans.size());
    for(int i = 0; i < ans.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", ans[i] + 1);
    }
    printf("\n");
    return 0;
}