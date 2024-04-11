#include<iostream>
using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int x,y,a,b;cin>>x>>y>>a>>b;
        if((y-x)%(a+b)==0){
            cout<<(y-x)/(a+b)<<endl;
        }
        else cout<<"-1"<<endl;
    }
}