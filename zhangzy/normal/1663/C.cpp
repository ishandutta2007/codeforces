#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, a[10100];

int main(){
    cin>>n;
    // assert(n<=2);
    for (int i=1;i<=n;++i) cin>>a[i];
    // cout<<(*max_element(a+1,a+n+1))<<endl;
    if (n==1){
        cout<<a[1]<<endl;
    }else if (n==2){
        cout<<a[1]+a[2]<<endl;
    }else{
        // assert(0);
        int sum=0;
        for (int i=1;i<=n;++i) sum+=a[i];
        cout<<sum<<endl;
    }
    // int ans=0; a[0]=a[n+1]=1e9;
    // for (int i=1;i<=n;++i) ans+=a[i]<a[i-1]&&a[i]<a[i+1];
    // cout<<ans<<endl;
}