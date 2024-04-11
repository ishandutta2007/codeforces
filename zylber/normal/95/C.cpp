#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

#define forn(a,n) for(int a = 0; a<(n); ++a)

typedef long long tint;

int n, m, s, f;
vector<pair<int, tint> > adyArm[1004];
vector<pair<int, tint> > ady[1004];
tint maxDrive, cost, dist[1004];

struct est{
    int pos; tint dist;
    est() {}
    est(int a, tint b) {pos = a; dist = b;}
};

bool operator<(const est &e0, const est &e1) {
    return e0.dist > e1.dist;
}

void dijkstraJuntar(int pos) {
    memset(dist,-1,sizeof(dist));
    priority_queue<est> q;
    dist[pos] = 0;
    q.push(est(pos,0));
    
    while(!q.empty()) {
        est e = q.top(); q.pop();
        
        if(e.dist != dist[e.pos]) continue;
        ady[pos].push_back(make_pair(e.pos, cost));
        
        forn(i, adyArm[e.pos].size()){
            int nn = adyArm[e.pos][i].first;
            tint d = e.dist+adyArm[e.pos][i].second;
            
            if(d > maxDrive) continue;
            if(dist[nn] == -1 || dist[nn] > d) {
                dist[nn] = d;
                q.push(est(nn, d));
            }
        }
    }
}

tint dijkstra() {
    memset(dist, -1, sizeof(dist));
    priority_queue<est> q;
    dist[s] = 0;
    q.push(est(s,0));
    
    while(!q.empty()) {
        est e = q.top(); q.pop();
        
        if(e.dist != dist[e.pos]) continue;
        if(e.pos == f) return e.dist;
        
        forn(i, ady[e.pos].size()){
            int nn = ady[e.pos][i].first;
            tint d = e.dist+ady[e.pos][i].second;
            
            if(dist[nn] == -1 || dist[nn] > d) {
                dist[nn] = d;
                q.push(est(nn, d));
            }
        }
    }
    return -1;
}

int main()
{
#ifdef ACMTUYO
    freopen("G.in", "r", stdin);
#endif
    cin >> n >> m;
    cin >> s >> f;
    s--; f--;
    forn(i,n){
        adyArm[i].clear();
        ady[i].clear();
    }
    forn(i,m) {
        int u, v; tint w;
        cin >> u >> v >> w;
        u--;v--;
        adyArm[u].push_back(make_pair(v,w));
        adyArm[v].push_back(make_pair(u,w));
    }
    
    forn(i,n) {
        cin >> maxDrive >> cost;
        dijkstraJuntar(i);
    }
    
    cout << dijkstra() << endl;
    
    return 0;
}