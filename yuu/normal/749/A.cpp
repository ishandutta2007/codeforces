#include <iostream>
using namespace std;
int n;
int main(){
    cin>>n;
    if(n==2){
        cout<<"1\n2";
    }
    else if(n==3){
        cout<<"1\n3";
    }
    else{
        if(n%2==0){
            cout<<n/2<<'\n';
            for(int i=1; i<=n/2; i++)
                cout<<"2 ";
        }
        else{
            n-=3;
            cout<<n/2+1<<'\n';
            for(int i=1; i<=n/2; i++)
                cout<<"2 ";
            cout<<"3";

        }
    }
}