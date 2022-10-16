#include <bits/stdc++.h>
using namespace std;
int n, k;
int cnt[100];
int main(){
    cin>>n>>k;
    for(int i=1, a; i<=n; i++){
        cin>>a;
        cnt[a%k]++;
    }
    int ans=cnt[0]/2;
    for(int i=1; i<k-i; i++) ans+=min(cnt[i], cnt[k-i]);
    if(k%2==0) ans+=cnt[k/2]/2;
    cout<<ans*2;
}