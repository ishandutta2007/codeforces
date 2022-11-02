#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int t;cin>>t;
    while(t--){
        int n,x,y;cin>>n>>x>>y;
        for(int i=1;i<=50;i++){
            if((y-x)%i==0&&(y-x)/i<=n-1){
                // cout<<i<<endl;
                int cnt=0;
                for(int j=x;j<=y;j+=i){
                    cout<<j<<" ";
                    cnt++;
                }
                for(int j=x-i;j>=1;j-=i){
                    if(cnt>=n)break;
                    cout<<j<<" ";
                    cnt++;
                }
                for(int j=y+i;;j+=i){
                    if(cnt>=n)break;
                    cout<<j<<" ";
                    cnt++;
                }
                cout<<endl;
                break;
            }
        }
    }
}