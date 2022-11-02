#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        if(n==2){
            cout<<2<<endl;
            cout<<1<<" "<<2<<endl;
            continue;
        }
        cout<<2<<endl;
        cout<<n<<" "<<n-1<<endl;
        cout<<n<<" "<<n-2<<endl;
        for(int i=n-1;i>=3;i--){
            cout<<i<<" "<<i-2<<endl;
        }
    }
}