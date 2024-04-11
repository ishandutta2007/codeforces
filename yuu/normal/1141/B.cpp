#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int ans=0;
int main(){
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    int now=0;
    for(int i=0; i<n*2; i++){
        now=a[i%n]?(now+1):0;
        ans=max(ans, now);
    }
    ans=min(ans, n);
    cout<<ans<<'\n';
}