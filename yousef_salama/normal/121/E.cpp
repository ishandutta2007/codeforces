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

int lucky[1005], n_lucky;
void gen_lucky(int x){
    if(x > 1000000)return;
    
    lucky[n_lucky++] = x;
    gen_lucky(x * 10 + 4);
    gen_lucky(x * 10 + 7);
}

pair <int, int> tree[4 * 100005];
int n, m, added[4 * 100005];

inline void push(int i){
    tree[i].first += added[i];
    
    if(2 * i < 4 * 100005)added[2 * i] += added[i];
    if(2 * i + 1 < 4 * 100005)added[2 * i + 1] += added[i];
    
    added[i] = 0;
}

inline void init(int i = 1, int Left = 0, int Right = n - 1){
    if(Left == Right)tree[i] = make_pair(0, 1);
    else{
        int mid = (Left + Right) >> 1;
        
        init(2 * i, Left, mid);
        init(2 * i + 1, mid + 1, Right);
        
        tree[i] = make_pair(0, tree[2 * i].second + tree[2 * i + 1].second);
    }
}

inline void update(int L, int R, int val, int i = 1, int Left = 0, int Right = n - 1){
    push(i);
    
    if(L <= Left && Right <= R){
        added[i] += val;
        push(i);
        
        return;
    }
    if(Right < L || R < Left)return;
    
    int mid = (Left + Right) >> 1;
    update(L, R, val, 2 * i, Left, mid);
    update(L, R, val, 2 * i + 1, mid + 1, Right);
    
    if(tree[2 * i].first == tree[2 * i + 1].first)
        tree[i] = make_pair(tree[2 * i].first, tree[2 * i].second + tree[2 * i + 1].second);
    else if(tree[2 * i].first < tree[2 * i + 1].first)
        tree[i] = tree[2 * i];
    else tree[i] = tree[2 * i + 1];
}

inline pair <int, int> query(int L, int R, int i = 1, int Left = 0, int Right = n - 1){
    push(i);
    
    if(L <= Left && Right <= R)return tree[i];
    if(Right < L || R < Left)return make_pair(1 << 30, 0);
    
    int mid = (Left + Right) >> 1;
    pair <int, int> a1 = query(L, R, 2 * i, Left, mid);
    pair <int, int> a2 = query(L, R, 2 * i + 1, mid + 1, Right);
    
    if(a1.first == a2.first)return make_pair(a1.first, a1.second + a2.second);
    if(a1.first < a2.first)return a1;
    return a2;
}
inline int find_zeros(int L, int R){
    pair <int, int> q = query(L, R);
 
    if(q.first != 0)return 0;
    else return q.second;
}
inline int first_negative(int L, int i = 1, int Left = 0, int Right = n - 1){
    push(i);
    
    if(Right < L)return n;
    if(tree[i].first >= 0)return n;
    if(Left == Right)return Left;
    
    int mid = (Left + Right) >> 1;
    
    int t1 = first_negative(L, 2 * i, Left, mid);
    if(t1 < n)return t1;
    
    int t2 = first_negative(L, 2 * i + 1, mid + 1, Right);
    if(t2 < n)return t2;
}

int a[100005], cur_lucky[100005], u, v, x;
char str[10];
int main(){
    gen_lucky(0);
    sort(lucky, lucky + n_lucky);

    scanf("%d %d", &n, &m);
    
    init();
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);

        int d = lower_bound(lucky, lucky + n_lucky, a[i]) - lucky;
        cur_lucky[i] = d;
        update(i, i, lucky[d] - a[i]);
    }
 
    while(m--){
        scanf("%s", str);
        if(str[0] == 'c'){
            scanf("%d %d", &u, &v);
            u--, v--;
            
            printf("%d\n", find_zeros(u, v));
        }else{
            scanf("%d %d %d", &u, &v, &x);
            u--, v--;
            
            update(u, v, -x);
            
            int x = first_negative(0);
            while(x < n){
                int val = query(x, x).first;
                int cur = lucky[cur_lucky[x]] - val;
                
                cur_lucky[x] = lower_bound(lucky, lucky + n_lucky, cur) - lucky;
                update(x, x, - val + lucky[cur_lucky[x]] - cur);
                
                x = first_negative(x + 1);
            }
        }
    }
    return 0;
}