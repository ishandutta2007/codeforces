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
using namespace std;

int n, q, type[100005], u[100005], v[100005], sx[300005], n_sx;
map <int, int> employee;

int tree[300005];
void add(int i, int val){
    i++;
    
    while(i < 300005){
        tree[i] += val;
        i += i & (-i);
    }
}
int find_sum(int i){
    i++;
    
    int res = 0;
    while(i > 0){
        res += tree[i];
        i -= i & (-i);
    }
    return res;
}
int get_x(int x){
    return lower_bound(sx, sx + n_sx, x) - sx;
}

struct segment{
    int l, r;
    segment(){}
    segment(int a, int b){
        l = a;
        r = b;
    }
};
bool operator <(segment a, segment b){
    if(a.r - a.l == b.r - b.l)return a.l > b.l;
    else return a.r - a.l > b.r - b.l;
}
struct cmp{
    bool operator ()(segment a, segment b){
        return a.l < b.l;
    }
};

int a[100005];
int main(){
    scanf("%d %d", &n, &q);
    for(int i = 0; i < q; i++){
        scanf("%d", &type[i]);
        if(type[i] == 0){
            scanf("%d %d", &u[i], &v[i]);
            u[i]--, v[i]--;
            
            sx[n_sx++] = u[i];
            sx[n_sx++] = v[i];
        }else{
            type[i]--;
            if(employee[type[i]] % 2 == 0){
                u[i] = type[i];
                type[i] = 1;
            }else{
                u[i] = type[i];
                type[i] = 2;
            }
            employee[u[i]]++;
            
            sx[n_sx++] = u[i];
        }
    }

    set <segment> segments;
    set <segment, cmp> pos;
    
    segments.insert(segment(0, n - 1));
    pos.insert(segment(0, n - 1));
    
    for(int i = 0; i < q; i++){
        if(type[i] == 1){
            segment cur = *segments.begin();
            
            int ind = (cur.l + cur.r + 1) / 2;
            employee[u[i]] = ind;
            
            segments.erase(cur);
            pos.erase(cur);
            
            if(cur.l < ind){
                segments.insert(segment(cur.l, ind - 1));
                pos.insert(segment(cur.l, ind - 1));
            }
            if(cur.r > ind){
                segments.insert(segment(ind + 1, cur.r));
                pos.insert(segment(ind + 1, cur.r));
            }
            
            a[i] = ind;
            sx[n_sx++] = a[i];
        }else if(type[i] == 2){
            int ind = employee[u[i]];
            
            set <segment> :: iterator d1 = pos.lower_bound(segment(ind, -2));
            set <segment> :: iterator d2 = d1;
            d1--;
            
            segment s1 = *d1, s2 = *d2, x = segment(ind, ind);
            if(s1.r + 1 == ind){
                x.l = s1.l;
                
                pos.erase(s1);
                segments.erase(s1);
            }
            if(ind == s2.l - 1){
                
                x.r = s2.r;
                pos.erase(s2);
                segments.erase(s2);
            }
            
            pos.insert(x);
            segments.insert(x);
        
            a[i] = ind;
            sx[n_sx++] = a[i];
        }
    }
    
    sort(sx, sx + n_sx);
    n_sx = unique(sx, sx + n_sx) - sx;
    
    for(int i = 0; i < q; i++){
        if(type[i] == 0){
            printf("%d\n", find_sum(get_x(v[i])) - find_sum(get_x(u[i]) - 1));
        }else if(type[i] == 1){
            add(get_x(a[i]), 1);
        }else add(get_x(a[i]), -1);
    }
    return 0;
}