#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <utility>
#include <vector>
using namespace std;

typedef pair< int,pair<int,int> > piii;
const int MAX_N = 2e5 + 6;
int match[MAX_N];
bool visit[MAX_N];
vector<int> edg[MAX_N];

piii p[MAX_N];

struct DisjointSet {
    int p[MAX_N],princess[MAX_N],prince[MAX_N];
    void init(int n) {
        for (int i=0;n>=i;i++) {
            p[i] = i;
            prince[i] = 1;
            princess[i] = 0;
        }
    }
    int Find(int x) {
        return x==p[x]?x:p[x]=Find(p[x]);
    }
    int Union(int x,int y) {
        x=Find(x);
        y=Find(y);
        if (x==y) return x;
        p[y] = x;
        prince[x] += prince[y];
        princess[x] += princess[y];
        return x;
    }
} djs;

int main () {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;m>=i;i++) {
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        p[i] = { w,{a,b} };
    }
    sort(p+1,p+m+1);
    for (int i=1;m>=i;i++) {
        //edg[i].push_back(p[i].second.first);
        //edg[i].push_back(p[i].second.second);
    }
    djs.init(n);
    int ans=0;
    memset(match,-1,sizeof(match));
    for (int i=m;i>=1;i--) {
        //memset(visit,0,sizeof(visit));
        //if (dfs(i)) ans += p[i].first;
        int t=djs.Union(p[i].second.first,p[i].second.second);
        if (djs.prince[t] > djs.princess[t]) {
            ans += p[i].first;
            djs.princess[t]++;
        }
    }
    printf("%d\n",ans);
}