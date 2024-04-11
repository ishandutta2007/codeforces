#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int flg=1;
        for(int i=0;i<=n/3;i++){
        for(int j=0;j<=n/5;j++){
        for(int k=0;k<=n/7;k++){
            if(i*3+j*5+k*7==n){
                cout<<i<<" "<<j<<" "<<k<<endl;
                flg=0;
                break;
            }
        }
        if(!flg) break;
        }
        if(!flg) break;
        }
        if(flg) cout<<-1<<endl;
    }
}