#include<bits/stdc++.h>

using namespace std;
int a[200003];
int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<2*n;i++){
        cin>>a[i];
    }
    sort(a,a+2*n);
    long long int ans1=(long long int)(a[n-1]-a[0])*(a[2*n-1]-a[n]);
    long long int ans2=1E18;
    for(int i=1;i<=n-1;i++)
        if(ans2>(a[i+n-1]-a[i])) ans2=a[i+n-1]-a[i];
    ans2*=(a[2*n-1]-a[0]);
    long long int ans=((ans2>ans1) ? ans1 : ans2);
    cout<<ans<<endl;
    
    
}