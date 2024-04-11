#include<bits/stdc++.h>
using namespace std;
char s[233];
long long ans=0,n;
int main(){
    cin>>n;
    cin>>s;
    for (int i=0;i<n;i++){
        if (s[i]=='B'){
            ans+=(long long)1<<i;
        }
    }
    cout<<ans;
}