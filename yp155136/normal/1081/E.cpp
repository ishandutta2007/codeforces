#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pii;
const int N = 200006;
vector<pii> v[N];
ll ans[N];
ll x[N];
ll pre[N];
vector<pii> seg[N];
vector<int> par[N];
#define SZ(x) ((int)(x).size())

int main () {
    for (ll i=1;i<N;++i) {
        for (ll j=i;j<N;j+=2) {
            if (i*j >= N) break;
            v[i*j].push_back(make_pair(i,j));
        }
    }
    int n;
    scanf("%d",&n);
    for (int i=2;i<=n;i+=2) {
        scanf("%lld",&x[i]);
        for (pii p:v[ x[i] ]) {
            if (p.second == p.first) continue;
            pii want = make_pair((p.second-p.first)/2,(p.second+p.first)/2);
            if (i == 2) {
                seg[i].push_back(want);
                par[i].push_back(-1);
            }
            else {
                int ptr=0;
                for (pii q:seg[ i-2 ]) {
                    if (q.second < want.first) {
                        seg[i].push_back(want);
                        par[i].push_back(ptr);
                        break;
                    }
                    ++ptr;
                }
            }
            //seg[i].push_back( (p.second-p.first)/2,(p.second+p.first)/2 );
        }
    }
    if (SZ(seg[n])) {
        puts("Yes");
        int now=0;
        for (int i=n;i>=2;i-=2) {
            pii p = seg[i][now];
            pre[i] = p.second*p.second;
            pre[i-1] = p.first*p.first;
            now = par[i][now];
        }
        for (int i=1;i<=n;++i) {
            printf("%lld%c",pre[i]-pre[i-1]," \n"[i==n]);
        }
    }
    else {
        puts("No");
    }
}