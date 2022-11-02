#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long 
int main(){
    int t;cin>>t;
    while(t--){
        ll x,y;cin>>x>>y;
        cout<<(x>y+1?"Yes":"No")<<endl;
    }
}