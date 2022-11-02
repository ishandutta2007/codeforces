#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000010];
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            if(sum<0){
                sort(a+1,a+n+1);
            }
            else sort(a+1,a+n+1,greater<int>());
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
}