#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>a[i];
    sort(a+1, a+n+1);
    int ans=0;
    for(int i=1, j=1; i<=n; i++){
        while((j<n)&&(a[j+1]-a[i]<=5)) j++;
        ans=max(ans, j-i+1);
    }
    cout<<ans;
}