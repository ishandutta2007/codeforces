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

int n, ri, ans[MAXN][3];
map <int, int> f;

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &ri);
        f[ri]++;
    }
    
    priority_queue < pair <int, int> > q;
    for(map <int, int> :: iterator i = f.begin(); i != f.end(); i++)
        q.push(make_pair((*i).second, (*i).first));
    
    int k = 0;
    while(q.size() >= 3){
        vector < pair <int, int> > to_add;
        for(int i = 0; i < 3; i++){
            pair <int, int> t = q.top();
            q.pop();
            
            ans[k][i] = t.second;
            
            t.first--;
            if(t.first > 0)to_add.push_back(t);
        }
        k++;
        
        for(int i = 0; i < to_add.size(); i++)q.push(to_add[i]);
    }
    
    printf("%d\n", k);
    for(int i = 0; i < k; i++){
        sort(ans[i], ans[i] + 3);
        printf("%d %d %d\n", ans[i][2], ans[i][1], ans[i][0]);
    }
    return 0;
}