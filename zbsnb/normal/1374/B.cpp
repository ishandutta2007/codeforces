#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt1=0,cnt2=0;
        while(n%2==0){
            cnt1++;
            n/=2;
        }
        while(n%3==0){
            cnt2++;
            n/=3;
        }
        if(n!=1||cnt2<cnt1)cout<<-1<<endl;
        else{
            cout<<(2*cnt2-cnt1)<<endl;
        }
    }
}