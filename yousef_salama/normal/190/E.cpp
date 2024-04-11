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
#include <sstream>
#include <string.h>
#include <assert.h>
#include <numeric>
#define MAXN 500005
using namespace std;
int n, m, ai, bi;
vector <int> g[MAXN];
set <int> s;
vector < vector <int> > comp;
int main(){
    scanf("%d %d", &n, &m);
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }
    for(int i = 0; i < n; i++){
        sort(g[i].begin(), g[i].end());
        s.insert(i);
    }
    for(int i = 0; i < n; i++){
        if(s.count(i)){
            queue <int> q;
            vector <int> c;
            
            q.push(i);
            s.erase(i);
            while(!q.empty()){
                int k = q.front();
                q.pop();

                c.push_back(k);
                vector <int> a;
                for(set <int> :: iterator d = s.begin(); d != s.end(); d++)
                    if(!binary_search(g[k].begin(), g[k].end(), *d)){
                        q.push(*d);
                        a.push_back(*d);
                    }
                for(int i = 0; i < a.size(); i++)
                    s.erase(a[i]);
            }
            comp.push_back(c);
        }
    }
    printf("%d\n", comp.size());
    for(int i = 0; i < comp.size(); i++){
        printf("%d", comp[i].size());
        for(int j = 0; j < comp[i].size(); j++)
            printf(" %d", comp[i][j] + 1);
        printf("\n");
    }
    return 0;
}