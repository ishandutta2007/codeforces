#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        int cnt=2*k-1-n;
        for(int i=1;i<=cnt;i++){
            cout<<i<<" ";
        }
        for(int i=k;i>cnt;i--){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}