#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int cnt[200001];
int f[200001];
deque <int> ans;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    f[200000]=cnt[200000];
    int best=200000;
    for(int i=199999; i>=1; i--) if(cnt[i]){
        if(cnt[i+1]>=2) f[i]=f[i+1]+cnt[i];
        else f[i]=cnt[i]+cnt[i+1];
        if(f[i]>f[best]) best=i;
    }
    cout<<f[best]<<'\n';
    for(int i=1; i<=cnt[best]; i++) ans.push_back(best);
    for(int i=best+1; i<=200000; i++){
        if(cnt[i]==0) break;
        ans.push_front(i);
        if(cnt[i]==1) break;
        else for(int j=1; j<cnt[i]; j++) ans.push_back(i);
    }
    for(int x: ans) cout<<x<<' ';
}