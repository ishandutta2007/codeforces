#include <bits/stdc++.h>
using namespace std;
int n;
pair <int, int> seg[300001];
pair <int, int> intl[300002];
pair <int, int> intr[300002];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>seg[i].first>>seg[i].second;
    auto inte=[](pair <int, int> a, pair <int, int> b){
        return make_pair(max(a.first, b.first), min(a.second, b.second));
    };
    auto leng=[](pair <int, int> a){
        return max(0, a.second-a.first);  
    };
    intl[0].second=1e9;
    intr[n+1].second=1e9;
    for(int i=1; i<=n; i++) intl[i]=inte(seg[i], intl[i-1]);
    for(int i=n; i>=1; i--) intr[i]=inte(seg[i], intr[i+1]);
    int ans=0;
    for(int i=1; i<=n; i++) ans=max(ans, leng(inte(intl[i-1], intr[i+1])));
    cout<<ans;
}