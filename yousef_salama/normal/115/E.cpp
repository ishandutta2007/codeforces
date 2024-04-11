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
#define MAXN 200005
using namespace std;
int n, m, lb, ub, p, repair[MAXN];
vector < pair <int, int> > v[MAXN];
long long tree[4 * MAXN], added[4 * MAXN];
void push(int i){
    tree[i] += added[i];
    
    if(2 * i < 4 * MAXN)added[2 * i] += added[i];
    if(2 * i + 1 < 4 * MAXN)added[2 * i + 1] += added[i];
    
    added[i] = 0;
}
long long query(int i, int Left, int Right, int L, int R){
    assert(Left <= Right);
    
    push(i);
    
    if(L <= Left && Right <= R)return tree[i];
    if(Right < L || R < Left)return -1 << 60;
    
    int mid = (Left + Right) / 2;
    return max(query(2 * i, Left, mid, L, R), query(2 * i + 1, mid + 1, Right, L, R));
}
void add(int i, int Left, int Right, int L, int R, long long val){
    assert(Left <= Right);
    
    push(i);

    if(L <= Left && Right <= R){
        added[i] += val;
        push(i);
        
        return;
    }
    if(Right < L || R < Left)return;
    
    int mid = (Left + Right) / 2;
    add(2 * i, Left, mid, L, R, val);
    add(2 * i + 1, mid + 1, Right, L, R, val);
    
    tree[i] = max(tree[2 * i], tree[2 * i + 1]);
}
void print(int i, int Left, int Right){
    cout << Left << ',' << Right << ':' << tree[i] << endl;
    if(Left == Right)return;
    
    int mid = (Left + Right) / 2;
    print(2 * i, Left, mid);
    print(2 * i + 1, mid + 1, Right);
}
int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", &repair[i]);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &lb, &ub, &p);
        lb--, ub--;
        
        v[ub].push_back(make_pair(lb, p)); 
    }
    for(int road = 0; road < n; road++){
        long long Max = query(1, 0, n, 0, road);
        add(1, 0, n, road + 1, road + 1, Max);
        
        add(1, 0, n, 0, road, -repair[road]);
        for(int i = 0; i < v[road].size(); i++)
            add(1, 0, n, 0, v[road][i].first, v[road][i].second);
    }
    printf("%I64d\n", tree[1]);
    return 0;
}