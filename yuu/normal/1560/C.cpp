#include <bits/stdc++.h>
using namespace std;

void solve(){
    int k;
    cin>>k;
    int r=sqrt(k);
    r--;
    while((r+1)*(r+1)<k) r++;
    k-=r*r;
    int row = min(k, r+1);
    k-=r+1;
    if(k<=0) k=0;
    int col = r+1-k;
    cout<<row<<' '<<col<<'\n';
}
int main(){
    int t=1;
    cin>>t;
    while(t--) solve();
}