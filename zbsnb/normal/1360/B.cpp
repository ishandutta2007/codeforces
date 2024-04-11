#include<bits/stdc++.h>
using namespace std;
#define ll long long

int a[1000010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+n+1);
        int minn=1e9;
        for(int i=2;i<=n;i++){
            minn=min(minn,a[i]-a[i-1]);
        }
        cout<<minn<<endl;
    }
}