#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int flg=1;
        for(int i=2;i<=n;i++){
            if(a[i]>=a[i-1]){
                flg=0;
                break;
            }
        }
        cout<<(flg?"NO":"YES")<<endl;
    }
}