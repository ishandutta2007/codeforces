#include<bits/stdc++.h>
using namespace std;
#define ll long long

char mp[55][55];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m,a,b;cin>>n>>m>>a>>b;
        if(n*a==m*b){
            cout<<"YES"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)mp[i][j]='0';
            }
            int pad=0;
            for(int i=0;i<n*a;i++){
                int x=(i+pad)%n;
                int y=i%m;
                while(mp[x][y]=='1'){
                    pad++;
                    x=(i+pad)%n;
                    y=i%m;
                }
                mp[x][y]='1';
            }
             for(int i=0;i<n;i++){
                for(int j=0;j<m;j++)cout<<mp[i][j];
                cout<<endl;
            }
        }
        else cout<<"NO"<<endl;
    }
}