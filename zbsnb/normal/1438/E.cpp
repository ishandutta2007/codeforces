#include<bits/stdc++.h>
using namespace std;
#define LL long long
int a[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        LL sum=a[i+1];
        for(int j=i+2;j<=n;j++){
            if(a[i]>a[j]&&(a[i]^a[j])==sum) ans++;
            sum+=a[j];
            if(sum>=2*a[i]) break;
        }
    }
    for(int i=n;i>=1;i--){
        LL sum=a[i-1];
        for(int j=i-2;j>=1;j--){
            if(a[i]>a[j]&&(a[i]^a[j])==sum) ans++;
            sum+=a[j];
            if(sum>=2*a[i]) break;
        }
    }
    cout<<ans<<endl;
}