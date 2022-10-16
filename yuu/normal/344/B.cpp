#include <bits/stdc++.h>
using namespace std;
int main(){
    int a, b, c;
    cin>>a>>b>>c;
    if((c-(a+b))%2) cout<<"Impossible\n";
    else{
        int i=(a+b-c)/2;
        if(i>a||i>b||i<0) cout<<"Impossible\n";
        else cout<<i<<' '<<b-i<<' '<<a-i<<'\n';
    }
}