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
int n, m, a, b, g[1005][1005], col[1005][1005], tree[1005][1005];
long long sum[1005][1005], mn[1005][1005];
bool prin[1000005];
vector < pair <long long, pair <int, int> > > v;
long long calc_sum(int p1, int p2, int p3, int p4){
    p1++, p2++, p3++, p4++;
    
    return sum[p3][p4] - sum[p1 - 1][p4] - sum[p3][p2 - 1] + sum[p1 - 1][p2 - 1];
}
int query(int i, int j){
    i++, j++;
    
    int ret = 0;
    while(i > 0){
        int xj = j;
        while(xj > 0){
            ret += tree[i][xj];
            xj -= xj & (-xj);
        }
        i -= i & (-i);
    }
    return ret;
}
void add_used(int i, int j){
    i++, j++;
    
    while(i < 1005){
        int xj = j;
        while(xj < 1005){
            tree[i][xj]++;
            xj += xj & (-xj);
        }
        i += i & (-i);
    }
}
int sum_used(int p1, int p2, int p3, int p4){
    return query(p3, p4) - query(p1 - 1, p4) - query(p3, p2 - 1) + query(p1 - 1, p2 - 1);
}
int main(){
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)
        scanf("%d", &g[i][j]);
    
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + g[i - 1][j - 1];
    
    for(int j = 0; j < m; j++){
        multiset <int> s;
        for(int k = 0; k < a; k++)
            s.insert(g[k][j]);
        
        col[0][j] = *s.begin();
        for(int i = 1; i + (a - 1) < n; i++){
            s.erase(s.find(g[i - 1][j]));
            s.insert(g[i + (a - 1)][j]);
            
            col[i][j] = *s.begin();
        }
    }
    for(int i = 0; i + (a - 1) < n; i++){
        multiset <int> s;
        for(int k = 0; k < b; k++)
            s.insert(col[i][k]);
        
        mn[i][0] = *s.begin();
        for(int j = 1; j + (b - 1) < m; j++){
            s.erase(s.find(col[i][j - 1]));
            s.insert(col[i][j + (b - 1)]);
            
            mn[i][j] = *s.begin();
        }
    }
    for(int i = 0; i + (a - 1) < n; i++)
    for(int j = 0; j + (b - 1) < m; j++){
        v.push_back(make_pair(calc_sum(i, j, i + (a - 1), j + (b - 1)) - mn[i][j] * a * b,
                make_pair(i, j)));
    }
    sort(v.begin(), v.end());
    
    int k = 0;
    for(int i = 0; i < v.size(); i++){
        if(sum_used(v[i].second.first, v[i].second.second, 
                v[i].second.first + (a - 1), v[i].second.second + (b - 1)) == 0){
            for(int p1 = v[i].second.first; p1 <= v[i].second.first + (a - 1); p1++)
            for(int p2 = v[i].second.second; p2 <= v[i].second.second + (b - 1); p2++)
                add_used(p1, p2);
            
            prin[i] = true;
            k++;
        }
    }
    printf("%d\n", k);
    for(int i = 0; i < v.size(); i++){
        if(prin[i]){
            printf("%d %d %I64d\n", v[i].second.first + 1, v[i].second.second + 1, v[i].first);
        }
    }
    return 0;
}