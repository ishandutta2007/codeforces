#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
const int MAX_N = 1e5 + 6;
const LL mod = 1e9 + 7;

pii p[MAX_N];
bool visit[MAX_N];
bool visitx[MAX_N],visity[MAX_N];

#define F first
#define S second

vector<int> vx[MAX_N],vy[MAX_N];

int tot=0;
int tot_xy = 0;

LL ppow(LL a,LL n) {
    if (n==0) return 1;
    else if (a==1) return n;
    LL ret=ppow(a,n/2);
    ret*=ret;
    ret%=mod;
    if (n&1) ret*=a;
    return ret%mod;
}

map<pii,int> mp;

void dfs(pii p) {
    //cout<<"p = "<<p.F<<","<<p.S<<endl;
    visit[ mp[p] ] = 1;
    tot++;
    if (!visitx[p.F]) {
        tot_xy++;
        visitx[p.F]=1;
        for (int i:vx[p.F]) {
            if (!visit[mp[make_pair(p.F,i)] ]) {
                dfs({p.F,i});
            }
        }
    }
    if (!visity[p.S]) {
        tot_xy++;
        visity[p.S]=1;
        for (int i:vy[p.S]) {
            if (!visit[mp[make_pair(i,p.S)] ]) {
                dfs({i,p.S});
            }
        }
    }
}

int main () {
    int n;
    scanf("%d",&n);
    vector<int> v1,v2;
    for (int i=1;n>=i;i++) {
        scanf("%d %d",&p[i].F,&p[i].S);
        v1.push_back(p[i].F);
        v2.push_back(p[i].S);
    }
    sort(v1.begin(),v1.end());
    v1.resize(unique(v1.begin(),v1.end()) - v1.begin());
    sort(v2.begin(),v2.end());
    v2.resize(unique(v2.begin(),v2.end()) - v2.begin());
    for (int i=1;n>=i;i++) {
        p[i].F = lower_bound(v1.begin(),v1.end(),p[i].F)-v1.begin()+1;
        p[i].S = lower_bound(v2.begin(),v2.end(),p[i].S)-v2.begin()+1;
        mp[p[i]] = i;
        vx[p[i].F].push_back(p[i].S);
        vy[p[i].S].push_back(p[i].F);
    }
    LL ans=1;
    for (int i=1;n>=i;i++) {
        if (!visit[i]) {
            tot=0;
            tot_xy=0;
            dfs(p[i]);
            if (tot_xy > tot) {
                ans *= (ppow(2,tot_xy)-1+mod)%mod;
            }
            else {
                ans *= (ppow(2,tot_xy));
            }
        }
        ans %= mod;
    }
    printf("%lld\n",ans);
}