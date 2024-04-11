#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=0;i<32;i++) a[i]=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            a[__builtin_clz(tmp)]++;            
        }
        ll ans=-n;
        for(int i=0;i<32;i++){
            ans+=1ll*a[i]*a[i];
        }
        cout<<ans/2<<endl;
    }
}