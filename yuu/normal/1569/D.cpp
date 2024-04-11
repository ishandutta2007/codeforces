#include <bits/stdc++.h>
using namespace std;
int n, m, k;
int x[200001];
int y[200001];
map <int, int> mx;
map <int, int> my;
map <pair <int, int>, int> mxmy;
map <pair <int, int>, int> mymx;
void solve(){
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++) cin>>x[i];
    for(int i=1; i<=m; i++) cin>>y[i];
    mx.clear();
    my.clear();
    mxmy.clear();
    mymx.clear();
    int64_t ans=0;
    for(int i=1, a, b; i<=k; i++){
        cin>>a>>b;
        int px=lower_bound(x+1, x+n+1, a)-x;
        int py=lower_bound(y+1, y+m+1, b)-y;
        if(a==x[px]){
            if(b==y[py]) continue;
            ans+=my[py];
            ans-=mymx[{py, px}];
            my[py]++;
            mymx[{py, px}]++;
        }
        else{
            ans+=mx[px];
            ans-=mxmy[{px, py}];
            mx[px]++;
            mxmy[{px, py}]++;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}