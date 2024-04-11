#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    char c;
    cin>>n;
    long long ans=0;
    for(int i=1; i<=n; i++){
        cin>>c;
        if(c%2==0) ans+=i;
    }
    cout<<ans<<'\n';
}