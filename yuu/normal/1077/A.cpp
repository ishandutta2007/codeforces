#include <bits/stdc++.h>
using namespace std;
int main(){
    int t, a, b, k;
    cin>>t;
    while(t--){
        cin>>a>>b>>k;
        long long pos=((long long)(a-b))*(k/2);
        if(k%2) pos+=a;
        cout<<pos<<'\n';
    }
}