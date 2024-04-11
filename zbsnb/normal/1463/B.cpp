#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            cout<<(1<<(31-__builtin_clz(tmp)))<<" \n"[i==n];
        }
    }
}