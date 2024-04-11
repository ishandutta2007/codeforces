#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
#define ll long long
int a[100010];
map<int,int> f1,f2;
int main(){
    int n,m;cin>>n>>m;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=m;i>=1;i--){
        f1[a[i]+i]=f1[a[i]+i+1]+1;
        f2[a[i]-i]=f2[a[i]-i-1]+1;
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        ans+=max(0,min(n-i,m+1-f2[i]))
            +max(0,min(i-1,m+1-f1[i]))+1;
    }
    cout<<ans<<endl;
}