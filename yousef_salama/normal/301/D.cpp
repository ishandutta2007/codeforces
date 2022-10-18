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
using namespace std;

int n, m, li, ri, p[2 * 100005], pi[2 * 100005];
vector < pair <int, int> > q[2 * 100005];

vector <int> x[2 * 100005];
vector <int> y[2 * 100005];

int ans[2 * 100005];

int tree[2 * 100005], total;
void add(int i, int v){
    i++;
    total += v;

    while(i < 2 * 100005){
        tree[i] += v;
        i += i & (-i);
    }
}
int sum(int i){
    i++;
    
    int ret = 0;
    while(i > 0){
        ret += tree[i];
        i -= i & (-i);
    }
    return ret;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &p[i]);
        pi[p[i]] = i;
    }
    for(int i = 0; i < m; i++){
        scanf("%d %d", &li, &ri);
        li--, ri--;

        q[ri].push_back(make_pair(li, i));
        ans[i] += ri - li + 1;
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 2 * i; j <= n; j += i){
            x[i].push_back(j);
            y[j].push_back(i);
        }
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < x[p[i]].size(); j++)
            if(pi[x[p[i]][j]] < i)add(pi[x[p[i]][j]], 1);
        for(int j = 0; j < y[p[i]].size(); j++)
            if(pi[y[p[i]][j]] < i)add(pi[y[p[i]][j]], 1);

        for(int j = 0; j < q[i].size(); j++)
            ans[q[i][j].second] += total - sum(q[i][j].first - 1);
    }

    for(int i = 0; i < m; i++)
        printf("%d\n", ans[i]);

    return 0;
}