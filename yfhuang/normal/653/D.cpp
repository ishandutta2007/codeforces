//
//  main.cpp
//  ISAP
//
//  Created by  on 16/3/22.
//  Copyright  2016 . All rights reserved.
//

#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;

const int maxn = 50 + 10;
const int maxm = 500 + 10;
const int INF = 1000000000;

int u[maxm],v[maxm],c[maxm];

struct Edge {
    long long from, to, cap, flow;
};

bool operator < (const Edge& a, const Edge& b) {
    return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct ISAP {
    long long n, m, s, t;
    vector<Edge> edges;
    vector<long long> G[maxn];   // G[i][j]ije
    bool vis[maxn];        // BFS
    long long d[maxn];           // i
    long long cur[maxn];        // 
    long long p[maxn];          // 
    long long num[maxn];        // 
    
    void AddEdge(int from, int to, long long cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    
    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<long long> Q;
        Q.push(t);
        vis[t] = 1;
        d[t] = 0;
        while(!Q.empty()) {
            long long x = Q.front(); Q.pop();
            for(int i = 0; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]^1];
                if(!vis[e.from] && e.cap > e.flow) {
                    vis[e.from] = 1;
                    d[e.from] = d[x] + 1;
                    Q.push(e.from);
                }
            }
        }
        return vis[s];
    }
    
    void ClearAll(int n) {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    
    void ClearFlow() {
        for(int i = 0; i < edges.size(); i++) edges[i].flow = 0;
    }
    
    long long Augment() {
        long long x = t, a = INF;
        while(x != s) {
            Edge& e = edges[p[x]];
            a = min(a, e.cap-e.flow);
            x = edges[p[x]].from;
        }
        x = t;
        while(x != s) {
            edges[p[x]].flow += a;
            edges[p[x]^1].flow -= a;
            x = edges[p[x]].from;
        }
        return a;
    }
    
    int Maxflow(int s, int t) {
        this->s = s; this->t = t;
        int flow = 0;
        BFS();
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) num[d[i]]++;
        long long x = s;
        memset(cur, 0, sizeof(cur));
        while(d[s] < n) {
            if(x == t) {
                flow += Augment();
                x = s;
            }
            int ok = 0;
            for(long long i = cur[x]; i < G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if(e.cap > e.flow && d[x] == d[e.to] + 1) { // Advance
                    ok = 1;
                    p[e.to] = G[x][i];
                    cur[x] = i; // 
                    x = e.to;
                    break;
                }
            }
            if(!ok) { // Retreat
                long long m = n-1; // 
                for(int i = 0; i < G[x].size(); i++) {
                    Edge& e = edges[G[x][i]];
                    if(e.cap > e.flow) m = min(m, d[e.to]);
                }
                if(--num[d[x]] == 0) break;
                num[d[x] = m+1]++;
                cur[x] = 0; // 
                if(x != s) x = edges[p[x]].from;
            }
        }
        return flow;
    }
    
    vector<int> Mincut() { // call this after maxflow
        BFS();
        vector<int> ans;
        for(int i = 0; i < edges.size(); i++) {
            Edge& e = edges[i];
            if(!vis[e.from] && vis[e.to] && e.cap > 0) ans.push_back(i);
        }
        return ans;
    }
    
    void Reduce() {
        for(int i = 0; i < edges.size(); i++) edges[i].cap -= edges[i].flow;
    }
    
};


ISAP g;



int main(int argc, const char * argv[]) {
    int n,m,x;
    scanf("%d%d%d",&n,&m,&x);
    double l=0,r=0;
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",u+i,v+i,c+i);
        r=max(r,(double)c[i]);
    }
    for(int i=1;i<=50;i++){
        double mid=(l+r)/2;
        g.ClearAll(n+2);
        g.ClearFlow();
        //cout<<mid<<endl;
        for(int j=1;j<=m;j++){
            g.AddEdge(u[j], v[j], (long long)((c[j]*1.0+1e-6)/mid));
        }
        //int ans=g.Maxflow(1, n);
        //cout<<ans<<endl;
        if(g.Maxflow(1, n)>=x) l=mid;
        else r=mid;
    }
    printf("%.10lf\n",l*x);
    return 0;
}