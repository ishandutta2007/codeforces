#include<bits/stdc++.h>
using namespace std;
#define ll long long

char mp[55][55];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>mp[i]+1;
        }
        int flg=0;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++){
                if(mp[i][j]=='1'&&(mp[i+1][j]=='0'&&mp[i][j+1]=='0')){
                    flg=1;
                    break;
                }
            }
        }
        cout<<(flg?"NO":"YES")<<endl;
    }
}