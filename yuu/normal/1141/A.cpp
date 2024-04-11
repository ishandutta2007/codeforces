#include <bits/stdc++.h>
using namespace std;
int n, m;
int main(){
    cin>>n>>m;
    if(m%n){
        cout<<-1;
        return 0;
    }
    m/=n;
    int ans=0;
    while(m%2==0){
        m/=2;
        ans++;
    }
    while(m%3==0){
        m/=3;
        ans++;
    }
    if(m>1){
        cout<<-1;
        return 0;
    }
    cout<<ans;
}