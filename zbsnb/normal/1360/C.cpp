#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1000010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int cnt1=0,cnt2=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            a[i]&1?cnt1++:cnt2++;
        }
        sort(a+1,a+n+1);
        if(cnt1%2==0)cout<<"YES"<<endl;
        else{
            int flg=0;
            for(int i=2;i<=n;i++){
                if(a[i]-a[i-1]==1){
                    flg=1;
                    break;
                }
            }
            cout<<(flg?"YES":"NO")<<endl;
        }
    }
}