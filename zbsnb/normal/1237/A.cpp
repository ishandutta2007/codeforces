#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;



int main(){
    int t;cin>>t;
    int flg=0;
    while(t--){
        int n;cin>>n;
        if(n%2==0)cout<<n/2<<endl;
        else{
            if(flg)cout<<(n+1)/2<<endl,flg=0;
            else cout<<(n-1)/2<<endl,flg=1;
        }
    }
}