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
int n, m, ui, vi, ai, bi, subtreeSize[MAXN], answer[MAXN], in[MAXN], out[MAXN], curTime;
vector <int> g[MAXN], queries[MAXN];

struct BIT{
    int tree[MAXN];
    void add(int i, int value){
        i++;
        
        while(i < MAXN){
            tree[i] += value;
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
} t, isMarked;

void calcSize(int i, int p){
    in[i] = ++curTime;
    subtreeSize[i] = 1;
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u != p){
            calcSize(u, i);
            subtreeSize[i] += subtreeSize[u];
        }
    }
    out[i] = curTime;
}

int curAnswer;
stack <int> updates, times;
void insert(int i){
    if(isMarked.sum(in[i]) == 0){
        int x = subtreeSize[i] - (t.sum(out[i]) - t.sum(in[i] - 1));

        isMarked.add(in[i], 1);
        isMarked.add(out[i] + 1, -1);

        t.add(in[i], x);
        curAnswer += x;
        updates.push(x);
        times.push(curTime);
    }
}
void remove(int i){
    if(times.top() == curTime){
        times.pop();

        int x = updates.top();
        updates.pop();

        isMarked.add(in[i], -1);
        isMarked.add(out[i] + 1, 1);

        t.add(in[i], -x);
        curAnswer -= x;
    }
}
void calcAnswer(int i, int p){
    for(int j = 0; j < queries[i].size(); j++){
        curTime++;
        insert(i);
        curTime++;
        insert(queries[i][j]);
    }
    
    answer[i] = max(0, curAnswer - 1);
    for(int j = 0; j < g[i].size(); j++){
        int u = g[i][j];
        if(u != p)calcAnswer(u, i);
    }
    
    for(int j = ((int)queries[i].size()) - 1; j >= 0; j--){
        remove(queries[i][j]);
        curTime--;
        remove(i);
        curTime--;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int e = 0; e < n - 1; e++){
        scanf("%d %d", &ui, &vi);
        ui--, vi--;
        
        g[ui].push_back(vi);
        g[vi].push_back(ui);
    }
    while(m--){
        scanf("%d %d", &ai, &bi);
        ai--, bi--;
        
        queries[ai].push_back(bi);
        queries[bi].push_back(ai);
    }
    curTime = 0;
    calcSize(0, -1);
    curTime = 0;
    calcAnswer(0, -1);

    for(int i = 0; i < n; i++){
        if(i > 0)printf(" ");
        printf("%d", answer[i]);
    }
    return 0;
}