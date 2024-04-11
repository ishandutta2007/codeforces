#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int n;cin>>n;
    set<ll> s;ll sum=0;int ans=0;
    s.insert(0);
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        sum+=tmp;
        if(s.count(sum)){
            ans++;
            s.clear();
            s.insert(0);
            sum=tmp;
        }
        s.insert(sum);
        // cout<<i<<" "<<sum<<endl;
    }
    cout<<ans<<endl;
}