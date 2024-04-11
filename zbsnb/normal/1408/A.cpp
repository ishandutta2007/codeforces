#include<bits/stdc++.h>
using namespace std;
int a[3][110];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++) cin>>a[0][i];
        for(int i=1;i<=n;i++) cin>>a[1][i];
        for(int i=1;i<=n;i++) cin>>a[2][i];
        cout<<a[0][1]<<" ";
        int pre=a[0][1];
        for(int i=2;i<=n-1;i++){
            for(int j=0;j<3;j++){
                if(a[j][i]!=pre){
                    cout<<a[j][i]<<" ";
                    pre=a[j][i];
                    break;
                }
            }
        }
        for(int j=0;j<3;j++){
            if(a[j][n]!=pre&&a[j][n]!=a[0][1]){
                cout<<a[j][n]<<" ";
                break;
            }
        }
        cout<<endl;
    }
}