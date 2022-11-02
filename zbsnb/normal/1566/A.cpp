#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    while(n--) {
        int a,b;cin>>a>>b;
        if(a & 1) {
            cout<<(b/((a+1)/2))<<"\n";
        }
        else cout<<(b/(a/2+1))<<"\n";
    }
}