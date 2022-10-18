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
#define MAXN 100005
using namespace std;

int curTime, n, q, li[MAXN], ri[MAXN], Next[MAXN], Prev[MAXN], ans[MAXN], first_visit[MAXN], tree[4 * MAXN];
char s[MAXN];
bool vis[MAXN];

vector <int> d;
vector < pair < vector <int>, int> > c;

struct Query{
    int li, ri, index;
    Query(int a, int b, int c){
        li = a;
        ri = b;
        index = c;
    }
};
vector <Query> v[MAXN * 20];

set <int> active;
int move(int x, int dir){
    set <int> :: iterator d = active.find(x);
    assert(d != active.end());
    if(dir == 1)d++; else d--;
    
    return *d;
}
void update(int i, int L, int R, int ind, int val){
    if(ind < L || R < ind)return;
    if(L == R){
        tree[i] = val;
        return;
    }
    int mid = (L + R) / 2;
    update(2 * i, L, mid, ind, val);
    update(2 * i + 1, mid + 1, R, ind, val);
    
    tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}
int query(int i, int L, int R, int u, int v){
    if(u <= L && R <= v)return tree[i];
    if(v < L || R < u)return 1 << 30;
    
    int mid = (L + R) / 2;
    return min(query(2 * i, L, mid, u, v), query(2 * i + 1, mid + 1, R, u, v));
}
int main(){
    scanf("%d %d %s", &n, &q, s + 1);
    s[0] = s[++n] = '#';
    
    for(int i = 0; i <= n; i++)
        active.insert(i);
    
    d.resize(10);
    memset(first_visit, 63, sizeof first_visit);
    for(int start = 1; start < n; start++){
        if(!vis[start]){
            int x = start, dir = 1;
            while(start <= x && x < n){
                first_visit[x] = min(first_visit[x], (int)c.size());
                c.push_back(make_pair(d, x));
                vis[x] = true;

                int removed = -1;
                if('0' <= s[x] && s[x] <= '9'){
                    d[s[x] - '0']++;
                    
                    if(s[x] == '0')removed = x;
                    else s[x]--;
                }else{
                    if(s[x] == '<'){
                        dir = -1;
                        if(s[move(x, dir)] == '>' || s[move(x, dir)] == '<')removed = x;
                    }else{
                        dir = 1;
                        if(s[move(x, dir)] == '>' || s[move(x, dir)] == '<')removed = x;
                    }
                }
                x = move(x, dir);
                if(removed >= 0)active.erase(removed);
            }

            c.push_back(make_pair(d, x));
        }
    }

    for(int i = 0; i < q; i++){
        scanf("%d %d", &li[i], &ri[i]);
        int ti = first_visit[li[i]];

        v[ti].push_back(Query(li[i], ri[i], i));
    }
    memset(tree, 63, sizeof tree);
    for(int i = c.size() - 1; i >= 0; i--){
        for(int j = 0; j < v[i].size(); j++)
            ans[v[i][j].index] = min(query(1, 0, n, 0, v[i][j].li - 1), query(1, 0, n, v[i][j].ri + 1, n));
        update(1, 0, n, c[i].second, i);
    }

    for(int i = 0; i < q; i++){
        for(int j = 0; j < 10; j++){
            if(j > 0)printf(" ");
            printf("%d", c[ans[i]].first[j] - c[first_visit[li[i]]].first[j]);
        }
        printf("\n");
    }
    return 0;
}