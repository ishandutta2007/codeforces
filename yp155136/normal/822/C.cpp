#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 2e5 + 6;

vector<pii> v[MAX_N];
vector<pii> vv;

struct Kirino {
    int l,r,c,id;
    void input(int _id) {
        id=_id;
        scanf("%d %d %d",&l,&r,&c);
        v[r].push_back(make_pair(c,r-l+1));
        vv.push_back(make_pair(l,id));
    }
} kirino[MAX_N];

const int INF = 2134567890;

int best[MAX_N];

int main () {
    int n,x;
    scanf("%d %d",&n,&x);
    for (int i=1;n>=i;i++) {
        kirino[i].input(i);
    }
    sort(vv.begin(),vv.end());
    int m=200000;
    int ans=INF;
    int id=0;
    fill(best,best+MAX_N,INF);
    for (int i=1;m>=i;i++) {
        while (id<vv.size() && vv[id].first == i) {
            int j=vv[id].second;
            int need=kirino[j].r-kirino[j].l+1;
            need=x-need;
            if(need>0) {
                if (best[need] != INF) ans = min(ans,kirino[j].c + best[need]);
            }
            id++;
        }
        for(pii p:v[i]) {
            best[p.second] = min(best[p.second],p.first);
        }
    }
    if (ans==INF) puts("-1");
    else printf("%d\n",ans);
}