#include<bits/stdc++.h>
using namespace std;
int mp[500][500];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        int flg=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin>>mp[i][j];
                int cnt=4;
                if(i==1||i==n)cnt--;
                if(j==1||j==m)cnt--;
                if(cnt<mp[i][j]){
                    flg=1;
                }
                mp[i][j]=cnt;
            }
        }
        if(flg){
            cout<<"NO"<<endl;
        }
        else {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout<<mp[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
}