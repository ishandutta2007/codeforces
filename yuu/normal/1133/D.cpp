#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int b[200001];
pair <int, int> f(int a, int b){
    if(b<0){
        b=-b;
        a=-a;
    }
    else if(b==0) a=1;
    int d=__gcd(abs(a), b);
    a/=d;
    b/=d;
    return make_pair(a, b);
}
map <pair<int, int>, int> cnt;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];
    int z=0;
    for(int i=1; i<=n; i++) if(a[i]) cnt[f(a[i], b[i])]++; else if(b[i]==0) z++;
    int ans=0;
    for(auto x: cnt) ans=max(ans, x.second);
    cout<<ans+z;
}