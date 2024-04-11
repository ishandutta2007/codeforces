#include <bits/stdc++.h>
using namespace std;
int n;
int a[101];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    int ans=0;
    for(int i=3; i<=n; i++) if((a[i]==1)&&(a[i-1]==0)&&(a[i-2]==1)){
        ans++;
        a[i]=0;
    }
    cout<<ans;
}