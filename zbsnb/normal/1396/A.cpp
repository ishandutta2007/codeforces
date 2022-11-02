#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==1){
        cout<<"1 1"<<endl;
        cout<<a[1]<<endl;
        cout<<"1 1"<<endl;
        cout<<(-a[1])<<endl;
        cout<<"1 1"<<endl;
        cout<<(-a[1])<<endl;
        return 0;
    }
    cout<<1<<" "<<n<<endl;
    for(int i=1;i<=n-1;i++){
        cout<<(-1ll*a[i]*n)<<" ";
    }
    cout<<0<<" "<<endl;
    cout<<1<<" "<<n-1<<endl;
    for(int i=1;i<=n-1;i++){
        cout<<(1ll*a[i]*(n-1))<<" ";
    }
    cout<<endl;
    cout<<n<<" "<<n<<endl;
    cout<<(-a[n])<<endl;
}