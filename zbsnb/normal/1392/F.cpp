#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;ll sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=2;i<=n;i++){
        sum+=a[i]-a[1];
    }
    // cout<<sum<<endl;
    for(int i=n;i>=1;i--){
        ll now=1ll*i*(i-1)/2;
        if(sum<=now){
            ll tmp=sqrt(2*sum+0.25)-0.5+1e-9;
            a[i]=a[1]+tmp;
            sum-=tmp;
        }
        else{
            ll h=i-1+(sum-now)/i;
            a[i]=a[1]+h;
            sum-=h;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}