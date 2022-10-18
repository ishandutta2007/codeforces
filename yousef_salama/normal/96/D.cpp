#include <cstring>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>
#include <list>
#include <climits>
#include <cctype>
#include <bitset>
#define Trvi(it, taxis) for(__typeof(taxis.begin()) it = taxis.begin(); it != taxis.end(); ++it)
#define MAX 1000000000000000LL
using namespace std;
struct edge{
    long long a, b, cost;
    edge(long long i, long long j, long long k){
        a = i;
        b = j;
        cost = k;
    }
};
struct taxi{
    long long t, c;
    taxi(long long i, long long j){
        t = i;
        c = j;
    }
};
struct state{
    long long cost, idx;
    state(long long i, long long j){
        cost = i;
        idx = j;
    }
};
long long N, M, src, dest, a, b, c;
vector <edge> g[1005];
vector <taxi> taxis;
long long d[1005][1005], dist[1005];
long long v[1005];
bool operator <(state a, state b){
    return a.cost > b.cost;
}
int main(){
    cin >> N >> M;
    cin >> src >> dest;
    src--; dest--;
    while(M--){
        cin >> a >> b >> c;
        g[a - 1].push_back(edge(a - 1, b - 1, c));
        g[b - 1].push_back(edge(b - 1, a - 1, c));
    }
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        taxis.push_back(taxi(a, b));
    }
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            d[i][j] = MAX;
    for(int i = 0; i < N; i++){
        d[i][i] = 0;
        priority_queue <state> pq;
        pq.push(state(0, i));
        memset(v, 0, sizeof v);
        while(!pq.empty()){
            state p = pq.top();
            pq.pop();
            if(v[p.idx])continue;
            v[p.idx] = 1;
            for(int j = 0; j < g[p.idx].size(); j++){
                edge next = g[p.idx][j];
                if(p.cost + next.cost < d[i][next.b]){
                    d[i][next.b] = p.cost + next.cost;
                    pq.push(state(d[i][next.b], next.b));
                }
            }
        }
    }
    for(int i = 0; i < N; i++)
        dist[i] = MAX;
    dist[src] = 0;
    priority_queue <state> pq;
    pq.push(state(0, src));
    memset(v, 0, sizeof v);
    while(!pq.empty()){
        state p = pq.top();
        pq.pop();
        if(v[p.idx])continue;
        v[p.idx] = 1;
        for(int i = 0; i < N; i++)
            if(d[p.idx][i] <= taxis[p.idx].t && p.cost + taxis[p.idx].c < dist[i]){
                dist[i] = p.cost + taxis[p.idx].c;
                pq.push(state(dist[i], i));
            }
    }
    if(dist[dest] == MAX)printf("-1\n");
    else cout << dist[dest] << endl;
    return 0;
}