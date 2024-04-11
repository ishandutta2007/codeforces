#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;cin>>a>>b>>c;
        if((a+b+c)%9==0&&min(a,min(b,c))>=(a+b+c)/9){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}