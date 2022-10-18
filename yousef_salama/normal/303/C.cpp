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

int n, k, a[5005], lim;
int p[5005], cnt[5005];
vector < pair <int, int> > d[1000005];

int findr(int i){
    if(p[i] == i)return i;
    return p[i] = findr(p[i]);
}
void connect(int i, int j){
    if(findr(i) == findr(j))return;
    
    lim++;
    
    cnt[findr(j)] += cnt[findr(i)];
    p[findr(i)] = findr(j);
}

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    
    sort(a, a + n);
    for(int i = 0; i < n; i++)
    for(int j = i + 1; j < n; j++){
        int diff = a[j] - a[i];
        if(d[diff].size() <= k)
            d[diff].push_back(make_pair(i, j));
    }
    for(int i = 0; i < n; i++){
        p[i] = i;
        cnt[i] = 1;
    }
    
    int M = a[n - 1] + 1, m;
    for(m = 1; ; m++){
        bool ok = true;
        int s = 0;
        for(int j = m; j <= M; j += m){
            if(d[j].size() > k){
                ok = false;
                break;
            }
            s += d[j].size();
        }
        
        if(ok && (s <= k * (k + 1) / 2)){
            lim = 0;
            for(int j = m; j <= M; j += m)
            for(int i = 0; i < d[j].size(); i++){
                int a = d[j][i].first, b = d[j][i].second;
                connect(a, b);
            }
            
            if(lim <= k)break;
            
            for(int j = m; j <= M; j += m)
            for(int i = 0; i < d[j].size(); i++){
                int a = d[j][i].first, b = d[j][i].second;
                
                p[a] = a;
                p[b] = b;
                cnt[a] = cnt[b] = 1;
            }

        }
    }
    
    printf("%d\n", m);
    return 0;
}