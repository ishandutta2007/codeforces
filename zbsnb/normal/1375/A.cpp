#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            cout<<(i&1?abs(tmp):-abs(tmp))<<" ";
        }
        cout<<endl;
    }
}