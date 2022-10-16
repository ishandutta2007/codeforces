#include <bits/stdc++.h>
using namespace std;
int main(){
    long long a, b;
    cin>>a>>b;
    int ans=0;
    while(a<=b){
        ans++;
        a*=3;
        b*=2;
    }
    cout<<ans<<'\n';
}