#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int now=1;
        while(n>=now){
            n-=now;
            now++;
        }
        if(n==0) cout<<now-1<<endl;
        else if(n==now-1) cout<<now+1<<endl;
        else cout<<now<<endl;
    }
}