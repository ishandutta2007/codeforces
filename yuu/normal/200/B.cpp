#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    double a=0;
    cin>>n;
    for(int i=0, p; i<n; i++){
        cin>>p;
        a+=p;
    }
    a/=n;
    cout<<setprecision(16)<<fixed<<a<<'\n';
}