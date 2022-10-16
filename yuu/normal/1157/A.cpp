#include <bits/stdc++.h>
using namespace std;
int n;
int main(){
    int ans=9;
    cin>>n;
    while(n>=10){
        ans++;
        n++;
        while(n%10==0) n/=10;
    }
    cout<<ans;
}