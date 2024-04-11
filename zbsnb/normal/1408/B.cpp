#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,x;cin>>n>>x;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=n;i>=1;i--){
            a[i]-=a[i-1];
        }
        int cnt=0;
        for(int i=2;i<=n;i++){
            if(a[i]) cnt++;
        }
        // cout<<"??"<<cnt<<endl;
        if(cnt==0){
            cout<<1<<endl;
            continue;
        }
        if(x==1){
            if(cnt) cout<<-1<<endl;
            else cout<<1<<endl;
        }
        else{
            cout<<(cnt<=0?cnt/(x-1):(cnt-1)/(x-1)+1)<<endl;
        }
    }
}