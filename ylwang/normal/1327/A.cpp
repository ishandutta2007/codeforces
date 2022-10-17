#include<bits/stdc++.h>
using namespace std;

long long t,n,k;

int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--){
        cin>>n>>k;
        if(n%2==0&&k%2==1)cout<<"NO"<<endl;
        else if(n%2==1&&k%2==0)cout<<"NO"<<endl;
        else if(n<k*k)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}