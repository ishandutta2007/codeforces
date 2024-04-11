#include <bits/stdc++.h>
using namespace std;
int n;
map <int, int> m;
vector <int> v;
int f[20];
int main(){
    cin>>n;
    for(int i=1, a; i<=n; i++){
        cin>>a;
        m[a]++;
    }
    for(auto x: m) v.push_back(x.second);
    sort(v.begin(), v.end());
    for(auto &x: v){
        for(int i=19; i>0; i--) f[i]=max(f[i], min(f[i-1], x>>i));
        f[0]=max(f[0], x);
    }
    long long ans=0;
    for(int i=0; i<20; i++){
        ans=max(ans, (((long long)(f[i]))<<(i+1))-f[i]);
        //cout<<f[i]<<" \n"[i+1==20];
    }
    cout<<ans<<'\n';
}