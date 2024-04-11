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


int n, ai, bi, ci, di;
pair < pair < pair <int, int>, pair <int, int> >, int> s[100005];

int mn_y[4 * 100005], mn_x[4 * 100005], mx_x[4 * 100005];
void build(int i, int L, int R){
    if(L == R){
        mn_x[i] = mx_x[i] = s[L].first.first.first;
        mn_y[i] = s[L].first.first.second;

        return;
    }

    int mid = (L + R) / 2;
    build(2 * i, L, mid);
    build(2 * i + 1, mid + 1, R);

    mn_y[i] = min(mn_y[2 * i], mn_y[2 * i + 1]);
    mn_x[i] = min(mn_x[2 * i], mn_x[2 * i + 1]);
    mx_x[i] = max(mx_x[2 * i], mx_x[2 * i + 1]);
}

queue < pair < pair <int, int>, int> > que;
int cur, pi[100005];
void query(int i, int L, int R, int p, int q){
    if(mn_x[i] == -1)return;

    if(mn_x[i] > p)return;
    if(mn_y[i] > q)return;

    if(L == R){
        que.push(make_pair(make_pair(s[L].first.second.first, s[L].first.second.second), s[L].second));
        mn_x[i] = mx_x[i] = mn_y[i] = -1;

        pi[s[L].second] = cur;

        return;
    }

    int mid = (L + R) / 2;
    query(2 * i, L, mid, p, q);
    query(2 * i + 1, mid + 1, R, p, q);

    if(mn_x[2 * i] == -1){
        mn_x[i] = mn_x[2 * i + 1];
        mx_x[i] = mx_x[2 * i + 1];
        mn_y[i] = mn_y[2 * i + 1];
    }else if(mn_x[2 * i + 1] == -1){
        mn_x[i] = mn_x[2 * i];
        mx_x[i] = mx_x[2 * i];
        mn_y[i] = mn_y[2 * i];
    }else{
        mn_y[i] = min(mn_y[2 * i], mn_y[2 * i + 1]);
        mn_x[i] = min(mn_x[2 * i], mn_x[2 * i + 1]);
        mx_x[i] = max(mx_x[2 * i], mx_x[2 * i + 1]);
    }
}
int main(){
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &ai, &bi, &ci, &di);
        s[i] = make_pair(make_pair(make_pair(ai, bi), make_pair(ci, di)), i);
    }
    sort(s, s + n);
    build(1, 0, n - 1);

    for(int i = 0; i < n; i++)pi[i] = -2;
    que.push(make_pair(make_pair(0, 0), -1));

    while(!que.empty()){
        pair < pair <int, int>, int> t = que.front();
        que.pop();

        cur = t.second;
        query(1, 0, n - 1, t.first.first, t.first.second);
    }
    
    if(pi[n - 1] == -2){
        printf("-1\n");
        return 0;
    }

    vector <int> r;

    int u = n - 1;
    while(u != -1){
        r.push_back(u);
        u = pi[u];        
    }
    reverse(r.begin(), r.end());

    printf("%d\n", r.size());
    for(int i = 0; i < r.size(); i++){
        if(i > 0)printf(" ");
        printf("%d", r[i] + 1);
    }
    printf("\n");


    return 0;
}