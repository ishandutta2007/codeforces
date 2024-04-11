#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using ld=long double;
int a, b, n;
#define taskname "A"
void solve(){
    cin>>a>>b>>n;
    ///a, b, a^b, a, b, a^b
    if(n%3==0) cout<<a<<'\n';
    else if(n%3==1) cout<<b<<'\n';
    else cout<<(a^b)<<'\n';
}
int main(){
    #ifdef Aria
        freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    cin>>t;
    while(t--) solve();
}