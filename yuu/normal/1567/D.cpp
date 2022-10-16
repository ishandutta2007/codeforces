#include <bits/stdc++.h>
using namespace std;
int s, n;
int p10[11];
void solve(){
    cin>>s>>n;
    deque <int> a;
    a.push_back(s);
    while(a.size()<n){
        bool found=0;
        int best=-1;
        for(int i=0; i<a.size(); i++){
            for(int j=0; a[i]>p10[j]; j++) if((a[i]/p10[j])%10>=1){
                // split able here
                // cerr<<a[i]<<' '<<p10[j]<<'\n';
                a[i]-=p10[j];
                a.push_back(p10[j]);
                found=1;
                break;
            }
            if(found) break;
            if(a[i]>1) if((best==-1)||(a[i]<a[best])) best=i;
        }
        if(!found){
            // cerr<<a[best]<<'\n';
            a[best]/=10;
            a.push_front(a[best]*9);
        }
    }
    for(auto&&x: a) cout<<x<<' ';
    cout<<'\n';

}
int main(){
    p10[0]=1;
    for(int i=1; i<10; i++) p10[i]=p10[i-1]*10;
    p10[10]=2e9;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--) solve();
}