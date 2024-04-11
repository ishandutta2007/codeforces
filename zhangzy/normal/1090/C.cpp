#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
const int SZ=1000;
const int N=1e6;
int n,m,tot=0,tar[N+10];
struct data {
    int loc,va;
}a[N+10];
vector <int> vec[N+10];
vector <int> vc;
int vis[N+10],vp[N+10];
bool cmp(data p,data q) {
    return p.va<q.va;
}
void Solve1() {
    for (;;) {
        int vx=0,vy=0;
        for (int i=1;i<=n;i++) {
            if ((int)vec[i].size()>tar[i]) vx=i;
            if ((int)vec[i].size()<tar[i]) vy=i;
        }
        if (vx==0||vy==0) break;
        int cnt1=vec[vx].size(),cnt2=vec[vy].size();
        for (int i=0;i<(int)vec[vy].size();i++) vis[vec[vy][i]]=1;
        for (int i=0;i<(int)vec[vx].size();i++) vp[i]=0;
        for (int i=0;i<(int)vec[vx].size();i++)
            if (!vis[vec[vx][i]]) {
                vp[i]=1;
                vec[vy].push_back(vec[vx][i]);
                printf("%d %d %d\n",vx,vy,vec[vx][i]);
                cnt1--;
                cnt2++;
                if (cnt1==tar[vx]) break;
                if (cnt2==tar[vy]) break;
            }
        vc.clear();
        for (int i=0;i<(int)vec[vx].size();i++) if (!vp[i]) vc.push_back(vec[vx][i]);
        vec[vx]=vc;
        for (int i=0;i<(int)vec[vy].size();i++) vis[vec[vy][i]]=0;
    }
}
set <pair<int,int> > s;
void Solve2() {
    for (int i=1;i<=n;i++) s.insert(make_pair(vec[i].size(),i));
    while (1) {
        set <pair<int,int> >::iterator it1=s.begin(),it2=s.end();
        it2--;
        pair <int,int> pii1=*it1,pii2=*it2;
        if (pii2.first-pii1.first<=1) break;
        int kx=pii2.second,px=pii1.second;
        for (int i=0;i<(int)vec[px].size();i++) vis[vec[px][i]]=1;
        for (int i=vec[kx].size()-1;i>=0;i--)
            if (!vis[vec[kx][i]]) {
                printf("%d %d %d\n",kx,px,vec[kx][i]);
                vec[px].push_back(vec[kx][i]);
                for (int j=i;j<(int)vec[kx].size()-1;j++)
                    vec[kx][j]=vec[kx][j+1];
                vec[kx].pop_back();
                break;
            }
        for (int i=0;i<(int)vec[px].size();i++) vis[vec[px][i]]=0;
        s.erase(it1);
        s.erase(it2);
        s.insert(make_pair(vec[kx].size(),kx));
        s.insert(make_pair(vec[px].size(),px));
    }
}
int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) {
        int k;
        scanf("%d",&k);
        a[i].loc=i;
        a[i].va=k;
        for (int j=1;j<=k;j++) {
            int x;
            scanf("%d",&x);
            vec[i].push_back(x);
        }
        tot+=vec[i].size();
    }
    sort(a+1,a+n+1,cmp);
    for (int i=1;i<=n;i++) tar[i]=tot/n;
    for (int i=1;i<=tot%n;i++) tar[a[n+1-i].loc]++;
    int ans=0;
    for (int i=1;i<=n;i++)
        if ((int)vec[i].size()>tar[i]) ans+=vec[i].size()-tar[i];
    printf("%d\n",ans);
    if (n<=SZ) Solve1();
    else Solve2();
    return 0;
}