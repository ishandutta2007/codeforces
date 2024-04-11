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

int ind[200005], tail[200005], next_ind[200005];
struct competitor{
    int st_ind;
    long long r, s;
} v[200005], r[200005];

bool operator <(competitor a, competitor b){
    return (a.r > b.r) || ((a.r == b.r) && (a.s > b.s));
}

bool ok(competitor a, competitor b, competitor c){
    if((a.r - b.r) * (a.s - c.s) * b.s * c.r -
        (a.r - c.r) * (a.s - b.s) * c.s * b.r < 0)return false;
    else return true;
}

int n, ans[200005];
void zabat(){
    int m = 0;
    for(int i = 0; i < n; i++){
        if(m == 0)v[m++] = v[i];
        else{
            if((v[m - 1].r != v[i].r) || (v[m - 1].s != v[i].s))v[m++] = v[i];
            else tail[v[m - 1].st_ind] = next_ind[tail[v[m - 1].st_ind]] = v[i].st_ind;
        }
    }
    n = m;
}

int main(){
    scanf("%d", &n);
    
    int ninds = 0;
    memset(next_ind, -1, sizeof next_ind);
    
    for(int i = 0; i < n; i++){
        scanf("%I64d %I64d", &v[i].r, &v[i].s);
        ind[tail[v[i].st_ind] = v[i].st_ind = ninds++] = i + 1;;
    }
    sort(v, v + n);
    zabat();
    
    int nr = 0;
    for(int i = 0; i < n; i++){
        if(nr == 0)r[nr++] = v[i];
        else{
            if(r[nr - 1].s >= v[i].s)continue;
            
            while((nr >= 2) && !ok(r[nr - 2], r[nr - 1], v[i]))
                nr--;
            r[nr++] = v[i];
        }
    }
    
    
    int nans = 0;
    for(int i = 0; i < nr; i++)
    for(int j = r[i].st_ind; j != -1; j = next_ind[j])
        ans[nans++] = ind[j];
    sort(ans, ans + nans);
    
    for(int i = 0; i < nans; i++){
        if(i > 0)printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    
    return 0;
}