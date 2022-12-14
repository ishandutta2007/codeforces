#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n,q,xi,yi,ans;
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        cin>>xi>>yi;
        if((xi+yi)%2==0){
            ans=(n*((xi-1)/2)+((xi-1)%2)*((n+1)/2))+((yi+1)/2);
        }
        else{
            ans=(n*n+1)/2+(n*((xi-1)/2)+((xi-1)%2)*(n/2))+((yi+1)/2);
        }
        cout<<ans<<endl;
    }
}