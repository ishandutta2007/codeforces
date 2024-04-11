#include<bits/stdc++.h>
using namespace std;
int cnt[7],n,x,ans=0;
int main(){
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        for (int j=0;j<7;j++){
            scanf("%1d",&x);
            ans=max(ans,cnt[j]+=x);
        }
    }
    cout<<ans;
}