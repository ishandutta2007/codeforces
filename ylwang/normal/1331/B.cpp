#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    for(int i=2; i*i<=n; ++i)       // 2 
        if(n%i==0){
            cout<<i<<n/i<<endl;     //
            return 0;
        }
    return 0;
}