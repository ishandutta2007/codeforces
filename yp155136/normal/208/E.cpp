#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 1e5 + 6;
const int MAX_P = 21;

vector<int> edg[MAX_N];
vector<int> d[MAX_N];
int lca[MAX_P][MAX_N];
int rhs[MAX_P][MAX_N];  //right highest son
int lhs[MAX_P][MAX_N];  //left highest son
int lc[MAX_N];
int rc[MAX_N];
int depth[MAX_N];
int ans[MAX_N];
int iden[MAX_N];

void dfs(int id,int cur_depth) {
    iden[id] = d[cur_depth].size();
    d[cur_depth].push_back(id);
    depth[id] = cur_depth;
    for (vector<int>::iterator iter=edg[id].begin();iter != edg[id].end();iter++) {
        int tmp = *iter;
        if (depth[tmp] == -1) {
            dfs(tmp,cur_depth+1);
        }
    }
}

int go(int s,int t) {
    int p[MAX_P];
    memset(p,0,sizeof(p));
    int id=0;
    while (t>0) {
        p[id++]=t%2;
        t/=2;
    }
    for (int i=0;id>i;i++) {
        //cout<<"S = "<<s<<endl;
        if (p[i]) {
            s = lca[i][s];
        }
    }
    return s;
}

int main () {
    int n;
    while (scanf("%d",&n) != EOF) {
        for (int x=0;n>=x;x++) {
            edg[x].clear();
            d[x].clear();
        }
        lca[0][0]=0;
        memset(depth,-1,sizeof(depth));
        for (int x=1;n>=x;x++) {
            int i;
            scanf("%d",&i);
            lca[0][x]=i;
            edg[i].push_back(x);
        }
        dfs(0,0);
        for (int i=1;MAX_P>i;i++) {
            for (int j=1;n>=j;j++) {
                lca[i][j] = lca[i-1][lca[i-1][j]];
            }
        }
        int q;
        scanf("%d",&q);
        for (int qq=0;q>qq;qq++) {
            int v,p;
            scanf("%d %d",&v,&p);
            int ret=go(v,p);
            if (!ret) {
                ans[qq] = 0;
                continue;
            }
            int cnt=0;
            int cur=depth[v];
            //right side
            int L=iden[v],R=d[cur].size();
            while (R-L != 1) {
                int mid=(L+R)>>1;
                if (go(d[cur][mid],p) == ret) L=mid;
                else R=mid;
            }
            cnt += (L - iden[v]);
            //left side
            L=-1,R=iden[v];
            while (R-L != 1) {
                int mid=(L+R)>>1;
                if (go(d[cur][mid],p) == ret) R=mid;
                else L=mid;
            }
            cnt += (iden[v] - R);
            ans[qq] = cnt;
        }
        for (int x=0;q>x;x++) {
            if (x) printf(" ");
            printf("%d",ans[x]);
        }
        puts("");
    }
}