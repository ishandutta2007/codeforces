#include <iostream>
#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int INF = 1e9 + 7;
const int MAX_N = 1e4 + 6;

vector<int> r[MAX_N],c[MAX_N];
vector<int> edg[MAX_N];
pii p[MAX_N];
int dis[3*MAX_N];
queue<int> que[2];

#define SZ(x) ((int)x.size())

int main () {
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int st=0,ed=0;
    for (int i=1;k>=i;i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        p[i] = make_pair(x,y);
        if (x==1 && y==1) st=i;
        if (x==n && y==m) ed=i;
        r[x].push_back(i);
        c[y].push_back(i);
    }
    for (int i=1;n>=i;i++) {
        for (int j:r[i]) dis[p[j].second ] = j;
        for (int j:r[i]) {
            if (dis[ p[j].second-1 ]) {
                edg[ j ].push_back(dis[ p[j].second-1 ]);
                edg[ dis[ p[j].second-1 ] ].push_back(j);
            }
        }
        for (int j:r[i]) dis[p[j].second ] = 0;
    }
    for (int i=1;m>=i;i++) {
        for (int j:c[i]) dis[p[j].first ] = j;
        for (int j:c[i]) {
            if (dis[ p[j].first-1 ]) {
                edg[j].push_back(dis[p[j].first-1]);
                edg[dis[p[j].first-1]].push_back(j);
            }
        }
        for (int j:c[i]) dis[p[j].first] = 0;
    }
    fill(dis,dis+n+m+k+1,INF);
    dis[st] = 0;
    que[0].push(st);
    for (int cost=0; SZ(que[0]) || SZ(que[1]); cost++ ) {
        while (SZ(que[1])) {
            int t=que[1].front();
            que[1].pop();
            if(t > k+n) {
                t -= (k+n);
                for (int i=t-1;t+1>=i;i++) {
                    if (i<=0 || i>m) continue;
                    for (int j:c[i]) {
                        if (dis[j] > cost) {
                            dis[j] = cost;
                            que[0].push(j);
                        }
                    }
                }
            }
            else {
                t -= k;
                for (int i=t-1;t+1>=i;i++) {
                    if (i<=0 || i>n) continue;
                    for (int j:r[i]) {
                        if (dis[j] > cost) {
                            dis[j] = cost;
                            que[0].push(j);
                        }
                    }
                }
            }
        }
        while (SZ(que[0])) {
            int t=que[0].front();
            que[0].pop();
            for (int i:edg[t]) {
                if (dis[i] > cost) {
                    dis[i] = cost;
                    que[0].push(i);
                }
            }
            for (int i=p[t].first-1;p[t].first+1>=i;i++) {
                if (1<=i && i<=n && dis[k+i] > cost+1) {
                    dis[k+i] = cost+1;
                    que[1].push(k+i);
                }
            }
            for (int i=p[t].second-1;p[t].second+1>=i;i++) {
                if (1<=i && i<=m && dis[k+n+i] > cost+1) {
                    dis[k+n+i] = cost+1;
                    que[1].push(k+n+i);
                }
            }
        }
    }
    int ans=min(dis[k+n],dis[k+n+m]);
    //for (int i=1;k+n+m>=i;i++) cout<<dis[i]<<' ';
    //cout<<endl;
    if (ed) ans = min(ans,dis[ed]);
    if (ans==INF) puts("-1");
    else printf("%d\n",ans);
}