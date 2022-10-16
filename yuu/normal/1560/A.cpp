#include <bits/stdc++.h>
using namespace std;
bool nice(int x){
    if((x%3==0)||(x%10==3)) return false;
    return true;
}
int ans[1001];
void solve(){
    int k;
    cin>>k;
    cout<<ans[k]<<'\n';
}
int main(){
    for(int i=1; i<=1000; i++){
        ans[i]=ans[i-1]+1;
        while(!nice(ans[i])) ans[i]++;
    }
    int t=1;
    cin>>t;
    while(t--) solve();
}