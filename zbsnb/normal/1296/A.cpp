#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int f1=0,f2=0;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            if(tmp%2)f1=1;
            else f2=1;
        }
        if(n%2&&f2==0){
            cout<<"YES"<<endl;
            continue;
        }
        if(f2==0||f1==0)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}