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

int n, x[200005], y[200005], t[200005], sx[200005], n_sx;
char s[10];

int tree[4 * 200005];
void update(int ind, int val, int i = 1, int L = 0, int R = n_sx - 1){
    if(ind < L || R < ind)return;
    
    if(L == R)tree[i] = val;
    else{
        int mid = (L + R) >> 1;
        update(ind, val, 2 * i, L, mid);
        update(ind, val, 2 * i + 1, mid + 1, R);
        
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }
}
int query(int ind, int val, int i = 1, int L = 0, int R = n_sx - 1){
    if(R <= ind)return -1;
    if(tree[i] <= val)return -1;
    if(L == R)return L;
    
    int mid = (L + R) >> 1;
    
    int t1 = query(ind, val, 2 * i, L, mid);
    if(t1 != -1)return t1;
    
    int t2 = query(ind, val, 2 * i + 1, mid + 1, R);
    if(t2 != -1)return t2;
    
    return -1;
}

multiset <int> points[200005];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", s, &x[i], &y[i]);
        sx[n_sx++] = x[i];
        
        if(s[0] == 'a')t[i] = 0;
        else if(s[0] == 'r')t[i] = 1;
        else t[i] = 2;
    }
    
    sort(sx, sx + n_sx);
    n_sx = unique(sx, sx + n_sx) - sx;
    
    for(int i = 0; i < n; i++){
        x[i] = lower_bound(sx, sx + n_sx, x[i]) - sx;
        if(t[i] == 0){
            points[x[i]].insert(y[i]);
            
            multiset <int> :: iterator d = points[x[i]].end();
            d--;
            
            update(x[i], *d);
        }else if(t[i] == 1){
            points[x[i]].erase(points[x[i]].lower_bound(y[i]));
            
            if(points[x[i]].empty())update(x[i], 0);
            else{
                multiset <int> :: iterator d = points[x[i]].end();
                d--;

                update(x[i], *d);
            }
        }else{
            int xi = query(x[i], y[i]);
         
            if(xi == -1)printf("-1\n");
            else printf("%d %d\n", sx[xi], *points[xi].upper_bound(y[i]));
        }
    }
    return 0;
}