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

int n, q, ci, xi;
set <int> m[300005];
vector <int> all;

int main(){
    scanf("%d %d", &n, &q);
    
    set < pair <int, int> > s;
    int id = 0, b = 0;
    while(q--){
        scanf("%d %d", &ci, &xi);
        if(ci == 1){
            m[--xi].insert(id);
            s.insert(make_pair(id, xi));
            id++;
            
            all.push_back(xi);
        }else if(ci == 2){
            xi--;
            while(m[xi].size() > 0){
                set <int> :: iterator it = m[xi].end();
                --it;
                
                s.erase(make_pair(*it, xi));
                m[xi].erase(it);
            }
        }else{
            if(xi > b){
                for(int i = b; i < xi; i++){
                    s.erase(make_pair(i, all[i]));
                    m[all[i]].erase(i);
                }
                b = xi;
            }
        }
        
        printf("%d\n", s.size());
    }
    return 0;
}