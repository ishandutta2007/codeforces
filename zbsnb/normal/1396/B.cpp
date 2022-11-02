#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int ans=0;int maxn=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            ans+=a[i];
            maxn=max(maxn,a[i]);
        }
        if(n==1){
            cout<<"T"<<endl;
        }
        else if(n==2){
            cout<<(a[1]==a[2]?"HL":"T")<<endl;
        }
        else cout<<(ans%2?"T":(maxn*2>ans?"T":"HL"))<<endl;
    }
}